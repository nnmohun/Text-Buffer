#ifndef BUFFER_H
#define BUFFER_H

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Buffer
{
    public:

        //accessor functions

        void setTextArray(char *t, int size); //initializes the text array to hell world 

        void setNumArray(int i); //sets the pointer array numArray to 13

        //append function adds new string to end of char text array 
        void append();
        void insert(); //at a specific index, insert user string
        void deleteArray();

        void displayInitial(); //prints text
        void printNumArray();
        void printCursor(int cursorSize);//prints new cursor location inside append/insert/delete function

        //constructors
        Buffer();
        Buffer(char *p,int *n, int i, int size, int c);
        //destructor
        ~Buffer();



    private:
        //index for char dynamic arrary is the cursor+1
        int index;

        char *text; //the pointer for the text array
        
        int *numArray;//uses the index to print the number index to count characters and spaces 

        int sizeOfText; //size of the text dynamic array starts at 13
        
        int cursor; //cursor is always sizeOfText -1

};



#endif //BUFFER_H

