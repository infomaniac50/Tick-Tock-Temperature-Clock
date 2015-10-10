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
#include <Arduino.h>
#include <LiquidCrystal.h>

#include "runtime.h"
#include "display.h"

#include "utils.h"

extern LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void Runtime::banner(void)
{
	lcd.clear();
	lcd.setCursor(0, 0);

	lcd.print(F("Birthday Clock"));
	lcd.setCursor(0, 1);
	lcd.print(F("by Derek Chafin"));
}

void Runtime::error(const __FlashStringHelper * string_literal)
{
	lcd.print(string_literal);
}

void Runtime::halt(void)
{
	while(1);
}

