#include <iostream>
#include  "car.h"
#include "sensor.h"

char *myStringCopy(char *destination, const char *source){
    for(; *source != '\0';){
        *destination = *source;
        *destination++;
        *source++;
    }
    *destination = '\0';
    return destination;
}
 /**Default Constructor**/
car :: car(){
    car :: setYear(0000);
    car :: setMake(empty);
    car :: setModel(empty);
    car :: setPrice(0.00);
    car :: setAvailable(0); /**Do I need to have the type in this thing**/
    car :: setOwner(empty);
}
/**Paramatierized Constructor**/
car :: car(int year, char *make, char *model, float price, bool available, char *owner){
    car :: setYear(year);
    car :: setMake(make);
    car :: setModel(model);
    car :: setPrice(price);
    car :: setAvailable(available); 
    car :: setOwner(owner);    
}

/**Setters**/
void car :: setYear(int year){
    m_year = year;
}
void car :: setMake(char *make){
    myStringCopy(m_make, make);
}
void car :: setModel(char *model){
    myStringCopy(m_model, model);
}
void car :: setPrice(float price){
    m_price = price;
}
void car :: setAvailable(bool available){
    m_available = available;
}
void car :: setOwner(char *owner){
    myStringCopy(m_owner, owner);
}
void car :: setSensor(sensor *sensorPtr){
    sensor *m_sensorsPtr = m_sensors;
    for(int i = 0; i < 3; i++){
        m_sensorsPtr ->setType(sensorPtr ->getType());
        m_sensorsPtr ->setExCost();
        sensorPtr++;
        m_sensorsPtr++;
    }
}

/**Getters**/
int car :: getYear(){
   return m_year;
}
char *car :: getMake(){
    return m_make;
}
char *car :: getModel(){
    return m_model;
}
float car :: getPrice(){
    return m_price;
}
bool car :: getAvailable(){
    return m_available;
}
char *car :: getOwner(){
    return m_owner;
}
float car :: getFPrice(int day, sensor *sensorPtr){
    float FPrice;
    float tExCost[3] = {0.00,0.00,0.00};
    for(int i = 0; i < 3; i++){
        tExCost[i]= sensorPtr ->getExCost();
        sensorPtr++;
    }
    FPrice = m_price*day + tExCost[0]*day +tExCost[1]*day + tExCost[2]*day;
    return FPrice;
}
sensor *car ::getSensor(){
    return m_sensors;
}

/**Calculates the price of a rent**/
float car :: estimateCost(int day){
    BPrice = day*m_price;
    return BPrice;
}




