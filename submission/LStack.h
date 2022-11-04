// -------------------------------------------------
// LStack.h
// -------------------------------------------------
// This .h file defines what is needed for the
// LinkedListDemo.cpp file. This is used in conjunction
// Node.h and Node.cpp to form a LStack
// -------------------------------------------------
// Written by Patrick Holt
// Last update: 29/09/2022
// -------------------------------------------------

#ifndef PATRICK_LSTACK
#define PATRICK_LSTACK
#include <iostream>//For cout
#include <assert.h>//For assert() function
#include <cstddef>//For nullptr
#include "LinkedList.h"//Allows the use of LinkedList functions
using namespace std;//For lots of stuff ;)

template <typename T>
class LStack
{
    //Public member functions
    public:
        //Constructors
        //Pre: None
        //Post: Constructs a LStack object by setting pointers to nullptr
        LStack();

        //Deconstructor
        //Pre: None
        //Post: Deconstructs a LStack object by calling clear(), removing and deleting pointers
        ~LStack();

        //Setter functions
        //Pre: Requires a T data type reference as an argument when called
        //Post: Pushes the T data type reference on top of the stack
        void push(const T& newStack);

        //Getter functions
        //Pre: None
        //Post: Returns a T data type reference from the top of the stack
        T& peek() const;

        //Pre: None
        //Post: Returns size of the stack
        int getStackSize() const;

        //Pre: None
        //Post: Returns true if LStack is empty, false if not empty
        bool isEmpty() const;

        //Remover functions
        //Pre: None
        //Post: Returns the front nodes data and deletes it from the Stack
        T pop();

    //Private member variables
    private:
        LinkedList<T> *stackList;
        int stackSize;
};

//Overloader
template <typename T>
ostream& operator<<(ostream& out, LStack<T>& myStack)
{
    assert(! myStack.isEmpty());

    LStack<T>* tempStack = new LStack<T>();
    while(! myStack.isEmpty()) //Adds ouput from top of myStack, pops top of myStack into tempStack, and repeats until emptied
    {
        out << myStack.peek() << endl;
        tempStack->push(myStack.pop());
    }//End for loop
    while(! tempStack->isEmpty()) //Moves all data back into myStack
    {
        myStack.push(tempStack->pop());
    }//End for loop
    if(tempStack->isEmpty())
    {
        tempStack = nullptr;
        delete tempStack;//Deletes pointer
    }//End if
    return out; //Returns output of all Stack data
};//End Overloader

//Constructors
template <typename T>
LStack<T>::LStack()
{
    stackList = new LinkedList<T>();
    stackSize = 0;
};//End Constructor

//Deconstructor
template <typename T>
LStack<T>::~LStack()
{
    stackSize = 0;
    stackList->clear();
    stackList = nullptr;
    delete(stackList);
};//End Deconstructor

//Setter functions
template <typename T>
void LStack<T>::push(const T& newStack)
{
    stackList->addToHead(newStack);//Adds T data type reference to the top of the stack
    stackSize++;//Increment
};//End push


//Getter functions
template <typename T>
T& LStack<T>::peek() const
{
    return(stackList->getFromHead());//Returns a T data type reference from head node
};//End getFromHead

template <typename T>
int LStack<T>::getStackSize() const
{
    return(stackSize);//Returns stackSize
}

template <typename T>
bool LStack<T>::isEmpty() const
{
    return(getStackSize() == 0);//Returns true if stackSize is 0, false if more than 0
};//End isEmpty

//Remover functions
template <typename T>
T LStack<T>::pop()
{
    T value = stackList->getFromHead();//Grabs value from head node before it is sent to deleteHead()

    stackList->deleteHead();//Deletes node from the top of the LStack
    stackSize--;//Decrement
    return(value);//Returns the value taken from the deleted node
};//End pop

#endif