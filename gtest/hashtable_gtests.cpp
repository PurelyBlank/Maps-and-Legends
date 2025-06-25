#include <gtest/gtest.h>
#include <string>

#include "hashtable.hpp"
#include "user.hpp"

namespace {

    constexpr int numBuckets{ 10 };
    
    TEST(HashTableInitialization, DefaultConstructor)
    {
        HashTable<std::string, User> map;
        
        std::string actual;
        for (int i{0}; i < 10; ++i) {
            actual += "nullptr\n";
        }
        EXPECT_EQ(actual, map.toString());

        HashTable<int, double> map2{};
        EXPECT_EQ(actual, map2.toString());    
    }

    // TODO: Copy Constructor

    TEST(HashTableHashFunction, DefaultHashFunction)
    {

    }

    // TEST(HashTableInsert, InsertOneIntoHashTable)
    // {
    //     HashTable<std::string, User> map;
    //     map.insert("user1", User{"user1", "12345"});

    // }
}
