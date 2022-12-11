#include "catch2/catch_all.hpp"
#include "../src/solution.h"


TEST_CASE("") {
    Node<int> *list = new Node<int>(1);
    Node<int> *traverse = list;

    traverse->next = new Node<int>(-4);
    traverse = traverse->next;

    traverse->next = new Node<int>(-5);
    traverse = traverse->next;

    traverse->next = new Node<int>(-1);
    traverse = traverse->next;

    traverse->next = new Node<int>(4);


    REQUIRE(makeTotal(list));
}


TEST_CASE("") {
    Node<int> *list = new Node<int>(10);
    Node<int> *traverse = list;

    traverse->next = new Node<int>(5);
    traverse = traverse->next;

    traverse->next = new Node<int>(-5);
    traverse = traverse->next;

    traverse->next = new Node<int>(-15);
    traverse = traverse->next;

    traverse->next = new Node<int>(2);


    REQUIRE_FALSE(makeTotal(list));
    traverse = list;

    REQUIRE(traverse->value == 10);
    traverse = traverse->next;

    REQUIRE(traverse->value == -15);
    traverse = traverse->next;

    REQUIRE(traverse->value == 2);
}
