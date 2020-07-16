/** 
Name: Michael Dorado
Program: project2.cpp
Date: 09/09/2019
Notes: This program takes a list of car data, makes a struct out of it and creates a menu
that the user can use to interact with car prices and renting.
**/
#include <iostream>
#include <fstream>
using namespace std;

#define fileSize 20
struct car{
    int year;
    char make[10];
    char model[10];
    float price;
    bool available;
};

size_t myStringLength(const char *str);
int myStringCompare(const char *str1, const char *str2);
char *myStringCopy(char *destination, const char *source);
char *myStringCat(char *destination, const char *source);
void printData(car carInput[], int spot[]);
void writeToFile(car carInput[], ofstream& fileNameOut);
void priceCopy(car source[], car destination);
void priceSwap(car *a, car *b);
void priceSort(car *carInput, int *spot);
void rentEstimate(int rentLength, car carInput[], int carChoice);
void rentCar(int rentLength, car carInput[]);




int main(){
    car carInput[5];
    int menu = 0;
    char fileIn[fileSize], fileOut[fileSize];
    int rentLength, carChoice;
    int spot[5] = {0,1,2,3,4};



    ifstream readFile;
    ofstream writeFile;
    

    while (menu != 7){
        cout << "=====Welcome to Car Rentals====="<< endl 
        << "1) Enter in the data from a file" << endl 
        << "2) Print all data entered to the screen" << endl 
        << "3) Enter all data to an outgoing file" << endl
        <<"4) Sort the car prices from most to least expensive" << endl 
        <<"5) Get a quote on rental prices" << endl 
        << "6) Choose a car to rent" << endl 
        << "7) Exit program" << endl;
        cin >> menu;
        switch (menu){
            case 1: 
            cout << "Please enter the input file." << endl;
            cin >> fileIn;
            readFile.open(fileIn);
            for(int i = 0; i < 5; i++){
                readFile >> carInput[i].year >> carInput[i].make >> carInput[i].model >> carInput[i].price >> carInput[i].available;
            }
            readFile.close();
            break;

            case 2:
            printData(carInput, spot);
            break;

            case 3:
            cout << "Please enter a the file you wish to write to: ";
            cin >> fileOut;
            writeFile.open(fileOut);
            writeToFile(carInput, writeFile);
            break;

            case 4:
            priceSort(carInput, spot);
            break;

            case 5:
            rentCar(rentLength, carInput);
            break;

            case 6:
            rentEstimate(rentLength, carInput, carChoice);
            break;

            case 7:
            break;


        }
    }
}

void rentCar(int rentLength, car carInput[]){ /**This funtion displays available cars to rent and gives their prices based on how many days they want to rent for**/
    cout << "How many days would you like to rent the car?" << endl;
    cin >> rentLength;
    cout << "Here are the vehicles for rent and their cost:" << endl;
    for(int i = 0; i < 5; i++){
        if(carInput[i].available == 1){
            cout << '[' << i << ']' << ' ' << carInput[i].year << ' ' << carInput[i].make << ' ' << carInput[i].model << ' ' << carInput[i].price << ' ' << carInput[i].available << endl;
            cout << carInput[i].price*rentLength << endl;
        }
    }
}

void rentEstimate(int rentLength, car carInput[], int carChoice){ /**This function selects a car to rent and makes the car unavailable going forward**/
    cout << "Which car would like to rent? (0, 1, 2, 3, 4)"<< endl;
    cin >> carChoice;
    cout << "How many days would you like to rent the car for?" << endl;
    cin >> rentLength;
    if(carInput[carChoice].available == 0){
        cout << "This car is unavailable for rent." << endl;
    }
    else if(carInput[carChoice].available == 1){
        carInput[carChoice].available = 0;
        cout << "Your chosen car was sucessfully rented! The total cost (in dollars) will be:" << carInput[carChoice].price*rentLength << endl;
    }
}

void priceSort(car *carInput, int *spot){/**This function sorts the cars by price using a price swap function**/
    for(int j = 0; j < 5; j++){
        for(int i = 0; i < 5 - j - 1; i++){
            if(carInput[i+1].price > carInput[i].price){
                priceSwap(&carInput[i+1], &carInput[i]);
                int temp = spot[i+1];
                spot[i+1] = spot[i];
                spot[i] = temp;
            }
        }
    }
}

void priceSwap(car * a, car * b){/**uses pointers to swap struct values**/
    car temp = *a;
    *a = *b;
    *b = temp;
}


void writeToFile(car carInput[], ofstream& fileNameOut){ /** Writes car data to a user defined file**/
    for(int i = 0; i < 5; i++){
        fileNameOut << ' ' << carInput[i].year << ' ' << carInput[i].make << ' ' << carInput[i].model << ' ' << carInput[i].price << ' ' << carInput[i].available << endl;
    }
}

void printData(car carInput[], int spot[]){ /**prints data to the terminal**/
    for(int i = 0; i < 5; i++){
        cout << '[' << spot[i] << ']' << ' ' << carInput[i].year << ' ' << carInput[i].make << ' ' << carInput[i].model << ' ' << carInput[i].price << ' ' << carInput[i].available << endl;
        cout << endl;
     }
}















char *myStringCopy(char *destination, const char *source){
    for(; *source != '\0';){
        *destination = *source;
        *destination++;
        *source++;
    }
    return destination;
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