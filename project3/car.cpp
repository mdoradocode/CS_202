#include  "car.h"

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
    car :: setAvailable(0);
}
/**Paramatierized Constructor**/
car :: car(int year, char *make, char *model, float price, bool available){
    car :: setYear(year);
    car :: setMake(make);
    car :: setModel(model);
    car :: setPrice(price);
    car :: setAvailable(available);      
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
/**Calculates the price of a rent**/
float car :: estimateCost(int day){
    return day*m_price;
}

