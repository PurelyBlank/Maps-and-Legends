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

    Node* copy(const LinkedList& ll);
    Node* reverse(Node* node);
    void deleteList() noexcept;

    Node* head;
    unsigned int length;

public:

    // default constructor
    LinkedList() noexcept;

    // copy-constructor
    LinkedList(const LinkedList& ll);

    void insert(const Data& data);
    const Node* find(const Data& data) const;
    bool contains(const Data& data) const;
    void remove(const Data& data);

    unsigned int getLength() const;
    void reverse();

    // assignment operator 
    LinkedList& operator=(const LinkedList& ll);
    bool operator==(const LinkedList& ll) const;

    bool equals(const LinkedList& ll) const;
    bool equals(const Data& d1, const Data& d2) const;
    void print() const;

    std::string toString() const;

    // destructor
    ~LinkedList() noexcept;
};

#endif
