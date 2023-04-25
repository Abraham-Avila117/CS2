//
//
//  InfixPostfix
//
//  Created by Antoun, Sherine on 11/11/21.
//  Copyright © 2021 Antoun, Sherine. All rights reserved.
//  Header file: myStack.h
// exception handling done by Abraham Avila

#ifndef H_StackType
#define H_StackType

#include <iostream>
#include <fstream>
#include <cassert>
#include <stdexcept>
#include <chrono>

#include "stackADT.h"

using namespace std;
using namespace chrono;

static auto start = high_resolution_clock::now();

template <class Type>
class stackType: public stackADT<Type>
{
public:
    const stackType<Type>& operator=(const stackType<Type>&);
      //Overload the assignment operator.

    void initializeStack();
      //Function to initialize the stack to an empty state.
      //Postcondition: stackTop = 0

    bool isEmptyStack() const;
      //Function to determine whether the stack is empty.
      //Postcondition: Returns true if the stack is empty,
      //               otherwise returns false.

    bool isFullStack() const;
      //Function to determine whether the stack is full.
      //Postcondition: Returns true if the stack is full,
      //               otherwise returns false.

    void push(const Type& newItem);
      //Function to add newItem to the stack.
      //Precondition: The stack exists and is not full.
      //Postcondition: The stack is changed and newItem
      //               is added to the top of the stack.

    Type top() const;
      //Function to return the top element of the stack.
      //Precondition: The stack exists and is not empty.
      //Postcondition: If the stack is empty, the program
      //               terminates; otherwise, the top element
      //               of the stack is returned.

    void pop();
      //Function to remove the top element of the stack.
      //Precondition: The stack exists and is not empty.
      //Postcondition: The stack is changed and the top
      //               element is removed from the stack.

    stackType(int stackSize = 100);
      //constructor
      //Create an array of the size stackSize to hold
      //the stack elements. The default stack size is 100.
      //Postcondition: The variable list contains the base
      //               address of the array, stackTop = 0, and
      //               maxStackSize = stackSize.

    stackType(const stackType<Type>& otherStack);
      //copy constructor

    ~stackType();
      //destructor
      //Remove all the elements from the stack.
      //Postcondition: The array (list) holding the stack
      //               elements is deleted.

private:
    int maxStackSize; //variable to store the maximum stack size
    int stackTop;     //variable to point to the top of the stack
    Type *list;       //pointer to the array that holds the
                      //stack elements

    void copyStack(const stackType<Type>& otherStack);
      //Function to make a copy of otherStack.
      //Postcondition: A copy of otherStack is created and
      //               assigned to this stack.
};


template <class Type>
void stackType<Type>::initializeStack()
{
    stackTop = 0;
}//end initializeStack

template <class Type>
bool stackType<Type>::isEmptyStack() const
{
    return(stackTop == 0);
}//end isEmptyStack

template <class Type>
bool stackType<Type>::isFullStack() const
{
    return(stackTop == maxStackSize);
} //end isFullStack

template <class Type>
void stackType<Type>::push(const Type& newItem)
{
    if (!isFullStack())
    {
        list[stackTop] = newItem;   //add newItem to the
                                    //top of the stack
        stackTop++; //increment stackTop
    }
    else
        cout << "Cannot add to a full stack." << endl;
}//end push

template <class Type>
Type stackType<Type>::top() const
{
    assert(stackTop != 0);          //if stack is empty,
                                    //terminate the program
    return list[stackTop - 1];      //return the element of the
                                    //stack indicated by
                                    //stackTop - 1
}//end top

template <class Type>
void stackType<Type>::pop()
{
    if (!isEmptyStack())
        stackTop--;                 //decrement stackTop
    else
        cout << "Cannot remove from an empty stack." << endl;
}//end pop

template <class Type>
stackType<Type>::stackType(int stackSize)
{
    if (stackSize <= 0)
    {
        cout << "Size of the array to hold the stack must "
             << "be positive." << endl;
        cout << "Creating an array of size 100." << endl;

        maxStackSize = 100;
    }
    else
        maxStackSize = stackSize;   //set the stack size to
                                    //the value specified by
                                    //the parameter stackSize

    stackTop = 0;                   //set stackTop to 0
                                    //create the array to
                                    //hold the stack elements
    try{
      list = new Type[maxStackSize];
    }
    catch(bad_alloc& ba){
        ofstream output_error;
        output_error.open("run_log.txt", ios::out);
        streambuf* stream_buffer_cerr = cerr.rdbuf();
        streambuf* stream_buffer_output_error = output_error.rdbuf();
        cerr.rdbuf(stream_buffer_output_error);
        cerr << "Exception thrown: " << ba.what() << endl;
        cerr << "Memory could not be allocated in constructor. Result: Program Termination" << endl;
        auto finish = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(finish - start);
        cerr << "Run time was: " << duration.count() << "ms" << endl;
        cerr.rdbuf(stream_buffer_cerr);
        throw;
    }
    catch(...){
        delete [] list;
        exit(1);
    }
}//end constructor

template <class Type>
stackType<Type>::~stackType() //destructor
{
    delete [] list; //deallocate the memory occupied
                    //by the array
}//end destructor

template <class Type>
void stackType<Type>::copyStack(const stackType<Type>& otherStack)
{
    delete [] list;
    maxStackSize = otherStack.maxStackSize;
    stackTop = otherStack.stackTop;

    try{
      list = new Type[maxStackSize];
    }
    catch(bad_alloc& ba){
        ofstream output_error;
        output_error.open("run_log.txt", ios::out);
        streambuf* stream_buffer_cerr = cerr.rdbuf();
        streambuf* stream_buffer_output_error = output_error.rdbuf();
        cerr.rdbuf(stream_buffer_output_error);
        cerr << "Exception thrown: " << ba.what() << endl;
        cerr << "Memory could not be allocated in copyStack function. Result: Program Termination" << endl;
        auto finish = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(finish - start);
        cerr << "Run time was: " << duration.count() << "ms" << endl;
        cerr.rdbuf(stream_buffer_cerr);
        throw;
    }
    catch(...){
        delete [] list;
        exit(1);
    }
        //copy otherStack into this stack
    for (int j = 0; j < stackTop; j++)
        list[j] = otherStack.list[j];
} //end copyStack


template <class Type>
stackType<Type>::stackType(const stackType<Type>& otherStack)
{
    list = nullptr;

    copyStack(otherStack);
}//end copy constructor

template <class Type>
const stackType<Type>& stackType<Type>::operator=
   					(const stackType<Type>& otherStack)
{
    if (this != &otherStack) //avoid self-copy
        copyStack(otherStack);

    return *this;
} //end operator=

#endif
