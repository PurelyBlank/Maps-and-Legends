#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <iostream>
#include <sstream>
#include <functional>

#include "linkedlist.hpp"

template <typename KeyType, typename DataType>
// DataType synonymous with a hashtables value

class HashTable
{
    static constexpr double loadFactor{ 0.8 };

    unsigned int numBuckets;
    LinkedList<DataType>** map;

    std::function<unsigned int(const KeyType&)>hashFunction;

    void deleteMap() noexcept;
    void rehash();

public:
    
    // default constructor
    HashTable() noexcept;

    // copy constructor
    HashTable(std::function<unsigned int(const KeyType&)> hashFunction);

    const DataType& get(const KeyType& key) const;
    void insert(const KeyType& key, const DataType& value);
    void remove(const KeyType& key);

    DataType& operator[](const KeyType&);
    const DataType& operator[](const KeyType&) const;

    // copy assignment
    HashTable& operator=(const HashTable& map);
    bool operator==(const HashTable& map) const;

    bool equals(const HashTable& map) const;
    void print() const;

    std::string toString() const;

   // destructor 
   ~HashTable() noexcept;
};


template <typename KeyType, typename DataType>
HashTable<KeyType, DataType>::HashTable() noexcept
    : numBuckets{ 10 }
{
    map = new LinkedList<DataType>*[numBuckets];

    for (unsigned int i{ 0 }; i < numBuckets; ++i) {
        map[i] = new LinkedList<DataType>();
    }
}


template <typename KeyType, typename DataType>
std::string HashTable<KeyType, DataType>::toString() const
{
    std::ostringstream oss;
    for (unsigned int i{ 0 }; i < numBuckets; ++i) {
        // TODO
    }

    return oss.str();
}

template <typename KeyType, typename DataType>
void HashTable<KeyType, DataType>::deleteMap() noexcept
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
HashTable<KeyType, DataType>::~HashTable() noexcept
{
    deleteMap(); 
}

#endif
