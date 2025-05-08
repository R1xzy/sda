#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "buku_dll.h"

void initBukuList(ListBuku* lb) {
    lb->head = lb->tail = NULL;
}

void tambahBuku(ListBuku* lb, const char* judul, int stok) {
    Buku* baru = (Buku*)malloc(sizeof(Buku));
    strcpy(baru->judul, judul);
    baru->stok = stok;
    initQueue(&baru->antrean);
    baru->next = NULL;
    baru->prev = lb->tail;

    if (lb->tail) lb->tail->next = baru;
    else lb->head = baru;

    lb->tail = baru;
}

Buku* cariBuku(ListBuku* lb, const char* judul) {
    Buku* b = lb->head;
    while (b != NULL) {
        if (strcmp(b->judul, judul) == 0) return b;
        b = b->next;
    }
    return NULL;
}

void tambahPeminjam(ListBuku* lb, const char* judul, const char* nama, int level) {
    Buku* b = cariBuku(lb, judul);
    if (b) enqueue(&b->antrean, nama, level);
}

void prosesPeminjaman(ListBuku* lb, const char* judul) {
    Buku* b = cariBuku(lb, judul);
    if (b && b->stok > 0) {
        char nama[100];
        if (dequeue(&b->antrean, nama)) {
            printf(">> %s meminjam buku %s\n", nama, judul);
            b->stok--;
        }
    }
}

void prosesPengembalian(ListBuku* lb, const char* judul) {
    Buku* b = cariBuku(lb, judul);
    if (b) {
        b->stok++;
        printf(">> Buku %s dikembalikan\n", judul);
        if (!isQueueEmpty(&b->antrean)) {
            prosesPeminjaman(lb, judul);
        }
    }
}

void batalkanPeminjaman(ListBuku* lb, const char* judul, const char* nama) {
    Buku* b = cariBuku(lb, judul);
    if (b && hapusPeminjam(&b->antrean, nama)) {
        printf(">> %s batal pinjam %s\n", nama, judul);
    }
}

void tampilkanDaftarBuku(ListBuku lb) {
    Buku* b = lb.head;
    while (b) {
        printf("\nJudul: %s | Stok: %d\n", b->judul, b->stok);
        tampilkanQueue(b->antrean);
        b = b->next;
    }
}
