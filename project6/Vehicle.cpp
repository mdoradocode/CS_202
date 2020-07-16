#include <iostream>
#include <cstring>
#include "Vehicle.h"

using namespace std;

/**Serialize**/
void Vehicle :: serialize(std :: ostream &os){
    os << "Vehicle @ [" <<
    this -> m_lla[0] << ", " <<
    this -> m_lla[1] << ", " <<
    this -> m_lla[2] << "]";
}


/**Constructors**/
Vehicle :: Vehicle(){
    cout << "Vehicle: Default-Ctor" << endl;
}

Vehicle :: Vehicle(float *lla){
    Vehicle :: SetLLA(lla);
    cout << "Vehicle: Paramerterized-Ctor" << endl;
}

Vehicle :: Vehicle(Vehicle &copy){
    SetLLA(copy.m_lla);
    cout << "Vehicle: Copy-Ctor" << endl;
}

Vehicle ::  ~Vehicle(){
    cout << "Vehicle: Dtor" << endl;
}

/**Operator Overload**/
void Vehicle :: operator= (Vehicle &OVehicle){
    this -> SetLLA(OVehicle.m_lla);
    cout << "Vehicle: Assignment" << endl;
}

std::ostream &operator<<(std::ostream &os, Vehicle & vehicle){ 
    vehicle.serialize(os);
    return os;
}

/**Getters and Setters**/
void Vehicle :: SetLLA(float *lla){
    for(int i = 0; i < 3; i++){
        m_lla[i] = *lla;
        lla++;
    }
}

float Vehicle :: getLla(){
    return *m_lla;
}

/**Pure Virtual**/
void Vehicle :: Move(float *lla){
    this -> SetLLA(lla);
}
