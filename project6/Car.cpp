#include <iostream>
#include <cstring>
#include "Car.h"
#include "Vehicle.h"
 
using namespace std;

/**Serialize**/
void Car :: serialize(std :: ostream &os){
    os << "Vehicle Throttle: " << this ->getThrottle() << " @ [" << 
    this -> m_lla[0] << ", " <<
    this -> m_lla[1] << ", " <<
    this -> m_lla[2] << "]";

}
/**Constructors**/
Car :: Car()
{
    setThrottle(0);
    cout << "Car: Default-Ctor" << endl;
}

Car :: Car(float *lla): 
Vehicle(lla)
{
    setThrottle(0);
    cout << "Car: Parametrized-Ctor" << endl;
}

Car :: Car (Car &copy):
Vehicle(copy)
{
    setThrottle(copy.m_throttle);
    cout << "Car: Copy-Ctor" << endl;
}

Car :: ~Car(){
    cout << "Car: Dtor" << endl; /**Does this do anything in the function?**/
}

/**Getters and Setters**/
void Car :: setThrottle(int throttle){
    m_throttle = throttle;
}

int Car :: getThrottle(){
    return m_throttle;
}

/**Overloads, No instertion, its virtual**/
void Car :: operator= (Car &car){
    this -> SetLLA (car.m_lla);
    this ->setThrottle (car.m_throttle);
    cout << "Car: Assignment" << endl;
}

/**Move and Drive**/

void Car :: drive(int throttle){
    m_throttle = throttle;
}

void Car :: Move(float *lla){
    cout << "DRIVE to destination, with throttle @ 75" << endl;
    this -> drive(75);
    this -> SetLLA(lla);
}