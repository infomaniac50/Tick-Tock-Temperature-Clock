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
#include "thermometer.h"

#include <Adafruit_MCP9808.h>
#include <LiquidCrystal.h>

extern LiquidCrystal lcd;

Adafruit_MCP9808 sensor;
struct temp_t temperature;

void Thermometer::boot(void) {
	if (!sensor.begin())
	{
		Runtime::error(F("No Temperature!"));
		Runtime::halt();
	}
}

void Thermometer::update() {
    temperature.celsius = sensor.readTempC();
	temperature.fahrenheit = temperature.celsius * 9.0 / 5.0 + 32;
}

void Thermometer::printTitle() {
	lcd.print(F("Temperature"));
}

void Thermometer::printTemperature()
{
	lcd.clear();
	lcd.setCursor(0, 0);
	printTitle();
	
	lcd.setCursor(0, 1);
	printFahrenheit();
}

void Thermometer::printFahrenheit(void) {
	lcd.print(temperature.fahrenheit, 2);
	// print the custom char to the lcd
	lcd.write((uint8_t)0);
	lcd.print('F');
	// why typecast? see: http://arduino.cc/forum/index.php?topic=74666.0
}