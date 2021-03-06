// Include protector.
#ifndef __CONFIG_STATIC_H__
#define __CONFIG_STATIC_H__
#include<Arduino.h>
//===================================== STATIC H/W CONFIGS =====================================
/**
 * Configs using #define pre-prosessor directives.
 * These are used to save memory since these values are replaced before compilation.
 * These settings cannot be configured during runtime.
 * These are meant to be fixed.
 * Put any config that should'nt change here.
 */
 
  // BT input/output pins
    #define BT_PIN_OUT 1
    #define BT_PIN_IN 0
    #define BT_BAUDRATE 9600
  // ARM output pins
    #define ARM_J1_OUT 9
    #define ARM_J2_OUT 10
    #define ARM_ROTATE_OUT 11
    // ARM initial values
      #define ARM_J1_INIT (byte)100
      #define ARM_J2_INIT (byte)150
      #define ARM_ROTATE_INIT (byte)80
    // ARM move limits
      #define ARM_J1_LIMIT_MIN (byte)35
      #define ARM_J1_LIMIT_MAX (byte)160
      #define ARM_J2_LIMIT_MIN (byte)0
      #define ARM_J2_LIMIT_MAX (byte)180
      #define ARM_ROTATE_LIMIT_MIN (byte)0
      #define ARM_ROTATE_LIMIT_MAX (byte)180
    
  // Temperature Sensor Pin
    #define TEMP_SENSOR 2
  // Air Quality Analog pin
    #define MQ_PIN A5
  
  // Car motor pins
    #define CAR_RIGHT_MOTOR_OUT_1 A0
    #define CAR_RIGHT_MOTOR_OUT_2 A1
    #define CAR_LEFT_MOTOR_OUT_1 A2
    #define CAR_LEFT_MOTOR_OUT_2 A3
  
  // DEBUG config, See _DEBUG_PRINT_, it is usefull.
  #ifndef __DEBUG_CONFIG__
    // enable/disable debugging.
    // Saves a LOT of memory when disabled.
    #define __DEBUG_ENABLED__ false
    #define __DEBUG_SERIAL__ Serial // the serial to print debug data to.
    
//==============================================================================================

// DEBUG Macros
    #if __DEBUG_ENABLED__
      #define _DEBUG_PRINT_(X) __DEBUG_SERIAL__.print(X)
    #else
      #define _DEBUG_PRINT_(X)  
    #endif
  #endif

// Config checks
#if __DEBUG_ENABLED__
  #warning "DEBUG enabled...! Debug mode will use more memory."
#endif
#if BT_PIN_OUT==BT_PIN_IN
  #error "Config: BT_PIN_OUT and BT_PIN_IN have same values."
#endif
#if ARM_J1_OUT==ARM_J2_OUT or ARM_J2_OUT==ARM_ROTATE_OUT or ARM_J1_OUT==ARM_ROTATE_OUT
  #error "Config: ARM's OUT pins are not different."
#endif

#endif // __CONFIG_STATIC_H__
