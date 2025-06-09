#include <iostream>

#include "linkedlist.hpp"

typedef LinkedList LL;


LL::LinkedList()
    :head{ nullptr }, length{ 0 }
{
}

// copy-constructor




unsigned int LL::getLength() const
{
    return length;
}


LL::~LinkedList()
{
    
}
