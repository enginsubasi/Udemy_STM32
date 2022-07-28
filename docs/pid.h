#ifndef PID_H_
#define PID_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdint.h>

/* FUNCTION DEFINITIONS */

/* DEFINITIONS */

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

/* TYPEDEFS */

/* STRUCTURES */

typedef struct
{
    float error;
    float lastError;

    float output;

    float kp;
    float ki;
    float kd;

    float ts;

    float iMax;
    float iMin;
    
    float dMax;
    float dMin;

    float partP;
    float partI;
    float partD;

    float pidMax;
    float pidMin;
} pidc_t;

/* ENUMS */

/* EXTERNS */

/* FUNCTION PROTOTYPES */

void pidInit ( pidc_t* driver, float kp, float ki, float kd, float ts, float iPartMaxLimit, float iPartMinLimit,
                float dPartMaxLimit, float dPartMinLimit, float pidOutputMaxLimit, float pidOutputMinLimit );
void pidChangeCoefficients ( pidc_t* driver, float kp, float ki, float kd, float ts );
void pidControl ( pidc_t* driver, float input );
float pidGetOutput ( pidc_t* driver );

#ifdef __cplusplus
}
#endif

#endif /* PID_H_ */
