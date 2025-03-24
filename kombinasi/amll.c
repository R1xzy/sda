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
    newNode->next = *head;
    *head = newNode;
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

void displayList(Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void destroyList(Node **head) {
    while (*head != NULL) {
        deleteFirst(head);
    }
}
