#pragma once
#include "sensor.h"
#include "car.h"
#include <fstream>
class agency{
    public:
    agency();
    agency(char *name, int zip, car *inv); 

    void setName(char *name);
    void setZip(int zip);
    void setInventory(car * inv);
    
    char *getName();
    int getZip();

    void printData();
    void readData();
    void displayCount();

    private:
    char m_name[256];
    int m_zip;
    car m_inventory[5];
    char empty[256] = "EMPTY";
    int radar, lidar, camera, gps;
};

