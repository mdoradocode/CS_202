#include <iostream>
#include <fstream>
using namespace std;

#define fileSize 20
#define nameLength 9
#define nameTotal 10
#define bubbleSort 50


void stringCopy(char nameTemp[nameLength], const char source[]);
int stringLength(char name[nameLength]);
int stringCompare(const char name1[nameLength], const char name2[nameLength]);
void nameSwap(char nameList[][nameLength], int place[], int position1, int position2);
void printNames(char nameList[nameTotal][nameLength], int spot[]);
void writeToFile(const char nameList[][nameLength], int spot[], ofstream& fileNameOut);
void lengthSort(char nameList[][nameLength], int spot []);
void alphaSort(char nameList[][nameLength], int spot[]);

int main(){
    char fileNameIn[fileSize], fileNameOut[fileSize];

    char nameList[nameTotal][nameLength];
    int spot[nameTotal] = {1,2,3,4,5,6,7,8,9,10};



    cout << "Enter the input file name: ";
    cin >> fileNameIn;
    cout << "Enter the output file name: ";
    cin >> fileNameOut;
    ofstream writeFile(fileNameOut);
    ifstream readFile;
    readFile.open(fileNameIn);
    for(int i = 0; i <= nameTotal; i++){
        readFile >> nameList[i];
    }
    readFile.close();
    printNames(nameList, spot);


    lengthSort(nameList, spot);
    writeFile << "Names sorted by length:" << endl;
    writeToFile(nameList, spot, writeFile);


    cout << endl;
    printNames(nameList, spot);
    cout << endl;

    alphaSort(nameList, spot);


    printNames(nameList, spot);
    writeFile << "Names sorted alphabetically:" << endl;
    writeToFile(nameList, spot, writeFile);
    cout << endl;
}
void alphaSort(char nameList[][nameLength], int spot[]){
    for(int i = 0; i < nameTotal; i++){
        for(int j = 0; j < nameLength; j++){
            int result = stringCompare(nameList[j+1], nameList[j]);
            if (result == -1){
                nameSwap(nameList, spot, j+1,j);
            }
        }
    }
}

void lengthSort(char nameList[][nameLength], int spot[]){
    for(int i = 0; i < nameTotal; i++){
        for(int j = 0; j < nameLength;j++){
           int size1 = stringLength(nameList[j]);
           int size2 = stringLength(nameList[j+1]);
           if (size2>size1){
               nameSwap(nameList, spot, j, j+1);
            }
        }
    }
}

void writeToFile(const char nameList[][nameLength], int spot[], ofstream& fileNameOut){
    for(int i = 0; i < nameTotal; i++){
        fileNameOut << spot[i] << ')' << nameList[i] << endl;
    }
}

void printNames(char nameList[][nameLength], int spot[]){
    for(int i = 0; i < nameTotal; i++ ){
        cout << spot[i] << ')' <<nameList[i] << endl;
    }
}

void stringCopy(char nameTemp[nameLength], const char source[]){
    int j = 0;
    for(j = 0; source[j] != '\0'; j++){
        nameTemp[j] = source[j];
    }
    nameTemp[j] = '\0';
}

int stringLength(char name[nameLength]){
    int length = 0; 
    for(int i = 0; name[i] != '\0'; i++){
        length++;
    }
    return length;
}
void nameSwap(char nameList[][nameLength], int place[], int position1, int position2){
    char tempName[nameLength];
    int tempPlace;
    stringCopy(tempName, nameList[position1]);
    stringCopy(nameList[position1], nameList[position2]);
    stringCopy(nameList[position2], tempName);
    tempPlace = place[position2];
    place[position2] = place[position1];
    place[position1] = tempPlace;
}

int stringCompare(const char name1[nameLength], const char name2[nameLength]){
    for(int i = 0; (name1[i] != '\0')&&(name2[i]!='\0');i++){
        int alp1 = name1[i];
        int alp2 = name2[i];
        if(alp1 >= 97){
            alp1 = alp1 - 32;
        }
        if(alp2 >= 97){
            alp2 = alp2 - 32;
        }
        if(alp1 > alp2){
            return 1;

        }
        else if (alp1 < alp2){
            return -1;
        }
    }
    return 0;
}

