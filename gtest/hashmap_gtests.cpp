#include <gtest/gtest.h>
#include <string>

#include "hashmap.hpp"
#include "user.hpp"

namespace {
    
    TEST(HashMapInitialization, DefaultConstructor)
    {
        HashMap<std::string, User> map;
        EXPECT_TRUE(false);
    }
}
