#include "catch2/catch_all.hpp"
#include "../solution/solution.h"

TEST_CASE("Testing intervals!") {
    Node<int> *list = new Node<int>(11);
    Node<int> *traverse = list;

    traverse->next = new Node<int>(4);
    traverse = traverse->next;

    traverse->next = new Node<int>(3);
    traverse = traverse->next;

    traverse->next = new Node<int>(7);
    traverse = traverse->next;

    traverse->next = new Node<int>(13);
    traverse = traverse->next;

    traverse->next = new Node<int>(4);
    traverse = traverse->next;

    traverse->next = new Node<int>(5);


    Node<Intervals> *intervals = new Node<Intervals>(Intervals(1, 3));
    intervals->next = new Node<Intervals>(Intervals(2, 5));
    intervals->next->next = new Node<Intervals>(Intervals(5, 6));

    reverseSublists(list, intervals->value);
    reverseSublists(list, intervals->next->value);
    reverseSublists(list, intervals->next->next->value);

    traverse = list;

    REQUIRE(traverse->value == 11);
    traverse = traverse->next;

    REQUIRE(traverse->value == 7);
    traverse = traverse->next;

    REQUIRE(traverse->value == 4);
    traverse = traverse->next;

    REQUIRE(traverse->value == 13);
    traverse = traverse->next;

    REQUIRE(traverse->value == 4);
    traverse = traverse->next;

    REQUIRE(traverse->value == 5);
    traverse = traverse->next;

    REQUIRE(traverse->value == 3);
}