// Copyright (C) 2015 Derek Chafin

// This program is free software: you can redistribute it and/or modify it
// under the terms of the GNU Affero General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at your
// option) any later version.

// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public
// License for more details.

// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

/*

  typedef struct  {
    uint8_t Second;
    uint8_t Minute;
    uint8_t Hour;
    uint8_t Wday;   // day of week, sunday is day 1
    uint8_t Day;
    uint8_t Month;
    uint8_t Year;   // offset from 1970;
  }   tmElements_t, TimeElements, *tmElementsPtr_t;

  The time and date functions can take an optional parameter for the time. This prevents
  errors if the time rolls over between elements. For example, if a new minute begins
  between getting the minute and second, the values will be inconsistent. Using the
  following functions eliminates this probglem
  int     hour(time_t t);    // the hour for the given time
  int     hourFormat12(time_t t); // the hour for the given time in 12 hour format
  uint8_t isAM(time_t t);    // returns true the given time is AM
  uint8_t isPM(time_t t);    // returns true the given time is PM
  int     minute(time_t t);  // the minute for the given time
  int     second(time_t t);  // the second for the given time
  int     day(time_t t);     // the day for the given time
  int     weekday(time_t t); // the weekday for the given time
  int     month(time_t t);   // the month for the given time
  int     year(time_t t);    // the year for the given time

  1.  Jan - January
  2.  Feb - February
  3.  Mar - March
  4.  Apr - April
  5.  May - May
  6.  Jun - June
  7.  Jul - July
  8.  Aug - August
  9.  Sep - September
  10. Oct - October
  11. Nov - November
  12. Dec - December

  SECS_PER_HOUR = (3600UL);
  def now():
    # get UTC time here

  # If the RTC is set to UTC
  def get_localtime():
    # time_t here is a 32bit integer
    time_t utc = now();
    localtime = utc + (TZ * SECS_PER_HOUR);
    if (IS_DST):
      localtime += SECS_PER_HOUR;

    return localtime;

  print get_localtime();
 */

#include <Arduino.h>
#include <Time.h>
#include <Wire.h>
#include <DS1307RTC.h>  // a basic DS1307 library that returns time as a time_t
#include <LiquidCrystal.h>

#include "clock.h"
#include "utils.h"

extern LiquidCrystal lcd;

struct TimeSettings {

	int TZ;
	bool IS_DST;	
};

time_t currentTime;
struct TimeSettings settings;

void Clock::set(time_t t) {
  if (t != 0) {
    RTC.set(t); // set the RTC
    setTime(t);
  }
}

void Clock::boot(void) {

	settings.TZ = -6;
	settings.IS_DST = true;

	setSyncProvider(RTC.get);   // the function to get the time from the RTC
	setSyncInterval(SECS_PER_MIN);
}

void Clock::update()
{
	if (timeStatus() == timeSet)
	{
		currentTime = now(); // store the current time in time variable t
	}
	else
	{
		// Saturday 1st January 2000 12:00:00 AM UTC
		currentTime = DEFAULT_TIME;
	}

	currentTime = getLocalTime(currentTime, settings.TZ, settings.IS_DST);
}

void Clock::printDate() {

	// May 22, 2015
	lcd.print(monthShortStr(month(currentTime)));
	lcd.print(' ');
	lcd.print(day(currentTime));
	lcd.print(", ");
	lcd.print(year(currentTime));
}

void Clock::printTime() {
	static boolean printColon = true;

	// 12:25 PM
	printLeadingCharacter(hourFormat12(currentTime), ' ');
	if (printColon)
		lcd.print(':');
	else
		lcd.print(' ');
	printColon = !printColon;
	printLeadingCharacter(minute(currentTime), '0');

	lcd.print(' ');
	if (isPM(currentTime))
	{
		lcd.print(F("PM"));
	}
	else
	{
		lcd.print(F("AM"));
	}
}

void Clock::printDateTime(void) {
	lcd.clear();
	lcd.setCursor(0, 0);

	printDate();
	// Start at beginning of second line
	lcd.setCursor(0, 1);

	printTime();
}
