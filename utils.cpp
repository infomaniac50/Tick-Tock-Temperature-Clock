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
#include <Arduino.h>
#include <Time.h>
#include <LiquidCrystal.h>

#include "utils.h"

extern LiquidCrystal lcd;

void printLeadingCharacter(int number, char character)
{
	if (number < 10)
		lcd.print(character);
	lcd.print(number);
}

void printLeadingZero(int number)
{
	if(number < 10)
		lcd.print('0');
	lcd.print(number);
}

time_t getLocalTime(time_t utc, int TZ, boolean isDst)
{
	// time_t here is a 32bit integer
	time_t localTime = utc + (TZ * SECS_PER_HOUR);

	if (isDst)
	{
		localTime += SECS_PER_HOUR;
	}

	return localTime;
}
