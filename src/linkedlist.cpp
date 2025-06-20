#include <iostream>
#include <sstream>

#include "linkedlist.hpp"

typedef LinkedList LL;

LL::LinkedList() noexcept
    :head{ nullptr }, length{ 0 }
{
}

// copy-constructor
LL::LinkedList(const LinkedList& ll)
    :head{ copy(ll) }, length{ ll.length }
{
}

void LL::insert(const Data& data)
{
    if (contains(data)) {
        return;
    } 
    head = new Node(data, head);
    ++length;
}

// disallow modification of node's internal data
const LL::Node* LL::find(const Data& data) const
{
    for (Node* curr{head}; curr != nullptr; curr = curr->next) {
        if (curr->data.username == data.username)
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

LinkedList& LL::operator=(const LinkedList& ll)
{
    if (this != &ll) {
        deleteList();
        head = copy(ll);
    }
        
    return *this;
}

bool LL::operator==(const LinkedList& ll) const
{
    return equals(ll);
}

void LL::reverse()
{
    head = reverse(head);
}

LL::Node* LL::reverse(Node* node)
{
    Node* prev{ nullptr };
    Node* curr{ node };
    
    while(curr != nullptr) {
        Node* temp{ curr->next };
        curr->next = prev;
        prev = curr;
        curr = temp;
    } 

    return prev;
}

LL::Node* LL::copy(const LinkedList& ll)
{
    Node* newHead{ nullptr };
    for (Node* curr{ ll.head }; curr != nullptr; curr = curr->next) {
        // The resulting linkedlist would be the reverse order,
        // would require reversing the linkedlist
        newHead = new Node(Data{ curr->data.username, curr->data.password }, newHead);
    }
    return reverse(newHead);
}

bool LL::equals(const LinkedList& ll) const
{
    Node* ll_1{ head };
    Node* ll_2{ ll.head };
 
    while( ll_1 && ll_2 && equals(ll_1->data, ll_2->data)) {
        ll_1 = ll_1->next;
        ll_2 = ll_2->next;
    }
    return ll_1 == ll_2;
}

bool LL::equals(const Data& d1, const Data& d2) const
{
    return d1.username == d2.username && d1.password == d2.password;
}

void LL::print() const
{
    std::cout << toString() << '\n';
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

void LL::deleteList() noexcept
{
    Node* curr{ head };
    while (curr != nullptr) {
        Node* temp{ curr->next };
        delete curr;
        curr = temp;
    }
    head = nullptr;
}

LL::~LinkedList() noexcept
{
    deleteList();
}
