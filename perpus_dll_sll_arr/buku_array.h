#ifndef BUKU_ARRAY_H
#define BUKU_ARRAY_H

#define MAX_BUKU 100
#define MAX_ANTRI 100

#define DOSEN 1
#define MAHASISWA 2
#define UMUM 3

typedef struct {
    char nama[100];
    int level; // prioritas
} Peminjam;

typedef struct {
    char judul[100];
    int stok;
    Peminjam antrian[MAX_ANTRI];
    int jumlahPeminjam;
} Buku;

typedef struct {
    Buku list[MAX_BUKU];
    int jumlah;
} DaftarBuku;

void initDaftar(DaftarBuku* db);
void tambahBuku(DaftarBuku* db, const char* judul, int stok);
void tambahPeminjam(DaftarBuku* db, const char* judul, const char* nama, int level);
void prosesPeminjaman(DaftarBuku* db, const char* judul);
void prosesPengembalian(DaftarBuku* db, const char* judul);
void batalkanPeminjaman(DaftarBuku* db, const char* judul, const char* nama);
void tampilkanDaftar(DaftarBuku db);

#endif
