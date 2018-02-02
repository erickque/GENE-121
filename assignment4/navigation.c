//Juyeop Lee and Eric Lin

task main()
{
	displayString(0, "Tues late 18");

	while (!getButtonPress(buttonEnter))
	{}
	while (getButtonPress(buttonEnter))
	{}

	clearTimer(T1);

	SensorType[S3] = sensorEV3_Touch;
	SensorType[S2] = sensorEV3_Ultrasonic;
	int stopValue = 0;

	int rightValue =0;
	int frontValue = 0;
	int leftValue = 0;

	while(SensorValue[S3] == 0 && stopValue == 0)
	{

		clearTimer(T2);

		while (time1[T2] <= 200 && SensorValue[S3] == 0 && stopValue == 0)
		{
			motor[motorA] = -75;
			motor[motorC] = 75;

			if (SensorValue[S3] == 1)
				stopValue = 1;
		}

		motor[motorA] = motor[motorC] = 0;

		if (stopValue == 0)
		{
			clearTimer(T3);
			while (time1[T3] < 500 && SensorValue[S3] == 0)
			{
				if (SensorValue[S3] == 1)
					stopValue = 1;
			}
			leftValue = SensorValue[S2];
		}

		clearTimer(T2);

		while (time1[T2] <= 200 && SensorValue[S3] == 0 && stopValue == 0)
		{
			motor[motorA] = 75;
			motor[motorC] = -75;

			if (SensorValue[S3] == 1)
				stopValue = 1;
		}

		motor[motorA] = motor[motorC] = 0;

		if (stopValue == 0)
		{
			clearTimer(T3);
			while (time1[T3] < 500 && SensorValue[S3] == 0)
			{
				if (SensorValue[S3] == 1)
					stopValue = 1;
			}
			frontValue = SensorValue[S2];
		}

		clearTimer(T2);

		while (time1[T2] <= 200 && SensorValue[S3] == 0 && stopValue == 0)
		{
			motor[motorA] = 75;
			motor[motorC] = -75;

			if (SensorValue[S3] == 1)
				stopValue = 1;
		}

		motor[motorA] = motor[motorC] = 0;

		if (stopValue == 0)
		{
			clearTimer(T3);
			while (time1[T3] < 500 && SensorValue[S3] == 0)
			{
				if (SensorValue[S3] == 1)
					stopValue = 1;
			}
			rightValue = SensorValue[S2];
		}

		if (leftValue > frontValue && leftValue > rightValue && stopValue == 0)
		{
			clearTimer(T2);
			while (time1[T2] <= 400 && SensorValue[S3] == 0 && stopValue == 0)
			{
				motor[motorA] = -75;
				motor[motorC] = 75;

				if (SensorValue[S3] == 1)
					stopValue = 1;
			}

			motor[motorA] = motor[motorC] = 0;
		}

		else if(frontValue > rightValue && frontValue > leftValue && stopValue == 0)
		{
			clearTimer(T2);
			while (time1[T2] <= 200 && SensorValue[S3] == 0 && stopValue == 0)
			{
				motor[motorA] = -75;
				motor[motorC] = 75;

				if (SensorValue[S3] == 1)
					stopValue = 1;
			}

			motor[motorA] = motor[motorC] = 0;
		}

		const int ENC_LIMIT = 40 * 360 / (2 * PI * 2.75);

		nMotorEncoder[motorA] = 0;

		if (stopValue == 0)
			motor[motorA] = motor[motorC] = 75;

		while(nMotorEncoder[motorA] < ENC_LIMIT && SensorValue[S3] == 0)
		{
			if (SensorValue[S3] == 1)
				stopValue = 1;
		}

		motor[motorA] = motor[motorC] = 0;

    }

	int recordTime = time1[T1] / 1000;	

	displayString(1, "%d seconds", recordTime);
	wait1Msec(5000);
}
