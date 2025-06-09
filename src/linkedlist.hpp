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

        Node(const Data& data, Node* next = nullptr)
            : data{ data }, next{ next }
        {
        }
    };

    void deleteList();

    Node* head;
    unsigned int length;

public:

    // default constructor
    LinkedList();

    // copy-constructor
    LinkedList(const LinkedList& ll);

    void insert(const Data& data);
    bool find(const Data& data) const;
    void remove(const Data& data);

    unsigned int getLength() const;

    // assignment operator 
    LinkedList& operator=(const LinkedList& ll);
    bool operator==(const LinkedList& ll) const;

    bool contains(const Data& data) const;
    bool equals(const LinkedList& ll) const;
    bool equals(const Data& d1, const Data& d2) const;
    void print() const;

    std::string toString() const;

    // destructor
    ~LinkedList();
};

#endif
