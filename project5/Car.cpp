#include <iostream>
#include <cstring>
#include "Vehicle.h"
#include "Car.h"

using namespace std;

Car :: Car(){
    Car :: setThrottle(0);
    cout << "Car #" << this -> getVin() << ": Default-Ctor" << endl;
}

Car :: Car(char *plates, int vin, float *lla):
    Vehicle(vin, lla)
{
    Car :: setThrottle(0);
    Car :: setPlates(plates);
    cout << "Car #" << this ->getVin() << ": Parametrized-Ctor" << endl;
}

Car :: Car(const Car &copy):
    Vehicle(copy)
{
    setPlates(copy.m_plates);
    setThrottle(copy.m_throttle);
    cout << "Car #" << this ->getVin() << ": Copy-Ctor" << endl;
}

Car :: ~Car(){

}

std :: ostream & operator<< (std::ostream &os, Car &car){
    os << "Car #" << car.getVin() << " Plates: " <<
    car.getPlates() << " Throttle: " << car.getThrottle() << " @ [" << 
    car.m_lla[0] << ", " << 
    car.m_lla[1] << ", " << 
    car.m_lla[2] << "]" << endl;
    return os;
}

void Car :: operator=(Car &OCar){ /**Might need to set the vehicle part individually**/
    this ->setLla(OCar.m_lla);
    this -> setPlates(OCar.m_plates);
    this -> setThrottle(OCar.m_throttle);
    cout << "Car #" << this ->getVin() << ": Assignment" << endl;
}

char* Car :: getPlates(){
    return m_plates;
}

int Car :: getThrottle(){
    return m_throttle;
}

void Car :: setThrottle(int throttle){
    m_throttle = throttle;
}

void Car :: setPlates(const char *plates){
    
    strcpy(m_plates, plates);
}

void Car :: drive (int throttle){
    m_throttle = throttle;
}

void Car :: move(float *lla){
    cout << "Car #" << this ->getVin() << ": Drive to Destination, with throttle @ 75" << endl;
    drive(75);
    this -> setLla(lla);
}


