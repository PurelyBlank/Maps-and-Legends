#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "linkedlist.hpp"
#include "user.hpp"


namespace {
    
    TEST(LinkedListInsert, InsertNodes)
    {
        LinkedList<User> ll;
        
        User d1{ "John Doe", "12345" };
        User d2{ "Jane Doe", "54321" };        

        ll.insert(d1);
        EXPECT_EQ(1, ll.getLength());
        EXPECT_EQ("(John Doe, 12345) -> nullptr", ll.toString());

        ll.insert(d2);
        EXPECT_EQ(2, ll.getLength());
        EXPECT_EQ("(Jane Doe, 54321) -> (John Doe, 12345) -> nullptr", ll.toString());
    }

    TEST(LinkedListInsertTest, InsertMultipleElements) {
        LinkedList<std::string> llStr;
        
        std::string output;

        int numIters{ 100 };
        for (int i{0}; i <= numIters; ++i) {
            llStr.insert(std::to_string(i));
            output += "(" + std::to_string(numIters - i) + ") -> ";
        }
        output += "nullptr";

        EXPECT_EQ(output, llStr.toString());
    }

    TEST(LinkedListInsertTest, InsertDuplicates) {
        LinkedList<std::string> llStr;
        llStr.insert("hello");
        llStr.insert("world");
        llStr.insert("hello"); // Duplicate
        llStr.insert("again");
    
        EXPECT_EQ("(again) -> (world) -> (hello) -> nullptr", llStr.toString());
    }

    TEST(LinkedListContains, ContainsInEmptyLinkedList)
    {
        LinkedList<User> ll;
           
        User d1{ "Mike Myers", "@MikeM" };

        EXPECT_FALSE(ll.contains(d1));
        EXPECT_EQ("nullptr", ll.toString());
    }

    TEST(LinkedListContains, ContainsInLinkedList)
    {
        LinkedList<User> ll;
           
        User d1{ "Fred Flintstone", "abc" };
        // different second field, different data
        User d2{ "Fred Flintstone", "cba" }; 
        ll.insert(d1);

        EXPECT_EQ(1, ll.getLength());
        EXPECT_TRUE(ll.contains(d1));

        ll.insert(d2);

        EXPECT_EQ(2, ll.getLength());
        EXPECT_TRUE(ll.contains(d1));

        EXPECT_EQ("(Fred Flintstone, cba) -> (Fred Flintstone, abc) -> nullptr", ll.toString());
    }

    TEST(LinkedListContains, ContainsInEmptyDoubleList) {
        LinkedList<double> ll;
        EXPECT_FALSE(ll.contains(3.14));
        EXPECT_EQ("nullptr", ll.toString());
    }

    TEST(LinkedListContains, ContainsExistingDoubleElement) {
        LinkedList<double> ll;
        ll.insert(1.1); // List: (1.1) -> nullptr
        ll.insert(2.2); // List: (2.2) -> (1.1) -> nullptr
        ll.insert(3.3); // List: (3.3) -> (2.2) -> (1.1) -> nullptr
    
        EXPECT_TRUE(ll.contains(3.3)); // Head
        EXPECT_TRUE(ll.contains(2.2));
        EXPECT_TRUE(ll.contains(1.1));
    }

    TEST(LinkedListRemove, RemoveFromEmptyLinkedList)
    {
        LinkedList<User> ll;

        User d1{ "Spike Spiegal", "cowboy" };

        ll.remove(d1);

        EXPECT_EQ(0, ll.getLength());
        EXPECT_EQ("nullptr", ll.toString());
    }

    TEST(LinkedListRemove, RemoveUserNotInLinkedList)
    {
        LinkedList<User> ll;

        User d1{ "Nico Robin", "mil-fleur" };
        User d2{ "Tenno", "lotus" };

        ll.insert(d1);
        ll.remove(d2);

        EXPECT_EQ(1, ll.getLength());
        EXPECT_TRUE(ll.contains(d1));
        EXPECT_EQ("(Nico Robin, mil-fleur) -> nullptr", ll.toString());
    }

    TEST(LinkedListRemove, RemoveFirstFromLinkedList)
    {
        LinkedList<User> ll;
        
        User d1{ "Banshee", "Loud and Clear" };
        User d2{ "SCV", "SCV Ready" };
        
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
        LinkedList<User> ll;
        
        User d1{ "Banshee", "Loud and Clear" };
        User d2{ "SCV", "SCV Ready" };

        ll.insert(d1);
        ll.insert(d2);

        EXPECT_EQ("(SCV, SCV Ready) -> (Banshee, Loud and Clear) -> nullptr", ll.toString());

        ll.remove(d1); // last thing we insert into linked list is first in line (LIFO)
                       // based on insertion algorithm
        EXPECT_EQ(1, ll.getLength());

        EXPECT_EQ("(SCV, SCV Ready) -> nullptr", ll.toString());
    }

    TEST(LinkedListRemove, RemoveUserInLinkedList)
    {
        LinkedList<User> ll;

        User d1{ "Player_1", "p1" };
        User d2{ "Player_2", "p2" };
        User d3{ "Player_3", "p3" };
        User d4{ "Player_4", "p4" };

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
        LinkedList<User> ll;
        ll.reverse();

        EXPECT_EQ("nullptr", ll.toString());
    }

    TEST(ReverseLinkedList, ReverseLinkedListSizeOne)
    {
        LinkedList<User> ll;

        User d1{ "Player_1", "p1" };

        ll.insert(d1);
        ll.reverse();

        EXPECT_EQ("(Player_1, p1) -> nullptr", ll.toString());
    }

    TEST(ReverseLinkedList, ReverseLinkedListSizeTwo)
    {
        LinkedList<User> ll;

        User d1{ "Player_1", "p1" };
        User d2{ "Player_2", "p2" };

        ll.insert(d1);
        ll.insert(d2);

        ll.reverse();

        EXPECT_EQ("(Player_1, p1) -> (Player_2, p2) -> nullptr", ll.toString());
    }

    TEST(ReverseLinkedList, ReverseLinkedList)
    {
        LinkedList<User> ll;

        User d1{ "Player_1", "p1" };
        User d2{ "Player_2", "p2" };
        User d3{ "Player_3", "p3" };
        User d4{ "Player_4", "p4" };

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
        LinkedList<User> ll;
        EXPECT_EQ(0, ll.getLength());
        EXPECT_EQ("nullptr", ll.toString());
    }

    TEST(LinkedListConstruction, CopyConstructor)
    {
        LinkedList<User> ll_1;
        ll_1.insert(User{"test1", "test1"});
        ll_1.insert(User{"test2", "test2"});

        LinkedList<User> ll_2{ ll_1 };
        EXPECT_EQ(ll_2.getLength(), 2);
        EXPECT_EQ(ll_1.toString(), ll_2.toString());
        EXPECT_TRUE(ll_2.equals(ll_1));
    }

    TEST(LinkedListConstruction, CopyConstructorEmptyLinkedList)
    {
        LinkedList<User> emptyLL;
        LinkedList<User> ll = emptyLL;

        EXPECT_TRUE(ll.equals(emptyLL));
    }

    TEST(LinkedListOperatorAssignment, AssignEmptyLinkedListToThis)
    {
        LinkedList<User> emptyLL;

        LinkedList<User> ll;
        ll.insert(User{"p1", "p1"});

        ll = emptyLL;
        
        EXPECT_EQ(ll.getLength(), 0);
        EXPECT_TRUE(ll.equals(emptyLL));
    }
    
    TEST(LinkedListOperatorAssignment, AssignLinkedListToThis)
    {
        LinkedList<User> ll_1;
        ll_1.insert(User{"test1", "test1"});

        LinkedList<User> ll_2;
        ll_2.insert(User{"test2", "test2"});

        ll_1 = ll_2;
        EXPECT_TRUE(ll_1.equals(ll_2));
    }

    TEST(LinkedListOperatorEquals, TwoEmptyLinkedListComparison)
    {
        LinkedList<User> ll_1;
        LinkedList<User> ll_2;

        EXPECT_TRUE(ll_1 == ll_2);
    }

    TEST(LinkedListOperatorEquals, OneEmptyLinkedListOneNonEmptyLinkedList)
    {
        LinkedList<User> emptyLL;
        LinkedList<User> ll_1;

        ll_1.insert(User{"test1", "test1"});
        
        EXPECT_FALSE(ll_1 == emptyLL); 
    }

    TEST(LinkedListOperatorEquals, TwoNonEmptyDifferentLinkedListsComparison)
    {
        LinkedList<User> ll_1;
        ll_1.insert(User{"test1", "test1"});

        LinkedList<User> ll_2;
        ll_2.insert(User{"test2", "test2"});

        EXPECT_FALSE(ll_1 == ll_2);
    }

    TEST(LinkedListOperatorEquals, TwoNonEmptySameLinkedListsComparison)
    {
        LinkedList<User> ll_1;
        ll_1.insert(User{"test1", "test1"});

        LinkedList<User> ll_2;
        ll_2.insert(User{"test1", "test1"});

        EXPECT_TRUE(ll_1 == ll_2);
    }
};
