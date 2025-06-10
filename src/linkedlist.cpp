#include <iostream>
#include <sstream>

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

// disallow modification of node's internal data
const LL::Node* LL::find(const Data& data) const
{
    for (Node* curr{head}; curr != nullptr; curr = curr->next) {
        if (equals(curr->data, data))
            return curr;
    }

    return nullptr; 
}

bool LL::contains(const Data& data) const
{
    return find(data) != nullptr;
}

void LL::remove(const Data& data)
{
    Node* prev{ nullptr };
    Node* curr{ head };

    for(; curr != nullptr; curr = curr->next) {
        if (equals(curr->data, data))
            break;
        prev = curr;
    }

    // not in linked list
    if (!curr)
        return;

    if (!prev) {
        head = head->next;
    } else {
        prev->next = curr->next; 
    }
    delete curr;
    --length;
}

unsigned int LL::getLength() const
{
    return length;
}

bool LL::equals(const Data& d1, const Data& d2) const
{
    return d1.username == d2.username && d1.password == d2.password;
}

std::string LL::toString() const
{
    std::ostringstream oss;
    // (username1, password1) -> (username2, password2) -> (username3, password3) -> NULL
    for (Node* curr{head}; curr != nullptr; curr = curr->next) {
        oss << "(" << curr->data.username << ", " << curr->data.password << ") -> ";
    }
    oss << "nullptr";

    return oss.str();
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
