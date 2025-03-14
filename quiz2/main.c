#include "amll.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Node* head = NULL;

    insertLast(&head, 10);
    insertLast(&head, 20);
    insertLast(&head, 30);
    displayList(head);

    insertFirst(&head, 5);
    insertAfter(head, 10, 15);
    insertBefore(&head, 20, 18);
    displayList(head);

    updateNode(head, 15, 17);
    displayList(head);

    deleteFirst(&head);
    deleteLast(&head);
    deleteNode(&head, 18);
    deleteAfter(&head, 10);
    displayList(head);

    return 0;
}