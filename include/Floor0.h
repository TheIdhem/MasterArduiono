//
// File: Floor0.h
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
#ifndef RTW_HEADER_Floor0_h_
#define RTW_HEADER_Floor0_h_
#ifndef Floor0_COMMON_INCLUDES_
#define Floor0_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif // Floor0_COMMON_INCLUDES_

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm) ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val) ((rtm)->errorStatus = (val))
#endif

// Forward declaration for rtModel
typedef struct tag_RTM RT_MODEL;

// Our custom pins
#define BUTTON1 2
#define BUTTON2 3
#define BUTTON3 4
#define BUTTON4 5

#define LED1 6
#define LED2 7
#define LED3 8
#define LED4 9

#define BUSRX 11
#define BUSTX 12
#define BUSCTRL 13

#define DIPSELECT1 14
#define DIPSELECT2 15

// Block signals and states (default storage) for system '<Root>'
typedef struct
{
  uint8_T is_active_c3_Floor0; // '<Root>/Floor'
  uint8_T is_c3_Floor0;        // '<Root>/Floor'
} DW;

// External inputs (root inport signals with default storage)
typedef struct
{
  boolean_T b1; // '<Root>/b1'
  boolean_T b2; // '<Root>/b2'
  boolean_T b3; // '<Root>/b3'
  boolean_T b4; // '<Root>/b4'
} ExtU;

// External outputs (root outports fed by signals with default storage)
typedef struct
{
  boolean_T l1; // '<Root>/l1'
  boolean_T l2; // '<Root>/l2'
  boolean_T l3; // '<Root>/l3'
  boolean_T l4; // '<Root>/l4'
} ExtY;

// Real-time Model Data Structure
struct tag_RTM
{
  const char_T *volatile errorStatus;
};

// Class declaration for model Floor0
class Floor0ModelClass
{
  // public data and function members
public:
  // External inputs
  ExtU rtU;

  // External outputs
  ExtY rtY;

  // model initialize function
  void initialize();

  void changeButtonState(int button);

  // model step function
  void step();

  // Constructor
  Floor0ModelClass();

  // Destructor
  ~Floor0ModelClass();

  // Real-Time Model get method
  RT_MODEL *getRTM();

  // private data and function members
private:
  // Block signals and states
  DW rtDW;

  // Real-Time Model
  RT_MODEL rtM;
};

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Note that this particular code originates from a subsystem build,
//  and has its own system numbers different from the parent model.
//  Refer to the system hierarchy for this subsystem below, and use the
//  MATLAB hilite_system command to trace the generated code back
//  to the parent model.  For example,
//
//  hilite_system('Project/Floor')    - opens subsystem Project/Floor
//  hilite_system('Project/Floor/Kp') - opens and selects block Kp
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'Project'
//  '<S1>'   : 'Project/Floor'

#endif // RTW_HEADER_Floor0_h_

//
// File trailer for generated code.
//
// [EOF]
//
