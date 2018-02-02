//Eric Lin

void measure_green(int mot_power, int time, int & green, int & notGreen)
{
	int ENC_LIMIT = 360/(2*PI*2.75);
	clearTimer(T4);
	motor[motorA] = motor[motorC] = mot_power;
	while (time1[T4]/1000 < time)
	{
		nMotorEncoder[motorA] = 0;
		while (nMotorEncoder[motorA] < ENC_LIMIT)
		{}
		if (SensorValue[S2] == 3)
				green++;
		else
			notGreen++;
	}
	motor[motorA] = motor[motorC] = 0;
}

task main()
{
	SensorType[S3] = sensorEV3_Touch;
	SensorType[S2] = sensorEV3_Color;
	wait1Msec(50);
	SensorMode[S2] = modeEV3Color_Color;
	wait1Msec(50);

	int green = 0, notGreen = 0;
	displayString(0, "Group 16, Section: Tue Late");

	while (SensorValue[S3] == 0)
	{}
	while (SensorValue[S3] != 0)
	{}

	bool downPress = false;

	while (downPress == false)
	{

		while (!getButtonPress(buttonAny))
		{}
		if (getButtonPress(buttonLeft))
		{
			while (getButtonPress(buttonAny))
			{}
			measure_green(75, 2, green, notGreen);

			displayString(1, "Green: %d Not Green: %d",green,notGreen);
		}
		else if (getButtonPress(buttonRight))
		{
			while (getButtonPress(buttonAny))
			{}
			measure_green(50, 3, green, notGreen);

			displayString(1, "Green: %d Not Green: %d",green,notGreen);
		}
		else if (getButtonPress(buttonEnter))
		{
			while (getButtonPress(buttonAny))
			{}
			measure_green(25, 4, green, notGreen);

			displayString(1, "Green: %d Not Green: %d",green,notGreen);
		}
		else if (getButtonPress(buttonDown))
		{
			while (getButtonPress(buttonAny))
			{}
			downPress = true;
		}
	}
	motor[motorA] = motor[motorC] = 0;

}

/* Final Output
Green: 187 Not Green: 5

The reason the sensor detected no green on some instances even though it was
driving over green the entire time can likely be attributed to inaccuracies
with the sensor. One solution that may possibly work is retrieving the raw
RGB values detected by the sensor and setting a larger tolerance for what
is considered to be green, compared to checking using SensorValue[S2] == 3.

*/
