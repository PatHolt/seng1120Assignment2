// -------------------------------------------------
// LinkedList.h
// -------------------------------------------------
// This .h file defines what is needed for the
// LinkedListDemo.cpp file. This is used in conjunction
// Node.h and Node.cpp to form a linked list
// -------------------------------------------------
// Written by Patrick Holt
// Last update: 29/09/2022
// -------------------------------------------------

#ifndef PATRICK_LINKEDLIST
#define PATRICK_LINKEDLIST
#include <iostream>//For cout
#include <assert.h>//For assert() function
#include "Node.h"
using namespace std;

template <typename T>
class LinkedList
{
    //Public member functions
    public:
        //Constructors
        //Pre: None
        //Post: Constructs a LinkedList object by setting pointers to nullptr
        LinkedList();

        //Deconstructor
        //Pre: None
        //Post: Deconstructs a LinkedList object by calling clear()
        ~LinkedList();

        //Setter functions
        //Pre: Requires a T data type as an argument when called
        //Post: Adds a node as the first node, or replaces the old tail node
        void addToHead (const T newHead); 

        //Pre: Requires a T data type as an argument when called
        //Post: Adds a node as the first node, or replaces the old head node
        void addToTail (const T newTail);

        //Pre: Requires a T data type as an argument when called
        //Post: Adds a node as the first node, or replaces the old current node
        void addToCurrent (const T newCurrent);

        //Getter functions
        //Pre: None
        //Post: Returns T data type reference from the head node
        T& getFromHead() const;

        //Pre: None
        //Post: Returns T data type reference from the tail node
        T& getFromTail() const;

        //Pre: None
        //Post: Returns T data type reference from the current node
        T& getFromCurrent() const;

        //Remover functions
        //Pre: None
        //Post: Removes the head node from the linked list and sets the new head, if any
        void deleteHead();

        //Pre: None
        //Post: Removes the tail node from the linked list and sets the new tail, if any
        void deleteTail();

        //Pre: None
        //Post: Removes the node on the current pointer from the linked list and replaces the neighbour nodes next/prev pointers, if any
        void deleteCurrent();

        //Pre: None
        //Post: Clears a linked list of all nodes
        void clear();

        //Current pointer functions
        //Pre: None
        //Post: Moves pointer to the head
        void start();

        //Pre: None
        //Post: Moves pointer to the tail
        void end();

        //Pre: None
        //Post: Moves the pointer to the next node
        void forward();

        //Pre: None
        //Post: Moves the pointer to the previous node
        void back();

    //Private member variables
    private:
        Node<T> *head;
        Node<T> *tail;
        Node<T> *current;
};

//Constructors
template <typename T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    current = nullptr;
};//End Constructor

//Deconstructor
template <typename T>
LinkedList<T>::~LinkedList()
{
    clear();//Calls clear as it clears the LinkedList and prepares deconstructor for destruction
};//End Deconstructor

//Setter functions
template <typename T>
void LinkedList<T>::addToHead(const T newHead)
{
    Node<T> *newHeadNode = new Node(newHead);

    if(head == nullptr)//If head is null/[True] the list is empty and newCurrent is the first node
    {
        head = newHeadNode;
        tail = newHeadNode;
        current = newHeadNode;
    }//End if
    else//Otherwise newHead replaces the old Head node
    {
        head->setPrev(newHeadNode);
        newHeadNode->setNext(head);
        head = newHeadNode;
    }//End else
};//End addToHead

template <typename T>       
void LinkedList<T>::addToTail (const T newTail)
{
    Node<T> *newTailNode = new Node(newTail);

     if(tail == nullptr)//If tail is null/[True] the list is empty and newCurrent is the first node
    {
        head = newTailNode;
        tail = newTailNode;
        current = newTailNode;
    }//End if
    else//Otherwise newTail replaces the old tail node
    {
        tail->setNext(newTailNode);
        newTailNode->setPrev(tail);
        tail = newTailNode;
    }//End else

};//End addToTail

template <typename T>
void LinkedList<T>::addToCurrent (const T newCurrent)
{
    Node<T> *newCurrentNode = new Node<T>(newCurrent);
    
    if(head == nullptr)//If head is null/[True] the list is empty and newCurrent is the first node
    {
        head = newCurrentNode;
        tail = newCurrentNode;
        current = newCurrentNode;
    }//End if
    else if(current == head)//If current is head/[True] copy addToHead function's else{}
    {
        head->setPrev(newCurrentNode);
        newCurrentNode->setNext(head);
        head = newCurrentNode;
    }//End if else
    else if(current == tail)//If current is tail/[True] copy addToTail function's else{}
    {
        tail->setNext(newCurrentNode);
        newCurrentNode->setPrev(tail);
        tail = newCurrentNode;
    }//End if else
    else//Otherwise newCurrent replaces the old current node
    {
        newCurrentNode->setNext(current);
        newCurrentNode->setPrev(current->getPrev());
        current->setPrev(newCurrentNode);
        newCurrentNode->getPrev()->setNext(newCurrentNode);
        current = newCurrentNode;
    }//End else

};//End addToCurrent

//Getter functions
template <typename T>
T& LinkedList<T>::getFromHead() const
{
    return(head->getData());//Returns T data type reference
};//End getFromHead

template <typename T>
T& LinkedList<T>::getFromTail() const
{
    return(tail->getData());//Returns T data type reference
};//End getFromTail

template <typename T>
T& LinkedList<T>::getFromCurrent() const
{
    return(current->getData());//Returns T data type reference
};//End getFromCurrent

//Remove functions
template <typename T>
void LinkedList<T>::deleteHead()
{
    assert(head != nullptr);//Terminates if head is nullptr

    Node<T> *tempHeadNode = head;//Temporary pointer to help with deletion
    if(head->getNext() != nullptr)//If next node isn't nullptr/[True] then proceed with deleting node and replacing it with the next node
    {
        tempHeadNode = head;
        head = head->getNext();
        head->setPrev(nullptr);
    }//End if
    else//Otherwise head is the last node and must be treated as such
    {
        head = nullptr;
        tail = nullptr;
        current = nullptr;
    }//End else

    delete(tempHeadNode);//Deletes pointer and accompanying node
};//End deleteHead

template <typename T>
void LinkedList<T>::deleteTail()
{
    assert(tail != nullptr);//Terminates if tail is nullptr

    Node<T> *tempTailNode = tail;//Temporary pointer to help with deletion
    if(tail->getPrev() != nullptr)//If prev node isn't nullptr/[True] then proceed with deleting node and replacing it with the previous node
    {
        tempTailNode = tail;
        tail = tail->getPrev();
        tail->setNext(nullptr);
    }//End if
    else//Otherwise tail is the last node and must be treated as such
    {
        head = nullptr;
        tail = nullptr;
        current = nullptr;
    }//End else

    delete(tempTailNode);//Deletes pointer and accompanying node
};//End deleteTail

template <typename T>
void LinkedList<T>::deleteCurrent()
{
    assert(current != nullptr);//Terminates if current is nullptr

    Node<T> *tempCurrentNode = current;//Temporary pointer to help with deletion
    if(current->getNext() != nullptr)//If next node isn't nullptr/[True] then proceed with deleting node and replacing it with the next node
    {
        tempCurrentNode = current;
        current = current->getNext();
        current->setPrev(nullptr);
    }//End if
    else if(current->getPrev != nullptr)//If prev node isn't nullptr/[True] then proceed with deleting node and replacing it with the previous node
    {
        tempCurrentNode = current;
        current = current->getPrev();
        current->setNext(nullptr);
    }//End else if
    else//Otherwise tail is the last node and must be treated as such
    {
        head = nullptr;
        tail = nullptr;
        current = nullptr;
    }//End else

    delete(tempCurrentNode);//Deletes pointer and accompanying node
};//End deleteCurrent

template <typename T>
void LinkedList<T>::clear()
{
    Node<T> *tempNode;//Temporary pointer to help with deletion

    while(head != nullptr)//Starts if head isn't a nullptr & ends when head becomes a nullptr
    {
        tempNode = head;
        head = head->getNext();
        delete(tempNode);
    }//End while

    tail = nullptr;
    current = nullptr;
};//End clear

//Pointer functions
template <typename T>
void LinkedList<T>::start()
{
    current = head;//Moves current to the head node
};//End start

template <typename T>
void LinkedList<T>::end()
{
    current = tail;//Moves current to the tail node
};//End end

template <typename T>
void LinkedList<T>::forward()
{
    current = current->getNext();//Moves current to the previous node
};//End forward

template <typename T>
void LinkedList<T>::back()
{
    current = current->getPrev();//Moves current to the previous node
};//End back

#endif