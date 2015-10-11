## Tick Tock Temperature Clock

### Parts

 - [Arduino UNO](https://www.arduino.cc/en/Main/ArduinoBoardUno) or Compatible
 - [LinkSprite LCD Shield](https://www.sparkfun.com/products/13293) or Compatible
 - DS1307 Compatible RTC
     - [DS1307 Real Time Clock breakout board kit](https://www.adafruit.com/product/264) - From the current incarnation
 - [MCP9808 High Accuracy I2C Temperature Sensor Breakout Board](https://www.adafruit.com/products/1782)

### Setting the Time

```bash
# Print unix timestamp to shell
echo -n "T$(date +"%s")" # -> T1444522812
```
http://unixtimesta.mp/1444522812

Copy and paste this timestamp to the Arduino Serial console.