#include <gtest/gtest.h>
#include "linkedlist.hpp"


namespace {
    
    TEST(LinkedListInsert, InsertNodes)
    {
        LinkedList ll{ LinkedList() };    
        
        Data d1{ "John Doe", "12345" };
        Data d2{ "Jane Doe", "54321" };        

        ll.insert(d1);
        EXPECT_EQ(1, ll.getLength());

        ll.insert(d2);
        EXPECT_EQ(2, ll.getLength());
    }

    TEST(LinkedListFind, FindInEmptyLinkedList)
    {
        LinkedList ll;
           
        Data d1{ "Mike Myers", "@MikeM" };

        EXPECT_FALSE(ll.find(d1));
    }

    TEST(LinkedListFind, FindInLinkedListSizeOne)
    {
        LinkedList ll;
           
        Data d1{ "Fred Flintstone", "abc" };
        Data d2{ "Fred Flintstone", "cba" }; // different second field, different data
        ll.insert(d1);

        EXPECT_EQ(1, ll.getLength());
        EXPECT_TRUE(ll.find(d1));
        EXPECT_FALSE(ll.find(d2));

        ll.insert(d2);

        EXPECT_EQ(2, ll.getLength());
        EXPECT_TRUE(ll.find(d1));
        EXPECT_TRUE(ll.find(d2));
    }

    TEST(LinkedListConstruction, DefaultConstructor)
    {
        LinkedList ll;
        EXPECT_EQ(0, ll.getLength());
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
