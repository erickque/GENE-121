//Juyeop Lee and Eric Lin 

task main()
{
    SensorType[S3] = sensorEV3_Touch;
    SensorType[S2] = sensorEV3_Ultrasonic;

    const int ENC_LIMIT = 5900 * 360 / (2 * PI * 2.75);
    const int ENC_METER = 100 * 360 / (2 * PI * 2.75);
    int ducks = 0;

    for(int columns = 0; columns < 101; columns++)
    {
        nMotorEncoder[motorA] = 0;

        do {
            motor[motorA] = 75;
            motor[motorC] = 75;

            while (SensorValue[S3] == 0 && nMotorEncoder[motorA] < ENC_LIMIT)
            {}

            if (SensorType[S2]==255)
            {
                int encoderPause = nMotorEncoder[motorA];

                motor[motorA] = 0;
                motor[motorC] = 0;
                motor[motorD] = 25;
                wait1Msec(3000);

                motor[motorA] = 75;
                motor[motorC] = -75;
                wait1Msec(800);

                motor[motorA] = 0;
                motor[motorC] = 0;
                motor[motorD] = -15;
                wait1Msec(1000);

                motor[motorA] = 75;
                motor[motorC] = -75;
                wait1Msec(800);
                motor[motorA] = 0;
                motor[motorC] = 0;
                ducks++;
                nMotorEncoder[motorA] = 0;
                nMotorEncoder[motorA] += encoderPause;
            }
            
            else if (SensorType[S2]<255)
            {
                motor[motorA] = 0;
                motor[motorC] = 0;
                wait1Msec(3000);
            }
            
        } while(nMotorEncoder[motorA] < ENC_LIMIT);

        if (columns%2 == 0)
            motor[motorC] = -75;
        else
            motor[motorA] = -75;
        
        wait1Msec(400);

        nMotorEncoder[motorA] = 0;

        motor[motorA] = 75;
        motor[motorC] = 75;

        while(nMotorEncoder[motorA] < ENC_METER)  
        {}

        if (columns%2 == 0)
            motor[motorC] = -75;
        else
            motor[motorA] = -75;
        wait1Msec(400);

        motor[motorA] = 0;
        motor[motorC] = 0;
    }

    displayString(0, "You've caught %d ducks.", ducks);

}

/*
Assumptions:
- That the obstacle will move out of the way within 3 seconds.
- That all ducks are the same size and will give an ultrasonic reading of 255

Things that could go wrong:
- A duck gets away before it is successfully tagged, resulting in an
incorrect final duck count as duck++; proceeds anyway.
*/
