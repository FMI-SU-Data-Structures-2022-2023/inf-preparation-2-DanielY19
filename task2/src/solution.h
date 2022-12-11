#ifndef DATASTRUCTURES_SOLUTION_H
#define DATASTRUCTURES_SOLUTION_H

template<typename T>
struct Node {
    T value;
    Node<T> *next;

    Node(const T &value) : value(value), next(nullptr) {}
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

bool checkTotal(Node<int> *head);

void removeNode(Node<int> *head);

bool makeTotal(Node<int> *head);

#endif //DATASTRUCTURES_SOLUTION_H
