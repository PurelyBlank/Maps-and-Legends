#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <string>

#include "constants.hpp"


class LinkedList
{
    struct Node
    {
        Data data;
        Node* next;
    };

    Node* head;
    unsigned int length;

public:

    LinkedList();

    // copy-constructor
    LinkedList(const LinkedList& ll);

    void insert(const Data& data);
    bool find(const Data& data);
    void remove(const Data& data);

    unsigned int getLength() const;

    // assignment operator 
    LinkedList& operator=(const LinkedList& ll);
    bool operator==(const LinkedList& ll) const;

    bool contains(const Data& data) const;
    bool equals(const LinkedList& ll) const;
    void print();
    
    // destructor
    ~LinkedList();
};

#endif
