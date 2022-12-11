#include "solution.h"

bool checkTotal(Node<int> *head) {
    if (!head)
        return false;

    Node<int> *traverse = head;

    while (traverse->next->next) {
        if (traverse->value + traverse->next->next->value != traverse->next->value)
            return false;
        traverse = traverse->next;
    }

    return size(head) > 2;
}

void removeNode(Node<int> *head) {
    Node<int> *traverse = head;

    while (traverse->next->next) {
        if (traverse->value + traverse->next->next->value == traverse->next->value) {
            Node<int> *nodeForDeletion = traverse->next;
            traverse->next = traverse->next->next;
            delete nodeForDeletion;
        } else traverse = traverse->next;
    }
}


bool makeTotal(Node<int> *head) {
    bool total = checkTotal(head);

    if (total)
        return total;
    else removeNode(head);

    return false;
}