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
#ifndef runtime_h
#define runtime_h
#include <WString.h>
#define LCD_ROWS 2
#define LCD_COLS 16

#define DEFAULT_BRIGHTNESS 127
#define BACKLIGHT_PWM_PIN 10

#define UPDATETIME_INTERVAL 1000
#define UPDATETEMP_INTERVAL 1000

// 1/2 of one second gives a nice blinking colon on the clock.
// 500ms; 500ms; 500ms; 500ms
// 12:00; 12 00; 12:00; 12 00
#define DISPLAY_INTERVAL 500
#define STEP_DURATION 8000

class Runtime
{
private:
public:
	static void step(void);
	static void print(void);
	static void boot(void);
	static void banner(void);
	static void error(const __FlashStringHelper * string_literal);
	static void halt(void);
};

#endif