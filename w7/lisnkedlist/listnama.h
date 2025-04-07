#ifndef LISTNAMA_H
#define LISTNAMA_H

#define MAKS_NAMA 30

typedef struct NamaNode {
    char nama[MAKS_NAMA];
    struct NamaNode* next;
} NamaNode;

typedef struct KotaNode {
    char namaKota[MAKS_NAMA];
    NamaNode* daftarNama;
    struct KotaNode* next;
} KotaNode;

// Fungsi-fungsi ADT
void inisialisasi();
void tambahKota(const char* namaKota);
void tambahNama(const char* namaKota, const char* namaOrang);
void hapusKota(const char* namaKota);
void tampilkanSemua();
void tampilkanNamaPerKota(const char* namaKota);

#endif
