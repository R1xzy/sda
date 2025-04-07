#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listnama.h"

KotaNode* headKota = NULL;

void inisialisasi() {
    headKota = NULL;
}

KotaNode* cariKota(const char* namaKota) {
    KotaNode* temp = headKota;
    while (temp != NULL) {
        if (strcmp(temp->namaKota, namaKota) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void tambahKota(const char* namaKota) {
    if (cariKota(namaKota) != NULL) {
        printf("Kota %s sudah ada.\n", namaKota);
        return;
    }

    KotaNode* baru = (KotaNode*)malloc(sizeof(KotaNode));
    strcpy(baru->namaKota, namaKota);
    baru->daftarNama = NULL;
    baru->next = headKota;
    headKota = baru;
}

void tambahNama(const char* namaKota, const char* namaOrang) {
    KotaNode* kota = cariKota(namaKota);
    if (kota == NULL) {
        printf("Kota %s tidak ditemukan.\n", namaKota);
        return;
    }

    NamaNode* namaBaru = (NamaNode*)malloc(sizeof(NamaNode));
    strcpy(namaBaru->nama, namaOrang);
    namaBaru->next = kota->daftarNama;
    kota->daftarNama = namaBaru;
}

void hapusKota(const char* namaKota) {
    KotaNode* prev = NULL;
    KotaNode* curr = headKota;

    while (curr != NULL) {
        if (strcmp(curr->namaKota, namaKota) == 0) {
            if (prev == NULL) {
                headKota = curr->next;
            } else {
                prev->next = curr->next;
            }

            NamaNode* p = curr->daftarNama;
            while (p != NULL) {
                NamaNode* hapus = p;
                p = p->next;
                free(hapus);
            }

            free(curr);
            printf("Kota %s dan daftar nama dihapus.\n", namaKota);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Kota %s tidak ditemukan.\n", namaKota);
}

void tampilkanSemua() {
    KotaNode* kota = headKota;
    while (kota != NULL) {
        printf("Kota: %s\n", kota->namaKota);
        NamaNode* nama = kota->daftarNama;
        while (nama != NULL) {
            printf("  - %s\n", nama->nama);
            nama = nama->next;
        }
        kota = kota->next;
    }
}

void tampilkanNamaPerKota(const char* namaKota) {
    KotaNode* kota = cariKota(namaKota);
    if (kota == NULL) {
        printf("Kota %s tidak ditemukan.\n", namaKota);
        return;
    }

    printf("Kota: %s\n", kota->namaKota);
    NamaNode* nama = kota->daftarNama;
    while (nama != NULL) {
        printf("  - %s\n", nama->nama);
        nama = nama->next;
    }
}
