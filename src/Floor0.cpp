//
// File: Floor0.cpp
//
// Code generated for Simulink model 'Floor0'.
//
// Model version                  : 1.28
// Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
// C/C++ source code generated on : Fri Jan 24 16:51:36 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Atmel->AVR
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#include "Floor0.h"
#include <Arduino.h>
#include <SoftwareSerial.h>

// Named constants for Chart: '<Root>/Floor'
#define IN_Floor_Initial ((uint8_T)1U)
#define IN_fled_1 ((uint8_T)2U)
#define IN_fled_2 ((uint8_T)3U)
#define IN_fled_3 ((uint8_T)4U)
#define IN_fled_4 ((uint8_T)5U)

char buffer;

// Model step function
void Floor0ModelClass::step()
{
  // Chart: '<Root>/Floor' incorporates:
  //   Inport: '<Root>/b1'
  //   Inport: '<Root>/b2'
  //   Inport: '<Root>/b3'
  //   Inport: '<Root>/b4'
  if (rtDW.is_active_c3_Floor0 == 0U)
  {
    rtDW.is_active_c3_Floor0 = 1U;

    // Outport: '<Root>/l1'
    rtY.l1 = false;

    // Outport: '<Root>/l2'
    rtY.l2 = false;

    // Outport: '<Root>/l3'
    rtY.l3 = false;

    // Outport: '<Root>/l4'
    rtY.l4 = false;
    rtDW.is_c3_Floor0 = IN_Floor_Initial;
  }
  else
  {
    switch (rtDW.is_c3_Floor0)
    {
    case IN_Floor_Initial:
      if (rtU.b1)
      {
        rtDW.is_c3_Floor0 = IN_fled_1;

        // Outport: '<Root>/l1'
        rtY.l1 = !rtY.l1;
        rtU.b1 = false;
        // digitalWrite(LED1, rtY.l1 ? HIGH : LOW);
      }
      else if (rtU.b2)
      {
        rtDW.is_c3_Floor0 = IN_fled_2;

        // Outport: '<Root>/l2'
        rtY.l2 = !rtY.l2;
        rtU.b2 = false;
        // digitalWrite(LED2, rtY.l2 ? HIGH : LOW);
      }
      else if (rtU.b3)
      {
        rtDW.is_c3_Floor0 = IN_fled_3;

        // Outport: '<Root>/l3'
        rtY.l3 = !rtY.l3;
        rtU.b3 = false;
        // digitalWrite(LED3, rtY.l3 ? HIGH : LOW);
      }
      else
      {
        if (rtU.b4)
        {
          rtDW.is_c3_Floor0 = IN_fled_4;

          // Outport: '<Root>/l4'
          rtY.l4 = !rtY.l4;
          rtU.b4 = false;
          // digitalWrite(LED4, rtY.l4 ? HIGH : LOW);
        }
      }
      break;

    case IN_fled_1:
      delay(2);
      Serial.println("LED1");
      digitalWrite(LED1, rtY.l1 == true ? HIGH : LOW);
      rtDW.is_c3_Floor0 = IN_Floor_Initial;
      break;

    case IN_fled_2:
      delay(2);
      Serial.println("LED2");
      digitalWrite(LED2, rtY.l2 == true ? HIGH : LOW);
      rtDW.is_c3_Floor0 = IN_Floor_Initial;
      break;

    case IN_fled_3:
      delay(2);
      Serial.println("LED3");
      digitalWrite(LED3, rtY.l3 == true ? HIGH : LOW);
      rtDW.is_c3_Floor0 = IN_Floor_Initial;
      break;

    default:
      // case IN_fled_4:
      delay(2);
      Serial.println("LED4");
      digitalWrite(LED4, rtY.l4 == true ? HIGH : LOW);
      rtDW.is_c3_Floor0 = IN_Floor_Initial;
      break;
    }
  }

  // End of Chart: '<Root>/Floor'
}

// Model initialize function
void Floor0ModelClass::initialize()
{
  // (no initialization code required)
}

void Floor0ModelClass::changeButtonState(int button)
{
  switch (button)
  {
  case 1:
    rtU.b1 = true;
    delay(2);
    Serial.println("changeButtonState LED1");

    break;
  case 2:
    rtU.b2 = true;
    delay(2);
    Serial.println("changeButtonState LED2");
    break;

  case 3:
    rtU.b3 = true;
    delay(2);
    Serial.println("changeButtonState LED3");
    break;

  case 4:
    rtU.b4 = true;
    delay(2);
    Serial.println("changeButtonState LED4");
    break;

  default:
    rtU.b1 = false;
    rtU.b2 = false;
    rtU.b3 = false;
    rtU.b4 = false;
    break;
  }
}

// Constructor
Floor0ModelClass::Floor0ModelClass()
{
  // Currently there is no constructor body generated.
}

// Destructor
Floor0ModelClass::~Floor0ModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL *Floor0ModelClass::getRTM()
{
  return (&rtM);
}

//
// File trailer for generated code.
//
// [EOF]
//
