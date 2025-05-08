#ifndef ANTRIAN_SLL_H
#define ANTRIAN_SLL_H

typedef struct Peminjam {
    char nama[100];
    int level;
    struct Peminjam* next;
} Peminjam;

typedef struct {
    Peminjam* front;
} QueuePeminjam;

void initQueue(QueuePeminjam* q);
void enqueue(QueuePeminjam* q, const char* nama, int level);
int dequeue(QueuePeminjam* q, char* namaOut);
int hapusPeminjam(QueuePeminjam* q, const char* nama);
int isQueueEmpty(QueuePeminjam* q);
void tampilkanQueue(QueuePeminjam q);

#endif
