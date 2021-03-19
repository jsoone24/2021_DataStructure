#pragma once
#include "Car.h"
#include <string>

class SportsCar : public Car{
public:
    bool bTurbo; 
    SportsCar() {}
    SportsCar(int s, std::string n, int g): Car(s,n,g) {}
    void setTurbo(bool bTur) {
        bTurbo = bTur;
    }
    void speedUp() {
        if( bTurbo ){
         speed += 20;            
        }
        else{
        Car::speedUp();
        }
    }
};