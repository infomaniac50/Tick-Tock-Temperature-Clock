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

#include "runtime.h"
#include "display.h"
#include <stdlib.h>
#include <Arduino.h>

extern LiquidCrystal lcd;

void Display::brightness(int brightness)
{
	analogWrite(BACKLIGHT_PWM_PIN, brightness);
}

void Display::boot(void)
{

	// create a new custom character
	unsigned char * customChar = (unsigned char *)malloc(CHAR_HEIGHT);

	if (customChar)
	{
		memcpy_P(customChar, bitmap_degree, CHAR_HEIGHT);
		lcd.createChar(0, customChar);
		free(customChar);
	}

	// set up number of columns and rows
	lcd.begin(LCD_COLS, LCD_ROWS);

}
