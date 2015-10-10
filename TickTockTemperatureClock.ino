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

#include <SimpleTimer.h>
#include <LiquidCrystal.h>

#include <Time.h>
#include <Wire.h>
#include <DS1307RTC.h>  // a basic DS1307 library that returns time as a time_t
#include <Adafruit_MCP9808.h>

#include "runtime.h"
#include "clock.h"
#include "thermometer.h"

SimpleTimer timer;

void setup()
{
	Runtime::boot();
	
	timer.setInterval(UPDATETIME_INTERVAL, Clock::update);
	timer.setInterval(UPDATETEMP_INTERVAL, Thermometer::update);

	timer.setInterval(STEP_DURATION, Runtime::step);
	timer.setInterval(DISPLAY_INTERVAL, Runtime::print);
}

void loop()
{
	timer.run();
}
