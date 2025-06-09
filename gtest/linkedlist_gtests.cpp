#include <gtest/gtest.h>
#include "linkedlist.hpp"


namespace {
    
    TEST(LinkedListInsert, InsertNodes)
    {
        LinkedList ll{ LinkedList() };    
        
        Data d1{ "John Doe", "12345" };
        Data d2{ "Jane Doe", "54321" };        

        ll.insert(d1);
        EXPECT_EQ(ll.getLength(), 1);

        ll.insert(d2);
        EXPECT_EQ(ll.getLength(), 2);
    }

    TEST(LinkedListConstruction, DefaultConstructor)
    {
        LinkedList ll{ LinkedList() };
        EXPECT_EQ(ll.getLength(), 0);
    }

    // TEST(LinkedListConstruction, CopyConstructor)
    // {
    //     LinkedList* ll_1{ new LinkedList() };
    //     ll_1.insert(new Node{ Data{"test1", "test1"}, nullptr });
    //     ll_1.insert(new Node{ Data{"test2", "test2"}, nullptr });

    //     LinkedList* ll_2{ new LinkedList(ll_1) };
    //     EXPECT_EQ(ll_2.getLength(), 2);
    //     EXPECT_TRUE(ll_2.equals(ll_1));
    // }


};
