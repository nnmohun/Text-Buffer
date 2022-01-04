#include <iostream>
#include <cstring>
#include <string>


#include "Buffer.h"


using namespace std;


Buffer::Buffer()
{
    index=0;
    sizeOfText=0;
    cursor=0;
}
       
Buffer::Buffer(char *p, int *n,int i, int size, int c)
{
    text = p;
    numArray=n;

    index=i;
    sizeOfText=size;
    cursor=c;
}


Buffer::~Buffer()
{
    //deletes the private pointer text pointing to the buffer char array
    delete [] text;
}

void Buffer::setNumArray(int i)
{
  
    i=13;
    index=i;
    int fill=0;

    

    numArray= new int[index];

    cout<<"\n\nCursor: "<<index-1<<endl;
    cout<<"Size: "<<index<<endl;

    for(int i=0; i<index;i++)
    {
        
        numArray[i]=fill;
        fill++;
    }

    for(int i=0; i<index;i++)
    {
        cout<<' ';
        cout<<numArray[i];
        cout<<"|";
    }
    cout<<endl;
}

void Buffer::setTextArray(char *t, int size)
{
    //call set number array function to print the integer array
    
    int i;
    setNumArray(i);
    
    size =13;
    sizeOfText = size;

    text =t;

    

    string hello = "Hello World!";

    //turn string hello into the text array via str copy

    int len = hello.length();

    text = new char[sizeOfText];

    strcpy(text, hello.c_str());

    //text now is a char array = Hello World!
    
}




void Buffer::displayInitial()
{
    int counter=0;
    for(int i=0; i<sizeOfText ; i++)
    {
        cout<<" ";
        counter++;
        if(i>=10)
        {
            cout<<' ';
            counter++;
            
        }
        cout<<text[i];
        
        counter++;
        cout<<"|";
        counter++;
    }
    
    cursor=0;
    cursor = counter-1;

    char cursorArray[cursor];
    
    cursorArray[cursor]='^';
    
    cout<<endl;
    
    for(int i=0; i<cursor-1;i++)
    {
        cout<<' ';
       
    }
    cout<<cursorArray[cursor];
}
void Buffer::printNumArray()
{
    //make new dynamic number array with size sizeOfText
    numArray= new int[sizeOfText];
    index=sizeOfText;
    cout<<"\nCursor: "<<index-1<<endl;
    cout<<"Size: "<<index<<endl;

    int fill=0;
    for(int i=0; i<index;i++)
    {
        
        numArray[i]=fill;
        fill++;
    }

    for(int i=0; i<index;i++)
    {
        cout<<' ';
        cout<<numArray[i];
        cout<<"|";
    }
    cout<<endl;



}
void Buffer::printCursor(int cursorSize)
{
    char *cursorArray;
    cursorArray= new char[cursorSize];
    
    
    cout<<endl;
    cursorArray[cursorSize]='^';
    
    for(int i=0; i<cursorSize-1;i++)
    {
        cout<<' ';
        
    }
    cout<<cursorArray[cursorSize];
}
void Buffer::append()
{
    
    string user;
    //ask user to enter new string
    cout<<"\nEnter text to append: ";
    cin.ignore();
    getline(cin, user);

    //convert user string into char array
    int userLen=user.length();
    int total = userLen;

    //create char array for the user string
    char userArray[userLen+1];
    //copy user string to char array
    strcpy(userArray, user.c_str());

    //create temp dynamic buffer array -- size of text + string length of user
    char *temp;
    temp = new char[sizeOfText+total];

    //update size of text 
    //private member
    //13 + user added text
    sizeOfText = sizeOfText+total;

    //copy text array into temp array
    //hello world into the temp
    strcpy(temp, text);


    //now str concatenate the user char array and temp array 
    //temp has hello world only
    //concat temp (hello world) + user input
    strcat(temp,userArray);

    //reupdate the private text pointer 
    text = new char[sizeOfText];
    strcpy(text, temp);

    cout<<endl;
    printNumArray();

    int counter=0;
    for(int i=0; i<sizeOfText ; i++)
    {
        cout<<" ";
        counter++;
        if(i>=10)
        {
            cout<<' ';
            counter++;
            
        }
        cout<<text[i];
        
        counter++;
        cout<<"|";
        counter++;
    }
    
    cursor=0;
    cursor = counter-1;

    printCursor(cursor);
    
    
}
void Buffer::insert()
{
    //privates transferred over safely //

    int insertPoint;
    string userInsert;

    //ask user for cursor index to insert
    //cursor -1 = index
    cout<<"\nEnter the cursor number to insert new words: "<<endl;
    cin>>insertPoint;

    //subtract one to have it be a valid index point for the char text array
    insertPoint = insertPoint -1;

    cin.ignore();
    //ask user to enter insert string
    cout<<"\nEnter the words to insert at "<<endl;
    getline(cin, userInsert);

    int userLength = userInsert.length();


    string convertedText="";
    //convert text array to string
    for(int i=0; i<sizeOfText; i++)
    {
        convertedText= convertedText + text[i];//hello world in it
    }
    //sizeoftext = helloworld + appended length

    //use string.insert(index,string)
    convertedText.insert(insertPoint+1, userInsert);

    //convert the new string to char array 
    //total length = user entry + null character
    
    int totalLen =convertedText.length();
    

    //local need rename as temp 
    //temp array size of the user insert wording
    char *temp;
    temp = new char[totalLen];

    //update private member length of text char array size of text
    sizeOfText = totalLen;

    

    strcpy(temp,convertedText.c_str()); 

    text = new char[sizeOfText];
    strcpy(text, temp);
    
    cout<<endl;
    printNumArray();


    int counter=0;
    for(int i=0; i<sizeOfText ; i++)
    {
        cout<<" ";
        counter++;
        if(i>=10)
        {
            cout<<' ';
            counter++;
            
        }
        cout<<text[i];
        
        counter++;
        cout<<"|";
        counter++;
    }
    
    cursor=0;
    cursor = counter-1;

    printCursor(cursor);
    

    
}

void Buffer::deleteArray()
{
    //test to make sure private text i has = hello world + inserted text + append text 
    string convertedText="";
    //convert text array to string converted text

    for(int i=0; i<sizeOfText; i++)
    {
        convertedText= convertedText + text[i];//hello world in it
    }

    //converted private text now is convertedText
    //cout<<"\n"<<convertedText<<endl;

    int deletionCursor=0;
    int numDeleted=0;
    
    //ask to insert point index from 
    cout<<"\nEnter the cursor number place you would like to start deleting: ";
    cin>>deletionCursor;
    cout<<endl;

    //ask int to delete amount of characters, n 
    cout<<"Enter the number of characters you would like to delete: ";
    cin>>numDeleted;
    cout<<endl;

    
    //have safeguard size be sizeof text -1 to save null character
    
    int safeGuard = sizeOfText-1;
   

    
    int deletionPlusNum = deletionCursor + numDeleted;

    if(numDeleted<=(sizeOfText) &&(deletionPlusNum<=sizeOfText-1))
    {
        convertedText.erase(deletionCursor,numDeleted);
    }
    else
    {
        cout<<"\nNot enough characters to delete.\nYou can only delete: "<<(sizeOfText-deletionCursor-1)<<" number of characters."
            <<"\nPlease enter a new number to you would like to delete that is less than or equal to "<<(sizeOfText-deletionCursor-1)<< ": ";
        cin>>numDeleted;
        convertedText.erase(deletionCursor,numDeleted);
        cout<<endl;
    }

    //statement telling the user to select a new feature size too small to delete
    if(sizeOfText==1)
    {
        cout<<"\nYou cannot delete anymore characters. Please select a new option below.\n";
    }

    
    
    //cout<<"\n"<<convertedText<<endl;works

    //convert back to text char array 
    //converted text now has the deltion included 
    int totalLen =convertedText.length();
    
    //temp array size of the user insert and deletion wording
    char *temp;
    temp = new char[totalLen];

    //update private member length of text char array size of text
    sizeOfText = totalLen;

    

    strcpy(temp,convertedText.c_str()); 

    //make new dynamic array to include the deletion change of size
    text = new char[sizeOfText];

    //copy temp which holds the deleted string into private text 
    strcpy(text, temp);

    cout<<endl;
    printNumArray();
    
    int counter=0;
    for(int i=0; i<sizeOfText ; i++)
    {
        cout<<" ";
        counter++;
        if(i>=10)
        {
            cout<<' ';
            counter++;
            
        }
        cout<<text[i];
        
        counter++;
        cout<<"|";
        counter++;
    }
    
    cursor=0;

    //update cursor number
    cursor = counter-1;

    printCursor(cursor);


    

}