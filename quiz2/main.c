#include "amll.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Node* head = NULL;

    insertFirst(&head, 7);
    displayList(head);
    insertLast(&head, 11);
    displayList(head);
    insertAfter(head, 7, 9);
    displayList(head);
    insertFirst(&head, 5);
    displayList(head);
    insertLast(&head, 13);
    displayList(head);
    deleteLast(&head);
    displayList(head);
    deleteNode(&head, 7);
    deleteFirst(&head);
    displayList(head);
    destroyList(&head);
    displayList(head);
    
    return 0;
}
