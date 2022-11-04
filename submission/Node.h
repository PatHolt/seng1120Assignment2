// -------------------------------------------------
// Node.h
// -------------------------------------------------
// This .h file defines what is needed for the
// Node.cpp file. This is used in conjunction with
// LinkedList.h and LinkedList.cpp to form a linked
// list
// -------------------------------------------------
// Written by Patrick Holt
// Last update: 29/09/2022
// -------------------------------------------------

#ifndef PATRICK_NODE
#define PATRICK_NODE
#include <cstddef>//For nullptr & NULL
using namespace std;//For a lil bit of everything

template <typename T>
class Node
{
    //Public Members
    public:

        //Constructors
        //Pre: None
        //Post: Constructs a node object and sets private members to NULL/nullptr
        Node();

        //Pre:  Requires a T data type reference as a parameter
        //Post: Creates a node object and sets data as given student data object
        Node(const T& object);

        //Deconstructor
        //Pre: None
        //Post: Deconstructs a node object by setting pointers to nullptr and deleting them
        ~Node();

        //Getters
        //Pre: Requires a templated node as a parameter
        //Post: Sets next as the given node
        void setNext(Node<T>* nextNode);

        //Pre: Requires a templated node as a parameter
        //Post: Sets prev as the given node
        void setPrev(Node<T>* prevNode);

        //Pre: Requires a T data type reference as a parameter
        //Post: Sets data as the given T data type reference
        void setData(T& dataObject);

        //Setters
        //Pre: None
        //Post: Returns the next node pointer in the linked list
        Node<T>* getNext() const;
        
        //Pre: None
        //Post: Returns the previous node pointer in the linked list
        Node<T>* getPrev() const;

        //Pre: None
        //Post: Returns T data type reference
        T& getData();

    //Private Members   
    private:
        T data;
        Node<T> *next;
        Node<T> *prev;

};

//Constructors
template <class T>
Node<T>::Node()
{
    data = NULL;//Sets data as NULL until otherwise changed
    next = nullptr;//Sets next to nullptr until otherwise changes
    prev = nullptr;//Sets prev to nullptr until otherwise changes
};//End Constructor

template <class T>
Node<T>::Node(const T& object)
{
    data = object;//Sets object parameter as the node's data
    next = nullptr;//Sets next to nullptr until otherwise changes
    prev = nullptr;//Sets prev to nullptr until otherwise changes
};//End Constructor w/ object parameter

//Deconstructor
template <typename T>
Node<T>::~Node()
{
    next = nullptr;//Sets next pointer to nullptr so it can be deleted
    prev = nullptr;//Sets prev pointer to nullptr so it can be deleted
    delete(next);//Deletes next pointer
    delete(prev);//Deletes prev pointer
};//End Deconstructor

//Getters
template <typename T>
void Node<T>::setNext(Node* nextNode)
{
    next = nextNode;//Sets next pointer to parameter node
};//End setNext

template <typename T>
void Node<T>::setPrev(Node* prevNode)
{
    prev = prevNode;//Sets prev pointer to parameter node
};//End setPrev

template <typename T>
void Node<T>::setData(T& dataObject)
{
    data = dataObject;//Sets data to parameter node
};//End setData

//Setters
template <typename T>
Node<T>* Node<T>::getNext() const
{
    return(next);//Returns next pointer
};//End getNext

template <typename T>
Node<T>* Node<T>::getPrev() const
{
    return(prev);//Returns prev pointer
};//End getPrev

template <typename T>
T& Node<T>::getData()
{
    return(data);//Returns the data from the node
};//End getData

#endif