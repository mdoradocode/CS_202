/** 
Name: Michael Dorado
Program: projec3.cpp
Date: 09/018/2019
Notes: This program takes a list of car data, makes a struct out of the agencies
and then makes a class out of the cars, it then can interact with the cars in a variety of ways. 
**/

#include <iostream>
#include <fstream>
#include "car.h"
#define size 5
#define fileSize 20
using namespace std;
struct agency{
    char name[256];
    char zip[6];
    car inventory[size];
};

size_t myStringLength(const char *str);
int myStringCompare(const char *str1, const char *str2);
char *myStringCat(char *destination, const char *source);

void menu(int *option); /**Displays the menu**/
void readFileIn(agency *arr);/**reads a file in**/
void printData(agency *arr);/**prints data to terminal**/
void rentEstimate(agency *arr);/**estimates rents**/
void findMostExpensiveCar(agency *arr);/**Finds most expensive car out of all agencies**/
void writeToFileUwu(agency *arr);/** writes to the file my guy**/



int main(){
    int k = 0;
    agency rentArray[3];
    char fileOut[fileSize];
    
    while (k != 6){
        menu(&k);
        switch(k){
            case 1: 
            readFileIn(rentArray);
            break;

            case 2:
            printData(rentArray);
            break;

            case 3:
            rentEstimate(rentArray);
            break;

            case 4:
            findMostExpensiveCar(rentArray);
            break;

            case 5:
            writeToFileUwu(rentArray);
            break;

            case 6:
            cout << "===== Thank you for shopping with us! =====";
            exit(1);
            break;


        }
        k = 0;
    }
    return 0;
}

void writeToFileUwu(agency *arr){
    agency *arrPtr = arr;
    
    char fileName[fileSize];
    ofstream writeFile;
    cout <<"Please enter the outgoing file name:" << endl;
    cin >> fileName;
    writeFile.open(fileName);

    for(int i = 0; i < 3; i++){
        car *carPtr = arrPtr ->inventory;
        writeFile << arrPtr -> name << ' ';
        for(int m = 0; m < 5;  m++){
            writeFile << arrPtr -> zip[m];
        }
        writeFile << ':' << endl;
        for(int j = 0; j < 5; j++){
            writeFile << carPtr ->getYear() << ' ' << carPtr -> getMake() << ' ' <<
            carPtr ->getModel() << ' ' << carPtr ->getPrice() << ' ' << 
            carPtr ->getAvailable() << endl;
            carPtr++;
        }
        writeFile << endl;
        arrPtr++;

    }


}

void findMostExpensiveCar(agency *arr){
    agency *arrPtr = arr;
    float bigPrice;
    car *expCar = arrPtr -> inventory;

    for(int i = 0; i < 3; i++, arrPtr++){
        car *carPtr = arrPtr -> inventory;
        for(int j = 0; j < 5; j++){
            if(bigPrice < carPtr -> getPrice()){
                bigPrice = carPtr ->getPrice();
                expCar = carPtr;
            }
            carPtr++;
        }
        if(i == 2){
            cout << "The most expensive car is a(n)  " << expCar ->getYear() << ' '<< expCar -> getMake() 
            << ' ' << expCar -> getModel() << endl;
        }
    }    
}

void rentEstimate(agency *arr){
    int aIndex, cIndex, daysToRent;
    float tprice;
    agency *arrPtr = arr;
    
    cout << "Which agency would you like to rent from?" << endl 
    << "Hertz (0)" << endl << "Alamo (1)" << endl
    << "Budget (2)";
    cin >> aIndex;
    cout << "Which car would you like to rent? (0, 1, 2, 3, 4):" << endl;
    cin >> cIndex;
    cout << "How many days would you like to rent the car for?" << endl;
    cin >> daysToRent;
    for(int i = 0; i <= aIndex; i++){
        car *carPtr = arrPtr -> inventory;
        for(int j = 0; j < cIndex; j++){
            carPtr++;
        }
        if(i == aIndex){
            tprice = carPtr -> estimateCost(daysToRent);
            cout << "To rent a(n)" << carPtr ->getYear() << ' '<< carPtr -> getMake() 
            << ' ' << carPtr -> getModel() << ' ' 
            << "it will cost $" << tprice << endl;
        }
        arrPtr++;
    }

}

void printData(agency *arr){
    agency *arrPtr = arr;
    for(int i = 0; i < 3; i++){
        car *rentPtr = arrPtr -> inventory;
        cout << arrPtr -> name << ' ' << arrPtr -> zip << ':' << endl;
        for (int j = 0; j < 5 ; j++){
            cout << rentPtr -> getYear() << ' ' << rentPtr -> getMake() << ' ' 
            << rentPtr ->getModel() << ' ' << '$' << rentPtr -> getPrice() << ' ' 
            << rentPtr -> getAvailable() << endl;
            rentPtr++;
        }
        cout << endl;
        arrPtr++;
    }
}

void readFileIn(agency *arr){
    char fileIn[fileSize];
    ifstream readFile;
    agency *arrPtr = arr;
    char zipArr[6];

    cout << "Please enter your file name:";
    cin >> fileIn;
    readFile.open(fileIn);

    for(int i = 0; i < 3; i++, arrPtr++){
        car *carPtr = arrPtr ->inventory;
        readFile >> arrPtr -> name;
        for(int m = 0; m < 5;  m++){
            readFile >> arrPtr -> zip[m];
        }
        arrPtr -> zip[5] = '\0';
 
        for(int j = 0; j < 5; j++){
            
            int tyear;
            char tmake[256];
            char tmodel[256];
            float tprice;
            bool tavailable;
    
            readFile >> tyear;
            readFile >> tmake;
            readFile >> tmodel;
            readFile >> tprice;
            readFile >> tavailable;
         
            carPtr -> setYear(tyear);
            carPtr -> setMake(tmake);
            carPtr -> setModel(tmodel);
            carPtr -> setPrice(tprice);
            carPtr -> setAvailable(tavailable);

            carPtr++;
        }
    }

    readFile.close();
}

void menu(int *option){
    cout << "=====Welcome to Car Rentals====="<< endl 
    << "1) Enter in the data from a file" << endl 
    << "2) Print all data entered to the screen" << endl    
    << "3) Get a quote on rental prices" << endl 
    << "4) Find the most expensive car" << endl 
    << "5) Enter all data to an outgoing file" << endl
    << "6) Exit program" << endl;
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