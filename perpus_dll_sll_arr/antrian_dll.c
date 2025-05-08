#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "antrian_dll.h"

void initQueue(QueuePeminjam* q) {
    q->front = q->rear = NULL;
}

void enqueue(QueuePeminjam* q, const char* nama, int level) {
    Peminjam* baru = (Peminjam*)malloc(sizeof(Peminjam));
    strcpy(baru->nama, nama);
    baru->level = level;
    baru->next = baru->prev = NULL;

    if (!q->front) {
        q->front = q->rear = baru;
        return;
    }

    Peminjam* curr = q->front;
    while (curr && curr->level <= level) {
        curr = curr->next;
    }

    if (!curr) {
        baru->prev = q->rear;
        q->rear->next = baru;
        q->rear = baru;
    } else {
        baru->next = curr;
        baru->prev = curr->prev;
        if (curr->prev) curr->prev->next = baru;
        else q->front = baru;
        curr->prev = baru;
    }
}

int dequeue(QueuePeminjam* q, char* namaOut) {
    if (!q->front) return 0;
    Peminjam* temp = q->front;
    strcpy(namaOut, temp->nama);
    q->front = temp->next;
    if (q->front) q->front->prev = NULL;
    else q->rear = NULL;
    free(temp);
    return 1;
}

int hapusPeminjam(QueuePeminjam* q, const char* nama) {
    Peminjam* curr = q->front;
    while (curr) {
        if (strcmp(curr->nama, nama) == 0) {
            if (curr->prev) curr->prev->next = curr->next;
            else q->front = curr->next;

            if (curr->next) curr->next->prev = curr->prev;
            else q->rear = curr->prev;

            free(curr);
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

int isQueueEmpty(QueuePeminjam* q) {
    return q->front == NULL;
}

void tampilkanQueue(QueuePeminjam q) {
    Peminjam* curr = q.front;
    while (curr) {
        printf(" - %s (Level %d)\n", curr->nama, curr->level);
        curr = curr->next;
    }
}
