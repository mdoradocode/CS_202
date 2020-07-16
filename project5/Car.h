#include <iostream>
#include "Vehicle.h"

using namespace std;

class Car: public Vehicle{
    private:
    char m_plates[256];
    int m_throttle;

    public:
    Car();
    Car(char *plates, int vin, float *lla);
    Car(const Car &copy);
    ~Car();

    void operator=(Car &OCar);

    char *getPlates();
    int getThrottle();

    void setPlates(const char *plates);
    void setThrottle(int throttle);
    void drive(int throttle);
    void move(float *lla);

    friend std::ostream &operator<<(std::ostream &os, Car &car);
};
