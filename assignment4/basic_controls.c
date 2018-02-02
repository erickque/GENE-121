//Juyeop Lee and Eric Lin

task main()
{
	displayString(0, "Tues late 18");

	for(int presses = 0; presses < 3; presses++)
	{
		while(!getButtonPress(buttonLeft) && !getButtonPress(buttonEnter) &&
		!getButtonPress(buttonRight))	//only if these three buttons are pressed
		{}

		if (getButtonPress(buttonLeft))
		{
			while (getButtonPress(buttonLeft))	//waits until the button is let go
			{}
			motor[motorA] = -75;
			motor[motorC] = 75;

			wait1Msec(400);

			motor[motorA] = 0;
			motor[motorC] = 0;

		}
		else if (getButtonPress(buttonRight))
		{
			while(getButtonPress(buttonRight))
			{}
			motor[motorA] = 75;
			motor[motorC] = -75;

			wait1Msec(400);

			motor[motorA] = 0;
			motor[motorC] = 0;
		}
		else if (getButtonPress(buttonEnter))
		{
			while(getButtonPress(buttonEnter))
			{}
			displayString(0, "Vamonos");
			motor[motorA] = 100;
			motor[motorC] = 100;

			wait1Msec(2000);

			motor[motorA] = 0;
			motor[motorC] = 0;
		}
	}
	wait1Msec(1000);

	SensorType[S3] = sensorEV3_Touch;

	motor[motorA] = 75;
	motor[motorC] = 25;

	while(SensorValue[S3] == 0)
	{}

	motor[motorA] = motor[motorC] = 0;
}
