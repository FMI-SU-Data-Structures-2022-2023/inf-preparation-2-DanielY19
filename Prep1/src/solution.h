#ifndef DATASTRUCTURES_SOLUTION_H
#define DATASTRUCTURES_SOLUTION_H

template<typename T>
struct Node {
    T value;
    Node<T> *next;

    Node(const T &value) : value(value), next(nullptr) {}
};

template<typename T>
size_t size(const Node<T> *head) {
    size_t counter = 0;

    while (head) {
        counter++;
        head = head->next;
    }

    return counter;
}


struct DoubleLinkedNode {
    int data;
    DoubleLinkedNode *next;
    DoubleLinkedNode *prev;

    DoubleLinkedNode(int data) : data(data), next(nullptr), prev(nullptr) {}

    DoubleLinkedNode(int data, DoubleLinkedNode *prev) : data(data), next(nullptr), prev(prev) {}
};

DoubleLinkedNode *getSecondLast(DoubleLinkedNode *head);

DoubleLinkedNode* clone(const DoubleLinkedNode* head);

DoubleLinkedNode* reverse(const DoubleLinkedNode *head);

void mirror(DoubleLinkedNode* head);

void destroy(DoubleLinkedNode *head);





#endif //DATASTRUCTURES_SOLUTION_H
