/** 
Name: Michael Dorado
Program: project4.cpp
Date: 
Notes: 
**/
#include <iostream>
#include <fstream>
#include "agency.h"
#include "car.h"
#include "sensor.h"

#define size 256
#define fileSize 20

using namespace std;

size_t myStringLength(const char *str);
int myStringCompare(const char *str1, const char *str2);
char *myStringCat(char *destination, const char *source);

void menu(int *option);


int main(){
    int k = 0;
    agency Agency;
    while(k != 5){
        
        /**Menu**/
        menu(&k);
        switch(k){
            case 1: 
            /**Read in Data**/
            Agency.readData();
            break;
            case 2: 
            /**Print Data**/
            Agency.printData();
            break;
            case 3: 
            /**Print total # of sensors**/
            Agency.displayCount();
            break;
            case 4:
            /**Find the most expensive car, ask if they want to rent it, update owner and availability**/
            break;
            case 5:
            cout << "=====Thank you for shopping with us!=====" << endl;
            exit(-1);
            break;

        }
        
    }
    return 0;
}

void menu(int *option){
    cout << "=====Welcome to Car Rentals====="<< endl 
    << "1) Enter in the data from a file" << endl 
    << "2) Print all data entered to the screen" << endl    
    << "3) Print total number of sensors" << endl 
    << "4) Find the most expensive car" << endl 
    << "5) Exit program" << endl;
    cin >> *option; 
}






size_t myStringLength(const char *str){
    int counter = 0;
    for(; *str != '\0'; *str++){
        counter++;
        *str++;
    }
    return counter++;
}

int myStringCompare(const char *str1, const char *str2){
    for(;(*str1 != '\0') && (*str2 != '\0');*str1++, *str2++){
        int i = *str1;
        int j = *str2; 
        if(i >= 97){
            i -= 32;
        }
        if(j >= 97){
            j -= 32;
        }
        if(i > j){
            return 1;
        }
        else if(i < j){
            return -1;
        }
    }
    return 0;
}

char *myStringCat(char *destination, char *source){
    for(; *source != '\0' + 1; *destination++){
        if(*destination == '\0'){
            for(; *source != '\0'; *source++){
                *destination = *source;
                *destination++;
            }
            *destination = '\0';
            break;
        }
    }
    return destination;
}