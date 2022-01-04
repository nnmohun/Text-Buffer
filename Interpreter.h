#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

#include "Buffer.h"


class Interpreter
{
    public:
        //menu 
            //calls buffer functions using ->
            void menu();
        
        //constructor
            Interpreter();
            Interpreter(Buffer *bufferPointer);
            //pass in the buffer pointer
            //set the pointer to the buffer privates?
            ~Interpreter();

    private:
        //pointer buffer
        Buffer *b;

};

#endif //INTERPRETER_H