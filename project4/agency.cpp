#include <iostream>
#include "agency.h"
#include "car.h"
using namespace std;


char *myStringCopy2(char *destination, const char *source){
    for(; *source != '\0';){
        *destination = *source;
        *destination++;
        *source++;
    }
    *destination = '\0';
    return destination;
}
int myStringCompare2(const char *str1, const char *str2){
    for(;(*str1 != '\0') && (*str2 != '\0');*str1++, *str2++){
        int i = *str1;
        int j = *str2; 
        if(i >= 97){
            i -= 32;
        }
        if(j >= 97){
            j -= 32;
        }
        if(i = j){
            return 0;
        }
    }
    return -1;
}

agency :: agency(){
    agency :: setName(empty);
    m_zip = 00000;

}
agency :: agency(char *name, int zip, car *inv){
    agency :: setName(name);
    agency :: setZip(zip);
}


/**Setters**/
void agency::setName(char *name){
   *myStringCopy2(m_name, name);
}
void agency::setZip(int zip){
    m_zip = zip;
}
void agency :: setInventory(car *inv){

}


/**Getters**/
char *agency :: getName(){
    return m_name;
}
int agency ::getZip(){
    return m_zip;
}
void agency :: displayCount(){
    cout << lidar;

}


/**Print Data and read Data**/
void agency::printData(){
    int day;
    car *invRef = m_inventory;
    

    cout << "How many days would you like to rent for?";
    cin >> day;
    cout << this -> getName() << ' ' << getZip() << ':' << endl << "========================"<< endl;
    for(int i = 0; i < 5; i++){
        sensor *senRef = invRef ->getSensor();

        cout <<"Year: " << invRef ->getYear() << endl; 
        cout << "Make: " << invRef ->getMake() <<endl;
        cout << "Model: " << invRef ->getModel()<< endl; 
        cout << "Base Price: " << '$'<< invRef -> estimateCost(day) << endl;
        cout << "Final Price" << "$"<< invRef ->getFPrice(day, senRef) << endl;
        cout << "Sensors: " << '{' ;

        for(int j = 0; j < 3; j++){
            cout << senRef ->getType() << ' ';
            senRef++;
        }
        cout << '}' << endl;
        cout << "Availability: " << invRef ->getAvailable() <<endl;
        cout << "Current Owner: " << invRef ->getOwner() << endl <<endl;
        invRef++;
    }
    
}


void agency::readData(){
    lidar = 0;
    radar = 0;
    camera = 0;
    gps = 0;
    ifstream fileIn;
    char tName[256];
    char readMove;
    int tZip;
    char fileName[256];
    car *invRef = m_inventory;

    cout << "Please enter your data file name with extension: " << endl;
    cin >> fileName;
    fileIn.open(fileName);

    fileIn >> tName;
    fileIn >> tZip;

    setName(tName);
    setZip(tZip);

    for(int i = 0; i < 5; i++){
        sensor sensorArr[3];
        sensor *senRef = sensorArr;
    

        int tyear;
        char tmake[256];
        char tmodel[256];
        float tprice;
        bool tavailable;
        char tOwner[256];
        char empty[256] = "EMPTY";

        fileIn >> tyear;
        fileIn >> tmake;
        fileIn >> tmodel;
        fileIn >> tprice;
        
        fileIn.get(readMove);
        fileIn.get(readMove);

        while(readMove != '}'){
            char tType[256];
            char *tTypeRef;
            if ((readMove == '{') || (readMove == ' ')){
                tTypeRef = tType;
                
                fileIn.get(readMove);
                while(readMove != ' '&& readMove !='}'){
                    *tTypeRef = readMove;
                    tTypeRef++;
                    fileIn.get(readMove);
                }
                *tTypeRef = '\0';

                senRef ->setType(tType);
                senRef ->setExCost();
                if(readMove == '}'){
                    break;
                }
                senRef++;

            }    

        }
        fileIn >> tavailable;
        if(tavailable == 0){
            fileIn >> tOwner;
        }
        else if(tavailable == 1){
            myStringCopy2(tOwner, empty);
        }
    
        invRef ->setYear(tyear);
        invRef ->setMake(tmake);
        invRef ->setModel(tmodel);
        invRef ->setPrice(tprice);
        invRef ->setSensor(sensorArr);
        invRef ->setAvailable(tavailable);
        invRef ->setOwner(tOwner);
            cout << "year" << ' ' <<invRef ->getYear()<< endl;
            cout << "make" << ' ' << invRef ->getMake() <<endl;
            cout << "Model" << ' ' << invRef ->getModel() <<endl;
            cout << "price" << ' ' << invRef ->getPrice() <<endl;
            sensor *ptr = invRef ->getSensor();
            for(int e = 0; e < 3; e++){
                cout << "sensor" << ' ' << ptr ->getType()<< ' ' <<endl;
                ptr++;
            }
            cout << "owner" << ' ' << invRef ->getOwner()<< endl <<endl<<endl;
            invRef++;

    }
    fileIn.close();
}