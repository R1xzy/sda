#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "buku_sll.h"

void initBukuList(ListBuku* lb) {
    lb->head = NULL;
}

void tambahBuku(ListBuku* lb, const char* judul, int stok) {
    Buku* baru = (Buku*)malloc(sizeof(Buku));
    strcpy(baru->judul, judul);
    baru->stok = stok;
    initQueue(&baru->antrean);
    baru->next = lb->head;
    lb->head = baru;
}

Buku* cariBuku(ListBuku* lb, const char* judul) {
    Buku* temp = lb->head;
    while (temp != NULL) {
        if (strcmp(temp->judul, judul) == 0) return temp;
        temp = temp->next;
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
    while (b != NULL) {
        printf("\nJudul: %s | Stok: %d\n", b->judul, b->stok);
        tampilkanQueue(b->antrean);
        b = b->next;
    }
}
