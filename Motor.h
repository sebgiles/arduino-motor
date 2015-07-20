//
//  Motor.h
//  
//
//  Created by Sebastian Giles on 26/11/14.
//
//

#ifndef ____Motor__
#define ____Motor__

#include "Arduino.h"

class Motor {
public:

    Motor(int fwdPin, int revPin, float supplyVoltage=0);

    void turn(float power); //-1<=power<=1
    void applyVoltage(float voltage);

    void stop();

    void setSupplyVoltage(float newVoltage);
    
protected:

    int pin1;
    int pin2;

private:
    float supplyVoltage;

};

//Requires a half H-bridge
class PCMotor : public Motor{
public:
    PCMotor(int pwmPin, int dirPin, float supplyVoltage=0);
    
    void turn(float power); //-1<=power<=1
    
};

#endif