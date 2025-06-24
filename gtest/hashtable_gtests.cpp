#include <gtest/gtest.h>
#include <string>

#include "hashtable.hpp"
#include "user.hpp"

namespace {
    
    TEST(HashMapInitialization, DefaultConstructor)
    {
        HashTable<std::string, User> map;
        EXPECT_TRUE(false);
    }
}
