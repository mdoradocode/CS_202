#include <iostream>
#include <cstring>
#include "ArrayStack.h"
#include "NodeStack.h"

using namespace std;

int main(){
    cout << "========================================="<< endl;
    cout << "Testing Default Constructors" << endl;
    ArrayStack<int> ASempty;
    NodeStack<int> NSempty;

    cout << "========================================="<< endl;
    cout << "Testing Parameterized Constructors" << endl;
    ArrayStack<int> ASfill(5,1);
    cout << "Parameterized Constructor: ArrayStack " << endl<<  ASfill << endl;
    NodeStack<int> NSfill(14,4);
    cout << "Parameterized Constructor: NodeStack" << endl<< NSfill << endl;

    cout << "========================================="<< endl;
    cout << "Testing Copy Constructors" << endl;
    ArrayStack<int> AScopy(ASfill);
    cout << "Copied ArrayStack from parameterized: " << AScopy << endl;
    NodeStack<int> NScopy(NSfill);
    cout << "Copied NodeStack from parameterized: " <<NScopy << endl;

    cout << "========================================="<< endl;
    cout << "Testing Assignment Operator" << endl;
    ASempty = AScopy;
    cout << "Default ArrayStack after being set to copied: " << ASempty << endl;
    NSempty = NScopy; 
    cout << "Default ArrayStack after being set to the copied: " << NSempty << endl;

    cout << "========================================="<< endl;
    cout << "Testing Top functions" << endl;
    ArrayStack<int> AStop(4, 8);
	NodeStack<int>  NStop(1, 5);
	cout << "\nTop value of stack:\nArrayStack: " << AStop.top() << "\nNodeStack: " << NStop.top() << endl;
    
    cout << "========================================="<< endl;
    cout << "Testing Push functions" << endl;
    AStop.push(7);
    NStop.push(80);
    cout << "\nPush function:\nArrayStack: " << AStop << "NodeStack: "<< NStop << endl;

    cout << "========================================="<< endl;
    cout << "Testing Pop functions" << endl;
    cout << "Old ArrayStack : " << endl << AStop << endl << "Old NodeStack: " << endl << NStop << endl;
    AStop.pop();
    NStop.pop();
    cout << "New ArrayStack: " << endl << AStop << endl << "New NodeStack: " << endl << NStop << endl;

    cout << "========================================="<< endl;
    cout << "Size of ArrayStack: " << AStop.size() << endl << "Size of NodeStack: " << endl << NStop.size() << endl;

    cout << "========================================="<< endl;
    ArrayStack<int> empty;
	NodeStack<int>  notfull;
	
	cout << "\nTesting empty function:\nEmpty ArrayStack: " << boolalpha
			  << empty.empty() << "\nRegular Array Stack: " << boolalpha
			  << AStop.empty() << "\nEmpty NodeStack: " << boolalpha 
			  << notfull.empty() << "\nRegular NodeStack: " << boolalpha
			  << NStop.empty() << std::endl;

    cout << "========================================="<< endl;
    ArrayStack<int> full(999, 1);
	NodeStack<int> neverfull(1001, 2);
	cout << "\nTesting full function:\nFull ArrayStack: " 
			  << boolalpha << full.full() << "\nRegular ArrayStack: " 
			  << boolalpha << AStop.full() << "\nNodeStacks have no limit, "
			  << "NodeStack of size 1001: " << boolalpha 
			  << neverfull.full() << endl;

    cout << "========================================="<< endl;

    cout << "\nClear function:\nFull ArrayStack: ";
	full.clear();
	cout << full << "\nNodeStack: ";
	neverfull.clear();
	cout << neverfull << endl;
	
	//Tests done
	cout << "Tests Done" << endl;
	

	return 0;
	  



}