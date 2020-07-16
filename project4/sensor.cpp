#include "sensor.h"
int sensor:: gpsCnt;
int sensor:: lidarCnt;
int sensor:: radarCnt;
int sensor:: cameraCnt;

char *myStringCopy1(char *destination, const char *source){
    for(; *source != '\0';){
        *destination = *source;
        *destination++;
        *source++;
    }
    *destination = '\0';
    return destination;
}
int myStringCompare1(const char *str1, const char *str2){
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

sensor :: sensor(){
    sensor ::setType(empty);
    sensor ::setExCost();
}

sensor :: sensor(char *type){
    sensor ::setType(type);
    sensor ::setExCost();

}

sensor :: sensor(sensor *copy){
    sensor :: setType(copy->getType());
}

void sensor :: setType(char* type){
    myStringCopy1(m_type, type);
    if(myStringCompare1(type, "lidar") == 0){
        lidarCnt++;
    }
    else if(myStringCompare1(type, "radar") == 0){
        radarCnt++;
    }
    else if (myStringCompare1(type, "gps") == 0){
        gpsCnt++;
    }
    else if (myStringCompare1(type, "camera") == 0){
        cameraCnt++;
    }
}
void sensor :: reset(){
    lidarCnt = 0;
    radarCnt = 0;
    cameraCnt = 0;
    gpsCnt = 0; 
}

void sensor ::setExCost(){
    m_exCost = 0.00;
    if(myStringCompare1(m_type, "lidar") == 0){
        m_exCost = 15.00;
    }
    else if(myStringCompare1(m_type, "radar") == 0){
        m_exCost = 20.00;
    }
    else if (myStringCompare1(m_type, "gps") == 0){
        m_exCost = 5.00;
    }
    else if (myStringCompare1(m_type, "camera") == 0){
        m_exCost = 10.00;
    }
    else if (myStringCompare1(m_type, "EMPTY") == 0){
        m_exCost = 0.00;
    }
}

bool sensor:: operator==(sensor *sensorPtr){
    bool result = 1; 
    char *Stype1 = this ->getType();
    char *Stype2 = sensorPtr ->getType();
    do{
        if(Stype1 != Stype2){
            return 0;
            break;
        }
        Stype1++, Stype2++;
    }while((*Stype1 != '\0')&&(*Stype2 != '\0'));
    return result;
}



float sensor ::getExCost(){
    return m_exCost;
}
char *sensor :: getType(){
    return m_type;
}

int sensor :: getCamera(){
    return cameraCnt;
}

int sensor :: getGps(){
    return gpsCnt;
}

int sensor :: getLidar(){
    return lidarCnt;
}

int sensor :: getRadar(){
    return radarCnt;
}



