#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <string>
#include <sstream>

#include "user.hpp"

template <typename DataType>
class LinkedList
{
    struct Node
    {
        DataType data;
        Node* next;

        Node(const DataType& data, Node* next = nullptr)
            : data{ data }, next{ next }
        {
        }
    };

    Node* copy(const LinkedList<DataType>& ll);
    Node* reverse(Node* node);
    void deleteList() noexcept;

    Node* head;
    unsigned int length;

public:

    // default constructor
    LinkedList() noexcept;

    // copy-constructor
    LinkedList(const LinkedList<DataType>& ll);

    void insert(const DataType& data);
    const Node* find(const DataType& data) const;
    bool contains(const DataType& data) const;
    void remove(const DataType& data);

    unsigned int getLength() const noexcept;
    void reverse();

    // assignment operator 
    LinkedList<DataType>& operator=(const LinkedList<DataType>& ll);
    bool operator==(const LinkedList<DataType>& ll) const;

    bool equals(const LinkedList<DataType>& ll) const;
    bool equals(const DataType& d1, const DataType& d2) const;
    void print() const;

    std::string toString() const;

    // destructor
    ~LinkedList() noexcept;
};


template <typename DataType>
LinkedList<DataType>::LinkedList() noexcept
    :head{ nullptr }, length{ 0 }
{
}

template <typename DataType>
// copy-constructor
LinkedList<DataType>::LinkedList(const LinkedList<DataType>& ll)
    :head{ copy(ll) }, length{ ll.length }
{
}

template <typename DataType>
void LinkedList<DataType>::insert(const DataType& data)
{
    if (contains(data)) {
        return;
    } 
    head = new Node(data, head);
    ++length;
}

template <typename DataType>
// if user wants to exclude insertion of data into linkedlist based
// on a specific field (e.g. a username), that will be the users
// reponsibility using the linkedlist
const LinkedList<DataType>::Node* LinkedList<DataType>::find(const DataType& data) const
{
    for (Node* curr{head}; curr != nullptr; curr = curr->next) {
        if (equals(curr->data, data))
            return curr;
    }

    return nullptr; 
}

template <typename DataType>
bool LinkedList<DataType>::contains(const DataType& data) const
{
    return find(data) != nullptr;
}

template <typename DataType>
void LinkedList<DataType>::remove(const DataType& data)
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

template <typename DataType>
unsigned int LinkedList<DataType>::getLength() const noexcept
{
    return length;
}

template <typename DataType>
LinkedList<DataType>& LinkedList<DataType>::operator=(const LinkedList<DataType>& ll)
{
    if (this != &ll) {
        deleteList();
        head = copy(ll);
        length = ll.getLength();
    }
        
    return *this;
}

template <typename DataType>
bool LinkedList<DataType>::operator==(const LinkedList<DataType>& ll) const
{
    return equals(ll);
}

template <typename DataType>
void LinkedList<DataType>::reverse()
{
    head = reverse(head);
}

template <typename DataType>
LinkedList<DataType>::Node* LinkedList<DataType>::reverse(Node* node)
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

template <typename DataType>
LinkedList<DataType>::Node* LinkedList<DataType>::copy(const LinkedList<DataType>& ll)
{
    Node* newHead{ nullptr };
    for (Node* curr{ ll.head }; curr != nullptr; curr = curr->next) {
        // The resulting linkedlist would be the reverse order,
        // would require reversing the linkedlist
        newHead = new Node(curr->data, newHead);
    }
    return reverse(newHead);
}

template <typename DataType>
bool LinkedList<DataType>::equals(const LinkedList<DataType>& ll) const
{
    Node* ll_1{ head };
    Node* ll_2{ ll.head };
 
    while( ll_1 && ll_2 && equals(ll_1->data, ll_2->data)) {
        ll_1 = ll_1->next;
        ll_2 = ll_2->next;
    }
    return ll_1 == ll_2;
}

template <typename DataType>
bool LinkedList<DataType>::equals(const DataType& d1, const DataType& d2) const
{
    // equality dependent on underlying implementation of the DataTypes "==" operator
    return d1 == d2;
}

template <typename DataType>
void LinkedList<DataType>::print() const
{
    std::cout << toString() << '\n';
}

template <typename DataType>
std::string LinkedList<DataType>::toString() const
{
    std::ostringstream oss;
    // (username1, password1) -> (username2, password2) -> (username3, password3) -> NULL
    for (Node* curr{head}; curr != nullptr; curr = curr->next) {
        // ostream dependent on underlying implementation of DataTypes "<<" operator
        oss << "(" << curr->data << ") -> ";
    }
    oss << "nullptr";

    return oss.str();
}

template <typename DataType>
void LinkedList<DataType>::deleteList() noexcept
{
    Node* curr{ head };
    while (curr != nullptr) {
        Node* temp{ curr->next };
        delete curr;
        curr = temp;
    }
    head = nullptr;
}

template <typename DataType>
LinkedList<DataType>::~LinkedList() noexcept
{
    deleteList();
}

#endif
