#pragma once
#include <iostream>
#include <cstring>
#include "Vehicle.h"

using namespace std;

class Car: public Vehicle{
    private:
    int m_throttle;

    virtual void serialize(std::ostream &obj);

    public:

    Car();
    Car(float *lla);
    Car(Car &copy);
    virtual ~Car();

    void operator=(Car &car);

    void setThrottle(int throttle);
    
    int getThrottle();

    void drive(int throttle);


    virtual void Move(float *lla);
};


