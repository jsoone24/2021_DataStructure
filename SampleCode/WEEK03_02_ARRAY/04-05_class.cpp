#include "SportsCar.h"

int main(){
    Car yourCar (80, "your car", 4);
    SportsCar myCar(100, "MY car", 4);

    yourCar.display();
    myCar.display();
    yourCar.speedUp();
    myCar.speedUp();
    yourCar.display();
    myCar.display();
    yourCar.changeGear(3);
    myCar.changeGear(3);
    yourCar.display();
    myCar.display();
    
    return 0;
}