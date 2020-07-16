#include <iostream>
#include <cstring>
#include "ArrayList.h"
#include "NodeList.h"

using namespace std;
//Issues: fails when the value looked for is not found, known problem area is the insert before and after functions

int main(){
    DataType testVal1(50, 75.00);
    DataType testVal2(25, 100.00);
    cout<< "============================================"<< endl <<
    "Testing all properties of ArrayList & NodeList Classes:" << endl;

    //Default
    cout << endl << "============================================" << endl;
    cout << "Testing Default Constructors" << endl;
    ArrayList ALDefault;
    NodeList NLDefault;

    //Paramertarized
    cout << endl << "============================================" << endl;
    cout << "Testing Parameterized Constructors" << endl;
    ArrayList ALP(5,testVal1);
    NodeList NLP(10, testVal2);

    //Copy
    cout << endl << "============================================" << endl;
    cout << "Testing Copy Constructors" << endl;
    ArrayList ALC(ALP);
    NodeList NLC(NLP);

    //Deconstructor
    cout << endl << "============================================" << endl;
    cout << "Testing Deconstructors" << endl;
    DataType nullSet(0,0.0);
    ArrayList *ALptr = new ArrayList(10, nullSet);
    NodeList *NLptr = new NodeList(10,nullSet);
    delete ALptr;
    ALptr = NULL;
    delete NLptr;
    NLptr = NULL;

    //Assignment Operators
    cout << endl << "============================================" << endl;
    cout << "Testing Assignment Operators" << endl;
    DataType testVal3(2, 2.0), testVal4(35,62.3), testVal5(45, 64.5);
    ArrayList assignAL1(8, testVal3);
    assignAL1 = ArrayList(8, testVal4);
    cout << assignAL1 << endl;
    ArrayList assignAL2(8, testVal4);
    cout << assignAL2 << endl;

    NodeList assignNL1(8, testVal5);
    assignNL1 = NodeList(8,testVal3);
    cout << assignNL1 << endl;
    NodeList assignNL2(8, testVal3);
    cout << assignNL2 << endl;

    //Front and Back Functions
    cout << endl << "============================================" << endl;
    cout << "Testing Front and Back Functions" << endl;
    ArrayList first(assignAL1), last(assignAL1);
    DataType *frontPtr = first.front();
    DataType *backPtr = last.back();
    cout << "Array List Front: " << *frontPtr << endl;
    cout << "Array List Back: " << *backPtr << endl;

    NodeList nlFirst(assignNL1), nlLast(assignNL1);
    Node *nlFrontPtr = nlFirst.front();
    Node *nlLastPtr = nlLast.back();
    cout << "Node List Front: ";
    if(nlFrontPtr != NULL){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    cout << "Node List Back: ";
    if(nlLastPtr != NULL){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }

    //Find Functions
    cout << endl << "============================================" << endl;
    cout << "Testing Find Function" << endl;
    DataType *ALPrevious = NULL;
    DataType *ALFind = assignAL1.find(testVal4, ALPrevious);
    cout << "Array List: " << *ALFind << endl;
    Node *NLPrevious = NULL;
    Node *NLFind = assignNL1.find(testVal3, NLPrevious);
    cout << "Node List: ";
    if(NLFind != NULL){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }

    //Insert Functions
    cout << "============================================" << endl;
    cout << "Testing Insert Function" << endl; // see top
    DataType *BInsert = assignAL1.insertBefore(testVal4, testVal5);
    cout << "Array List before: " << *BInsert << endl;
    DataType *AInsert = assignAL1.insertAfter(testVal4, testVal5);
    cout << "Array List after: " << *AInsert << endl;
    cout << endl << "Node Inserts: Before then After" << endl;
    Node *NLBInsert = assignNL1.insertBefore(testVal3, testVal5);
    Node *NLAInsert = assignNL1.insertAfter(testVal3, testVal5);
    cout << "Node List before: ";
    if(NLBInsert != NULL){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    cout << "Node List after: ";
    if(NLAInsert != NULL){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }

    cout << endl << "Testing Indexing Operators:" << endl;
    cout << "Array List: " << assignAL1[3] << endl;
    cout << "Array List: " << assignNL1[3] << endl;
    
    cout << endl << "Testing Size Functions:" << endl;
    cout << "Array List: " << assignAL1.size() << endl;
    cout << "Node List: " << assignNL1.size() << endl;

    cout << endl << "Testing Clear Functions:" << endl;
    assignAL1.clear();
    assignNL1.clear();
    cout << "Array List: " << boolalpha << assignAL1.empty() << endl;
    cout << "Node List: " << boolalpha << assignNL1.empty() << endl;

    cout << "=====================================================" << endl;
    cout << "All tests complete, you may now go to bed, good job :)" << endl;
    return 0;

}