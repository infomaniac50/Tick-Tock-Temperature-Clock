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

#ifndef display_h
#define display_h
#include <avr/pgmspace.h>
#include <LiquidCrystal.h>
#define CHAR_HEIGHT 8

const PROGMEM unsigned char bitmap_degree[CHAR_HEIGHT] =
{
	0b01100,
	0b10010,
	0b10010,
	0b01100,
	0b00000,
	0b00000,
	0b00000,
	0b00000
};

class Display
{
public:
	static int brightness(void);
	static void blank(void);
	static void boot(void);
	static void brightness(int brightness);
	static void update(void);
};

#endif