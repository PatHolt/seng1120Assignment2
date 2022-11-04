// -------------------------------------------------
// LQueue.h
// -------------------------------------------------
// This .h file defines what is needed for the
// LinkedListDemo.cpp file. This is used in conjunction
// Node.h and Node.cpp to form a LQueue
// -------------------------------------------------
// Written by Patrick Holt
// Last update: 29/09/2022
// -------------------------------------------------

#ifndef PATRICK_LQUEUE
#define PATRICK_LQUEUE
#include <iostream>//For cout
#include <assert.h>//For assert() function
#include <cstddef>//For nullptr
#include "LinkedList.h"//Allows the use of LinkedList functions, etc.
using namespace std;//For lots of stuff ;)

template <typename T>
class LQueue
{
    //Public member functions
    public:
        //Constructors
        //Pre: None
        //Post: Constructs a LQueue object by queueList and queueSize
        LQueue();

        //Deconstructor
        //Pre: None
        //Post: Deconstructs a LQueue object by setting queueList to nullptr and deleting and setting queueSize to 0
        ~LQueue();

        //Setter functions
        //Pre: Requires a T data type reference as an argument when called
        //Post: Places the T data type reference at the back of the queue (get in line mate)
        void enqueue(const T& newQueue);

        //Getter functions
        //Pre: None
        //Post: Returns the T data Type reference from the front of the queue (head node)
        T& front() const;

        //Pre: None
        //Post: Returns the queueSize
        int getQueueSize() const;

        //Pre: None
        //Post: Returns true if LQueue is empty, false if not empty
        bool isEmpty() const;

        //Remover functions
        //Pre: None
        //Post: Returns the head node's T value type and deletes the node from the queue
        T dequeue();
        
    //Private member variables
    private:
        LinkedList<T> *queueList;
        int queueSize;
};

template <typename T>
ostream& operator<<(ostream& out, LQueue<T>& myQueue)
{
    assert(! myQueue.isEmpty());

    LQueue<T>* tempQueue = new LQueue<T>();
    while(! myQueue.isEmpty()) //Adds ouput from top of myQueue, pops top of myQueue into tempQueue, and repeats until emptied
    {
        out << myQueue.front() << endl;
        tempQueue->enqueue(myQueue.dequeue());
    }//End for loop
    while(! tempQueue->isEmpty()) //Moves all data back into myQueue
    {
        myQueue.enqueue(tempQueue->dequeue());
    }//End for loop
    if(tempQueue->isEmpty())
    {
        tempQueue = nullptr;//Sets pointer to nullptr for deletion
        delete tempQueue;//Deletes pointer
    }//End if
    return out; //Returns output of all Queue data
};//End Overloader


//Constructors
template <typename T>
LQueue<T>::LQueue()
{
    queueList = new LinkedList<T>();
    queueSize = 0;
};//End Constructor

template <typename T>
//Deconstructor
LQueue<T>::~LQueue()
{
    queueSize = 0;
    queueList->clear();
    queueList = nullptr;
    delete(queueList);
};//End Deconstructor

//Setter functions
template <typename T>
void LQueue<T>::enqueue(const T& newQueue)
{
    queueList->addToTail(newQueue);//Adds newQueue T data type reference to tail
    queueSize++;//Increment
};//End enqueue

//Getter functions
template <typename T>
T& LQueue<T>::front() const
{
    return(queueList->getFromHead());//Returns head node
};//End front

template <typename T>
int LQueue<T>::getQueueSize() const
{
    return(queueSize);//Returns queueSize
}

template <typename T>
bool LQueue<T>::isEmpty() const
{
    return(getQueueSize() == 0);//True if queueSize is 0, false if queueSize is more than 0
};//End isEmpty

//Remover functions
template <typename T>
T LQueue<T>::dequeue()
{
    T value = queueList->getFromHead();//Creates
    queueList->deleteHead();//Deletes node from the front of the Queue
    queueSize--;
    return(value);//Returns the value held in the deleted node
};//End dequeue
#endif
