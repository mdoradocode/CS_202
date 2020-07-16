#include <iostream>
#include "Vehicle.h"
#include <cstring>

int Vehicle:: s_idgen = 1;
int Vehicle:: deletedVin[256] = {0};

/**Can I please get a constructor? Can I pleeease get a constructor**/
Vehicle :: Vehicle():
m_vin(s_idgen)
{
    
    cout << "Vehicle " << this ->getVin() << ": " << "Default-Ctor" << endl;
}

Vehicle :: Vehicle(int vin, float *lla):
    m_vin(vinMake(vin))
{
    Vehicle :: setLla(lla);
    cout << "Vehicle " << this -> getVin() << ": " << "Parametrized-Ctor" << endl;
}

Vehicle :: Vehicle(const Vehicle &copy):
    m_vin(vinMake(1))
{
    setLla(copy.m_lla);
    cout << "Vehicle " << this -> getVin() << ": " << "Copy-Ctor" << endl;
}

Vehicle :: ~Vehicle(){
    int i = 0;
    do{
        deletedVin[i] = this -> getVin(); /**Look into incrementing the pointer to vin for this**/
    }while(deletedVin[i] != 0);
    cout << "Vehicle" << m_vin << ": " << "Dtor" << endl;
}


/** Mutha fuqin uhhhhhhhhhhhhhh overload operators**/
void Vehicle :: operator= (Vehicle &OVehicle){
    this -> setLla(OVehicle.m_lla);
}

std::ostream &operator<<(std::ostream &os, const Vehicle & vehicle){ 
    os << "Vehicle " << vehicle.m_vin << " @ " << '['
    << vehicle.m_lla[0] << ", "
    << vehicle.m_lla[1] << ", "
    << vehicle.m_lla[2] << ']' << endl;
    return os;
} /** What should this function return**/


/**Getters and Setters Babyyyyyy**/
void Vehicle :: setLla(const float *lla){
    for(int i = 0; i < 3; i++){
        m_lla[i] = *lla;
        lla++;
    }
}

int Vehicle :: vinMake(int vin){
    if(vin > s_idgen){
        return vin;
    }
    else{
        s_idgen++;
        return s_idgen;
    }

    
}

float *Vehicle :: getLla(){
    return m_lla;
}

int Vehicle :: getVin(){
    return m_vin;
}

const int Vehicle :: getIdgen(){
    return s_idgen;
}


/**Whats the move Function**/
void Vehicle :: move(float *lla){
    cout << "Vehicle " << this -> getVin() << ": CANNOT MOVE - I DON'T KNOW HOW TO" << endl; 
}

/** how to get static memebers to work**/