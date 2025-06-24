#ifndef HASHMAP_HPP
#define HASHMAP_HPP

#include <iostream>
#include <sstream>
#include <functional>

#include "linkedlist.hpp"

template <typename KeyType, typename DataType>
// DataType synonymous with a hashmaps value

class HashMap
{
    static constexpr double loadFactor{ 0.8 };

    unsigned int numBuckets;
    LinkedList<DataType>** map;

    std::function<unsigned int(const KeyType&)>hashFunction;

    void deleteMap() noexcept;
    void rehash();

public:
    
    // default constructor
    HashMap() noexcept;

    // copy constructor
    HashMap(std::function<unsigned int(const KeyType&)> hashFunction);

    const DataType& get(const KeyType& key) const;
    void insert(const KeyType& key, const DataType& value);
    void remove(const KeyType& key);

    DataType& operator[](const KeyType&);
    const DataType& operator[](const KeyType&) const;

    // copy assignment
    HashMap& operator=(const HashMap& map);
    bool operator==(const HashMap& map) const;

    bool equals(const HashMap& map) const;
    void print() const;

    std::string toString() const;

   // destructor 
   ~HashMap() noexcept;
};


template <typename KeyType, typename DataType>
HashMap<KeyType, DataType>::HashMap() noexcept
    : numBuckets{ 10 }
{
    map = new LinkedList<DataType>*[numBuckets];

    for (unsigned int i{ 0 }; i < numBuckets; ++i) {
        map[i] = new LinkedList<DataType>();
    }
}


template <typename KeyType, typename DataType>
std::string HashMap<KeyType, DataType>::toString() const
{
    std::ostringstream oss;
    for (unsigned int i{ 0 }; i < numBuckets; ++i) {
        // TODO
    }

    return oss.str();
}

template <typename KeyType, typename DataType>
void HashMap<KeyType, DataType>::deleteMap() noexcept
{
    if (map == nullptr)
        return;

    for (unsigned int i{ 0 }; i < numBuckets; ++i) {
        delete map[i];
        map[i] = nullptr;
    }
    delete[] map;
    map = nullptr;
}

template <typename KeyType, typename DataType>
HashMap<KeyType, DataType>::~HashMap() noexcept
{
    deleteMap(); 
}

#endif
