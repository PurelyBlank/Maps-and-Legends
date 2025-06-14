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
        EXPECT_EQ("(John Doe, 12345) -> nullptr", ll.toString());

        ll.insert(d2);
        EXPECT_EQ(2, ll.getLength());
        EXPECT_EQ("(Jane Doe, 54321) -> (John Doe, 12345) -> nullptr", ll.toString());
    }

    TEST(LinkedListContains, ContainsInEmptyLinkedList)
    {
        LinkedList ll;
           
        Data d1{ "Mike Myers", "@MikeM" };

        EXPECT_FALSE(ll.contains(d1));
        EXPECT_EQ("nullptr", ll.toString());
    }

    TEST(LinkedListContains, ContainsInLinkedList)
    {
        LinkedList ll;
           
        Data d1{ "Fred Flintstone", "abc" };
        Data d2{ "Fred Flintstone", "cba" }; // different second field, different data
        ll.insert(d1);

        EXPECT_EQ(1, ll.getLength());
        EXPECT_TRUE(ll.contains(d1));

        ll.insert(d2);

        EXPECT_EQ(1, ll.getLength());
        EXPECT_TRUE(ll.contains(d1));

        EXPECT_EQ("(Fred Flintstone, abc) -> nullptr", ll.toString());
    }

    TEST(LinkedListRemove, RemoveFromEmptyLinkedList)
    {
        LinkedList ll;

        Data d1{ "Spike Spiegal", "cowboy" };

        ll.remove(d1);

        EXPECT_EQ(0, ll.getLength());
        EXPECT_EQ("nullptr", ll.toString());
    }

    TEST(LinkedListRemove, RemoveDataNotInLinkedList)
    {
        LinkedList ll;

        Data d1{ "Nico Robin", "mil-fleur" };
        Data d2{ "Tenno", "lotus" };

        ll.insert(d1);
        ll.remove(d2);

        EXPECT_EQ(1, ll.getLength());
        EXPECT_TRUE(ll.contains(d1));
        EXPECT_EQ("(Nico Robin, mil-fleur) -> nullptr", ll.toString());
    }

    TEST(LinkedListRemove, RemoveFirstFromLinkedList)
    {
        LinkedList ll;
        
        Data d1{ "Banshee", "Loud and Clear" };
        Data d2{ "SCV", "SCV Ready" };
        
        ll.insert(d1);
        ll.insert(d2);

        EXPECT_EQ("(SCV, SCV Ready) -> (Banshee, Loud and Clear) -> nullptr", ll.toString());

        ll.remove(d2); // last thing we insert into linked list is first in line (LIFO)
                       // based on insertion algorithm
        EXPECT_EQ(1, ll.getLength());

        EXPECT_EQ("(Banshee, Loud and Clear) -> nullptr", ll.toString());
    }

    TEST(LinkedListRemove, RemoveLastFromLinkedList)
    {
        LinkedList ll;
        
        Data d1{ "Banshee", "Loud and Clear" };
        Data d2{ "SCV", "SCV Ready" };

        ll.insert(d1);
        ll.insert(d2);

        EXPECT_EQ("(SCV, SCV Ready) -> (Banshee, Loud and Clear) -> nullptr", ll.toString());

        ll.remove(d1); // last thing we insert into linked list is first in line (LIFO)
                       // based on insertion algorithm
        EXPECT_EQ(1, ll.getLength());

        EXPECT_EQ("(SCV, SCV Ready) -> nullptr", ll.toString());
    }

    TEST(LinkedListRemove, RemoveDataInLinkedList)
    {
        LinkedList ll;

        Data d1{ "Player_1", "p1" };
        Data d2{ "Player_2", "p2" };
        Data d3{ "Player_3", "p3" };
        Data d4{ "Player_4", "p4" };

        ll.insert(d1);
        ll.insert(d2);
        ll.insert(d3);
        ll.insert(d4);

        EXPECT_EQ("(Player_4, p4) -> (Player_3, p3) -> (Player_2, p2) -> (Player_1, p1) -> nullptr", ll.toString());

        EXPECT_EQ(4, ll.getLength());

        ll.remove(d1);
        EXPECT_EQ("(Player_4, p4) -> (Player_3, p3) -> (Player_2, p2) -> nullptr", ll.toString());

        EXPECT_EQ(3, ll.getLength());

        ll.remove(d3);
        EXPECT_EQ("(Player_4, p4) -> (Player_2, p2) -> nullptr", ll.toString());

        EXPECT_EQ(2, ll.getLength());

        ll.remove(d4);
        EXPECT_EQ("(Player_2, p2) -> nullptr", ll.toString());

        EXPECT_EQ(1, ll.getLength());

        ll.remove(d2);
        EXPECT_EQ("nullptr", ll.toString());

        EXPECT_EQ(0, ll.getLength());
    }
    
    TEST(ReverseLinkedList, ReverseEmptyLinkedList)
    {
        LinkedList ll;
        ll.reverse();

        EXPECT_EQ("nullptr", ll.toString());
    }

    TEST(ReverseLinkedList, ReverseLinkedListSizeOne)
    {
        LinkedList ll;

        Data d1{ "Player_1", "p1" };

        ll.insert(d1);
        ll.reverse();

        EXPECT_EQ("(Player_1, p1) -> nullptr", ll.toString());
    }

    TEST(ReverseLinkedList, ReverseLinkedListSizeTwo)
    {
        LinkedList ll;

        Data d1{ "Player_1", "p1" };
        Data d2{ "Player_2", "p2" };

        ll.insert(d1);
        ll.insert(d2);

        ll.reverse();

        EXPECT_EQ("(Player_1, p1) -> (Player_2, p2) -> nullptr", ll.toString());
    }

    TEST(ReverseLinkedList, ReverseLinkedList)
    {
        LinkedList ll;

        Data d1{ "Player_1", "p1" };
        Data d2{ "Player_2", "p2" };
        Data d3{ "Player_3", "p3" };
        Data d4{ "Player_4", "p4" };

        ll.insert(d1);
        ll.insert(d2);
        ll.insert(d3);
        ll.insert(d4);

        ll.reverse();

        EXPECT_EQ("(Player_1, p1) -> (Player_2, p2) -> (Player_3, p3) -> (Player_4, p4) -> nullptr", ll.toString());
        EXPECT_EQ(4, ll.getLength());
    }

    TEST(LinkedListConstruction, DefaultConstructor)
    {
        LinkedList ll;
        EXPECT_EQ(0, ll.getLength());
        EXPECT_EQ("nullptr", ll.toString());
    }

    TEST(LinkedListConstruction, CopyConstructor)
    {
        LinkedList ll_1;
        ll_1.insert(Data{"test1", "test1"});
        ll_1.insert(Data{"test2", "test2"});

        LinkedList ll_2{ ll_1 };
        EXPECT_EQ(ll_2.getLength(), 2);
        EXPECT_EQ(ll_1.toString(), ll_2.toString());
        EXPECT_TRUE(ll_2.equals(ll_1));
    }


};
