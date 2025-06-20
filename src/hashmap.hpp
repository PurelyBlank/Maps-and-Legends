#ifndef HASHMAP_HPP
#define HASHMAP_HPP

#include <iostream>
#include <functional>

#include "linkedlist.hpp"

class HashMap
{
    static constexpr double loadFactor{ 0.8 };

    unsigned int numBuckets;
    LinkedList** map;

    std::function<unsigned int(const std::string&)>hashFunction;

    void rehash();
public:
    
    // default constructor
    HashMap() noexcept;

    // copy constructor
    HashMap(std::function<unsigned int(const std::string&)> hashFunction);

    const std::string& get(const std::string& key) const;
    void insert(const std::string& key, const std::string& value);
    void remove(const std::string& key);

    std::string& operator[](const std::string&);

    // copy assignment
    HashMap& operator=(const HashMap& map);  
    bool operator==(const HashMap& map) const;

    bool equals(const HashMap& map) const;
    void print() const;

    std::string toString() const;

   // destructor 
   ~HashMap() noexcept;
};

#endif
