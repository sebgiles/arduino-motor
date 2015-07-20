//
//  Motor.cpp
//  
//
//  Created by Sebastian Giles on 26/11/14.
//
//

#include "Motor.h"

Motor::Motor(int fwdPin, int revPin, float supplyVoltage):
pin1(fwdPin),
pin2(revPin),
supplyVoltage(supplyVoltage)
{
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
} 

void Motor::turn(float p){
    if (p>1) p=1;
    else if (p<-1) p=-1;
    if (p>=0){
        analogWrite(pin2, 0); 
        analogWrite(pin1, p*255);
    } else {
        analogWrite(pin1, 0);
        analogWrite(pin2, -p*255);
    }
}

void Motor::applyVoltage(float voltage){
    if(supplyVoltage!=0)
        turn(voltage/supplyVoltage);
}

void Motor::stop(){
    turn(0);
}

PCMotor::PCMotor(int pwmPin, int dirPin, float voltage):
Motor(pwmPin,dirPin,voltage)
{
}

void PCMotor::turn(float power){
    if (power<0) {
        power=-power;
        digitalWrite(pin2, LOW);
    } else {
        digitalWrite(pin2, HIGH);
    }
    analogWrite(pin1, power*255);
}