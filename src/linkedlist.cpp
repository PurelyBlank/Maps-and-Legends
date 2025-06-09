#include <iostream>

#include "linkedlist.hpp"

typedef LinkedList LL;


LL::LinkedList()
    :head{ nullptr }, length{ 0 }
{
}

// copy-constructor


void LL::insert(const Data& data)
{
    head = new Node(data, head);
    ++length;
}

unsigned int LL::getLength() const
{
    return length;
}

void LL::deleteList()
{
    Node* curr{ head };
    while (curr != nullptr) {
        Node* temp{ curr->next };
        delete curr;
        curr = temp;
    }
}

LL::~LinkedList()
{
    deleteList();
}
