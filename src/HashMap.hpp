#include <iostream>

#include "linkedlist.hpp"

class HashMap
{
    static constexpr double loadFactor{ 0.8 };

    unsigned int numBuckets;
    LinkedList* map[numBuckets];

    std::function<unsigned int(const std::stirng&)>hashFunction;

    void rehash();
public:
    
    HashMap();
    HashMap(std::function<unsigned int(const std::string&)> hashFunction);

    // Other functions... 
};
