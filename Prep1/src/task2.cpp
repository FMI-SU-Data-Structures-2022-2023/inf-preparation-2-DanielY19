#include "solution.h"

DoubleLinkedNode *getSecondLast(DoubleLinkedNode *head) {
    while (head->next->next)
        head = head->next;

    return head;
}

DoubleLinkedNode *clone(const DoubleLinkedNode *head) {
    DoubleLinkedNode *newHead = new DoubleLinkedNode(head->data);

    const DoubleLinkedNode *traverseHead = head->next;
    DoubleLinkedNode *traverseNew = newHead;

    while (traverseHead) {
        traverseNew->next = new DoubleLinkedNode(traverseHead->data, traverseNew);
        traverseHead = traverseHead->next;
        traverseNew = traverseNew->next;
    }

    return newHead;
}

DoubleLinkedNode *reverse(const DoubleLinkedNode *head) {
    DoubleLinkedNode *newHead = clone(head);
    DoubleLinkedNode *secondLast = getSecondLast(newHead);

    DoubleLinkedNode *reverseHead = secondLast->next;
    secondLast->next = nullptr;

    reverseHead->prev = nullptr;
    reverseHead->next = nullptr;

    DoubleLinkedNode *traverseReverse = reverseHead;

    while (newHead->next) {
        secondLast = getSecondLast(newHead);
        traverseReverse->next = secondLast->next;
        secondLast->next->prev = traverseReverse;

        secondLast->next = nullptr;

        traverseReverse->next->next = newHead;
        newHead->prev = traverseReverse->next;

        traverseReverse = traverseReverse->next;
    }

    return reverseHead;
}

void mirror(DoubleLinkedNode *head) {
    DoubleLinkedNode *secondLast = getSecondLast(head);

    secondLast->next->next = reverse(head);
    secondLast->next->next->prev = secondLast->next;
}

void destroy(DoubleLinkedNode *head) {
    while (head) {
        DoubleLinkedNode *deletion = head;
        head = head->next;
        delete deletion;
    }
}