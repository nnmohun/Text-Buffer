#include <iostream>
#include <cstring>
#include <string>

#include "Interpreter.h"

using namespace std;



void Interpreter::menu()
{
    char *array;
    int arraySize=0;
    int cur=0;

    //displays intital array
    b->setTextArray(array, arraySize);
    b->displayInitial();
   

    int user;

    do 
    {
        cout<<"\nEnter the following\n1 to delete\n2 to append text\n3 to insert at position\n0 to Exit\n";
        cin>>user;
        switch(user)
        {
            
            case 1:
                b->deleteArray();
                break;
            case 2:
                b->append();
                break;
            case 3:
                b->insert();
                break;
            default:
                cout<<"Enter 1, 2, 3 or 0\n";
                break;
            case 0:
                cout<<"\nExiting now\n";
                break;
        }
            

        
    }while(user!=0);

    
}


Interpreter::Interpreter()
{
    
    b= new Buffer;

};

Interpreter::Interpreter(Buffer *bufferPointer)
{
    b=bufferPointer;
}

Interpreter::~Interpreter()
{
    delete b;
}