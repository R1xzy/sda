#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "antrian_sll.h"

void initQueue(QueuePeminjam* q) {
    q->front = NULL;
}

void enqueue(QueuePeminjam* q, const char* nama, int level) {
    Peminjam* baru = (Peminjam*)malloc(sizeof(Peminjam));
    strcpy(baru->nama, nama);
    baru->level = level;
    baru->next = NULL;

    if (!q->front || level < q->front->level) {
        baru->next = q->front;
        q->front = baru;
    } else {
        Peminjam* curr = q->front;
        while (curr->next && curr->next->level <= level) {
            curr = curr->next;
        }
        baru->next = curr->next;
        curr->next = baru;
    }
}

int dequeue(QueuePeminjam* q, char* namaOut) {
    if (!q->front) return 0;
    Peminjam* temp = q->front;
    strcpy(namaOut, temp->nama);
    q->front = temp->next;
    free(temp);
    return 1;
}

int hapusPeminjam(QueuePeminjam* q, const char* nama) {
    Peminjam* curr = q->front, *prev = NULL;
    while (curr) {
        if (strcmp(curr->nama, nama) == 0) {
            if (!prev) q->front = curr->next;
            else prev->next = curr->next;
            free(curr);
            return 1;
        }
        prev = curr;
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
