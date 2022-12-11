#ifndef DATASTRUCTURES_SOLUTION_H
#define DATASTRUCTURES_SOLUTION_H

#include <iostream>

template<typename T>
struct Node {
    T value;
    Node<T> *next;

    Node(const T &value) : value(value), next(nullptr) {}
};

struct Intervals {
    int from;
    int to;

    Intervals(int from, int to) : from(from), to(to) {}
};

template<typename T>
Node<T> *getNodeAtIndex(Node<T> *head, int index) {
    while (index--)
        head = head->next;

    return head;
}

template<typename T>
size_t size(const Node<T> *head) {
    size_t counter = 0;

    while (head) {
        counter++;
        head = head->next;
    }

    return counter;
}


template<typename T>
void reverseSublists(Node<T> *head, const Intervals &intervals) {
    size_t listSize = size(head);

    if (intervals.from >= listSize || intervals.to >= listSize)
        throw std::invalid_argument("Invalid indexes!");

    Node<T> *traverse = head;
    int index = 0;

    int from = intervals.from;
    int to = intervals.to;
    int iterations = (to - from) / 2;

    if ((to - from + 1) % 2 == 0) // четно
        iterations++;

    //0 1 2 3 4
    // from = 0,to = 4,i = 0
    //i = 1,from + i = 1,to - i = 3


    for (int i = 0; i < iterations; i++) {
        Node<T> *first = getNodeAtIndex(head, from + i);
        Node<T> *second = getNodeAtIndex(head, to - i);

        std::swap(first->value, second->value);
    }
}

#endif //DATASTRUCTURES_SOLUTION_H
