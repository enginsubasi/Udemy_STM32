float pid ( float error )
{
    static float kp = 1;
    static float ki = 1;
    static float kd = 1;
    
    static float integral = 0;
    static float lastError = 0;
    
    float derivative = 0;
    float pidOutput = 0;
    
    integral += error;
    derivative = ( error - lastError );
    
    
    pidValue =  ( error * kp ) + 
                ( integral * ki ) + 
                ( derivative * kd );

    // To keep last value of error
    lastError = error;

    return ( pidValue );
}



