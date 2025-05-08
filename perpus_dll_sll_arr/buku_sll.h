#ifndef BUKU_SLL_H
#define BUKU_SLL_H

#include "antrian_sll.h"

#define DOSEN 1
#define MAHASISWA 2
#define UMUM 3

typedef struct Buku {
    char judul[100];
    int stok;
    QueuePeminjam antrean;
    struct Buku* next;
} Buku;

typedef struct {
    Buku* head;
} ListBuku;

void initBukuList(ListBuku* lb);
void tambahBuku(ListBuku* lb, const char* judul, int stok);
Buku* cariBuku(ListBuku* lb, const char* judul);
void tambahPeminjam(ListBuku* lb, const char* judul, const char* nama, int level);
void prosesPeminjaman(ListBuku* lb, const char* judul);
void prosesPengembalian(ListBuku* lb, const char* judul);
void batalkanPeminjaman(ListBuku* lb, const char* judul, const char* nama);
void tampilkanDaftarBuku(ListBuku lb);

#endif
