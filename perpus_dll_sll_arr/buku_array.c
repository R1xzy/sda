#include <stdio.h>
#include <string.h>
#include "buku_array.h"

void initDaftar(DaftarBuku* db) {
    db->jumlah = 0;
}

void tambahBuku(DaftarBuku* db, const char* judul, int stok) {
    strcpy(db->list[db->jumlah].judul, judul);
    db->list[db->jumlah].stok = stok;
    db->list[db->jumlah].jumlahPeminjam = 0;
    db->jumlah++;
}

int indeksBuku(DaftarBuku* db, const char* judul) {
    for (int i = 0; i < db->jumlah; i++) {
        if (strcmp(db->list[i].judul, judul) == 0) return i;
    }
    return -1;
}

void tambahPeminjam(DaftarBuku* db, const char* judul, const char* nama, int level) {
    int idx = indeksBuku(db, judul);
    if (idx == -1) return;
    Buku* b = &db->list[idx];
    int pos = b->jumlahPeminjam;

    // sisipkan berdasarkan prioritas
    for (int i = 0; i < b->jumlahPeminjam; i++) {
        if (level < b->antrian[i].level) {
            pos = i;
            break;
        }
    }

    // geser ke kanan
    for (int i = b->jumlahPeminjam; i > pos; i--) {
        b->antrian[i] = b->antrian[i-1];
    }

    strcpy(b->antrian[pos].nama, nama);
    b->antrian[pos].level = level;
    b->jumlahPeminjam++;
}

void prosesPeminjaman(DaftarBuku* db, const char* judul) {
    int idx = indeksBuku(db, judul);
    if (idx == -1) return;
    Buku* b = &db->list[idx];

    if (b->stok > 0 && b->jumlahPeminjam > 0) {
        printf(">> Buku %s dipinjam oleh %s\n", judul, b->antrian[0].nama);
        for (int i = 0; i < b->jumlahPeminjam - 1; i++) {
            b->antrian[i] = b->antrian[i+1];
        }
        b->jumlahPeminjam--;
        b->stok--;
    } else {
        printf(">> Tidak bisa dipinjam.\n");
    }
}

void prosesPengembalian(DaftarBuku* db, const char* judul) {
    int idx = indeksBuku(db, judul);
    if (idx == -1) return;
    Buku* b = &db->list[idx];
    b->stok++;
    printf(">> Buku %s dikembalikan.\n", judul);
    if (b->jumlahPeminjam > 0) {
        prosesPeminjaman(db, judul);
    }
}

void batalkanPeminjaman(DaftarBuku* db, const char* judul, const char* nama) {
    int idx = indeksBuku(db, judul);
    if (idx == -1) return;
    Buku* b = &db->list[idx];
    int found = -1;
    for (int i = 0; i < b->jumlahPeminjam; i++) {
        if (strcmp(b->antrian[i].nama, nama) == 0) {
            found = i;
            break;
        }
    }
    if (found != -1) {
        for (int i = found; i < b->jumlahPeminjam - 1; i++) {
            b->antrian[i] = b->antrian[i+1];
        }
        b->jumlahPeminjam--;
        printf(">> %s batal meminjam %s\n", nama, judul);
    }
}

void tampilkanDaftar(DaftarBuku db) {
    for (int i = 0; i < db.jumlah; i++) {
        Buku b = db.list[i];
        printf("\nJudul: %s | Stok: %d\n", b.judul, b.stok);
        printf("Antrian:\n");
        for (int j = 0; j < b.jumlahPeminjam; j++) {
            printf(" - %s (Level %d)\n", b.antrian[j].nama, b.antrian[j].level);
        }
    }
}
