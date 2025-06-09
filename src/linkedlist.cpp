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

bool LL::find(const Data& data) const
{
    for (Node* curr{head}; curr != nullptr; curr = curr->next) {
        if (equals(curr->data, data))
            return true;
    }

    return false; 
}

unsigned int LL::getLength() const
{
    return length;
}

bool LL::equals(const Data& d1, const Data& d2) const
{
    return d1.username == d2.username && d1.password == d2.password;
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
