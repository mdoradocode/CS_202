#include <iostream>
#include <vector>
#include <stdio.h>
#include <fstream>
#include "VectorRecursion.h"

using namespace std;

int main(){
    vector<int> vecInt;
    vector<int> vecIntCpy;
    int i = 0;

    ifstream fileIn("RandomData.txt");
    while(i < 100){
        int tempFileIn;
        fileIn >> tempFileIn;
        vecInt.push_back(tempFileIn);
        vecIntCpy.push_back(tempFileIn);
        i++;
    }
    vectorResort(vecInt,0, vecInt.size()-1);

    cout << vectorResearch(vecInt, 0, vecInt.size(), 17) << endl;
    
    for(int i = 0; i < 100; i++){
        cout << vecInt[i] << endl;
    }
    return 0;
}