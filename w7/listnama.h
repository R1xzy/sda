#ifndef LISTNAMA_H
#define LISTNAMA_H

#define MAKS_NAMA 30
#define MAX_KOTA 5

typedef struct Node {
    char nama[MAKS_NAMA];
    struct Node* next;
} Node;

typedef struct {
    char kota[MAKS_NAMA];
    Node* head;
} KotaList;

void inisialisasi();
void tambahKota(const char* namaKota);
void tambahNama(const char* namaKota, const char* namaOrang);
void hapusKota(const char* namaKota);
void tampilkanSemua();
void tampilkanNamaPerKota(const char* namaKota);

#endif
