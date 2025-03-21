#include "amll.h"
#include <stdio.h>
#include <stdlib.h>

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->data = value;
        newNode->next = NULL;
    }
    return newNode;
}

void insertFirst(Node **head, int value) {
    Node* newNode = createNode(value);
    if (newNode != NULL) {
        newNode->next = *head;
        *head = newNode;
    }
}

void insertLast(Node **head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertBetween(Node *prevNode, int value) {
    if (prevNode == NULL) return;
    Node* newNode = createNode(value);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void insertBefore(Node **head, int beforeValue, int value) {
    if (*head == NULL) return;
    
    if ((*head)->data == beforeValue) {
        insertFirst(head, value);
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL && temp->next->data != beforeValue) {
        temp = temp->next;
    }

    if (temp->next != NULL) {
        insertBetween(temp, value);
    }
}

void insertAfter(Node *head, int afterValue, int value) {
    Node* temp = head;
    while (temp != NULL && temp->data != afterValue) {
        temp = temp->next;
    }

    if (temp != NULL) {
        insertBetween(temp, value);
    }
}

void displayList(Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void updateNode(Node *head, int oldValue, int newValue) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == oldValue) {
            temp->data = newValue;
            return;
        }
        temp = temp->next;
    }
}

void deleteFirst(Node **head) {
    if (*head == NULL) return;
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteLast(Node **head) {
    if (*head == NULL) return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteAfter(Node **head, int afterValue) {
    if (*head == NULL) return;
    
    Node* temp = *head;
    while (temp != NULL && temp->data != afterValue) {
        temp = temp->next;
    }

    if (temp != NULL && temp->next != NULL) {
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        free(toDelete);
    }
}

void deleteBefore(Node **head, int beforeValue) {
    if (*head == NULL || (*head)->next == NULL) return;

    if ((*head)->next->data == beforeValue) {
        deleteFirst(head);
        return;
    }

    Node* temp = *head;
    while (temp->next->next != NULL && temp->next->next->data != beforeValue) {
        temp = temp->next;
    }

    if (temp->next->next != NULL) {
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        free(toDelete);
    }
}

void deleteNode(Node **head, int value) {
    if (*head == NULL) return;

    if ((*head)->data == value) {
        deleteFirst(head);
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next != NULL) {
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        free(toDelete);
    }
}

void destroyList(Node **head) {
    Node *current = *head;
    Node *nextNode;

    while (current != NULL) {
        nextNode = current->next; 
        free(current);            
        current = nextNode;        
    }

    *head = NULL; 
}
