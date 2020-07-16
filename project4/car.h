#pragma once
#include "sensor.h"

class car{
    public:
        car();
        car(int year, char *make, char *model, float price, bool available, char *owner);
        int getYear();
        char *getModel();
        char *getMake();
        float getPrice();
        bool getAvailable();
        char *getType();
        char *getOwner();
        int getFPrice(float BPrice);
        sensor *getSensor(); 

        void setYear(int year);
        void setModel(char *model);
        void setMake(char *make);
        void setPrice(float price);
        void setAvailable(bool available);
        void setOwner(char *owner);
        void setSensor(sensor *sensorPtr);

        float estimateCost(int days);
        float getFPrice(int days, sensor *sensorPtr);
    private:
        int m_year;
        char m_make[256];
        char m_model[256];
        float m_price;
        bool m_available;
        char empty[256] = "EMPTY";
        float FPrice;
        float BPrice;
        char m_owner[256];
        sensor m_sensors[3];

};