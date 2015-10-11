## Tick Tock Temperature Clock

### Parts

 - Arduino UNO or Compatible
 - LinkSprite LCD Shield or Compatible
 - DS1307 Compatible RTC
 - [MCP9808 High Accuracy I2C Temperature Sensor Breakout Board](https://www.adafruit.com/products/1782)

### Setting the Time

```bash
# Print unix timestamp to shell
echo -n "T$(date +"%s")" # -> T1444522812
```
http://unixtimesta.mp/1444522812

Copy and paste this timestamp to the Arduino Serial console.