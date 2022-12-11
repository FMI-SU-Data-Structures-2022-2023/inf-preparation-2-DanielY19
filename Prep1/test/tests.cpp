#include "../../src/solution.h"
#include "catch2/catch_all.hpp"

TEST_CASE("Testing task1"){

}


TEST_CASE("Testing task3") {
    DoubleLinkedNode *head = new DoubleLinkedNode(1);
    head->next = new DoubleLinkedNode(2, head);
    head->next->next = new DoubleLinkedNode(3, head->next);
    head->next->next->next = new DoubleLinkedNode(4, head->next->next);
    DoubleLinkedNode *traverse = head;

    mirror(head);

    REQUIRE(traverse->data == 1);
    traverse = traverse->next;

    REQUIRE(traverse->data == 2);
    traverse = traverse->next;

    REQUIRE(traverse->data == 3);
    traverse = traverse->next;

    REQUIRE(traverse->data == 4);
    traverse = traverse->next;

    REQUIRE(traverse->data == 4);
    traverse = traverse->next;

    REQUIRE(traverse->data == 3);
    traverse = traverse->next;

    REQUIRE(traverse->data == 2);
    traverse = traverse->next;

    REQUIRE(traverse->data == 1);

    destroy(head);
}