#include "solution.h"

Node<size_t> *clone(const Node<size_t> *head) {
    Node<size_t> *newHead = new Node<size_t>(head->value);
    Node<size_t> *traverse = newHead;

    head = head->next;

    while (head) {
        traverse->next = new Node<size_t>(head->value);
        head = head->next;
        traverse = traverse->next;
    }

    return newHead;
}

void sumTo(Node<size_t> *to, Node<size_t> *from) {
    bool addition = 0;
    while (from) {
        addition = to->value + from->value + addition >= 10;
        to->value = (to->value + from->value + addition) % 10;
        from = from->next;
        to = to->next;
    }
}

Node<size_t> *sum(Node<size_t> *first, Node<size_t> *second) {
    Node<size_t> *newSum;
    if (size(first) > size(second)) {
        newSum = clone(first);
        sumTo(newSum, second);
    } else {
        newSum = clone(second);
        sumTo(newSum, first);
    }

    return newSum;
}