#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Vehicle{
    protected:
    float m_lla[3];

    private:
    virtual void serialize(std :: ostream &os);

    public:
    Vehicle();
    Vehicle(float *lla);
    Vehicle(Vehicle &copy);
    virtual ~Vehicle();

    void operator= (Vehicle &OVehicle);
    friend std::ostream &operator<<(std::ostream &os, Vehicle &vehicle);
    
    void SetLLA(float *lla);
    float getLla();

    virtual void Move(float *lla) = 0; /**May need to make a const before the = sign**/
};