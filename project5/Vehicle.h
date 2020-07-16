#pragma once
#include <iostream>

using namespace std;

class Vehicle{
    protected:
    float m_lla[3];
    const int m_vin;

    private:
    static int s_idgen;
    static int deletedVin[256];

    public:
    Vehicle();
    Vehicle(int vin, float *m_lla);
    Vehicle(const Vehicle &copy);
    ~Vehicle();

    void operator= (Vehicle &OVehicle);
    void move(float *lla);
    friend std::ostream & operator<<(std::ostream &os, const Vehicle &vehicle);

    float *getLla();
    int getVin();

    void setLla(const float *lla);
    int vinMake(int vin);


    /** Unsure about how to implement the following**/
    static const int getIdgen();

    
};