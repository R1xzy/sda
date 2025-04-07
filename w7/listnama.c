#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listnama.h"

KotaList daftarKota[MAX_KOTA];
int jumlahKota = 0;

Node* buatNode(const char* nama) {
    Node* baru = (Node*)malloc(sizeof(Node));
    strcpy(baru->nama, nama);
    baru->next = NULL;
    return baru;
}

void inisialisasi() {
    jumlahKota = 0;
    for (int i = 0; i < MAX_KOTA; i++) {
        daftarKota[i].head = NULL;
    }
}

void tambahKota(const char* namaKota) {
    if (jumlahKota < MAX_KOTA) {
        strcpy(daftarKota[jumlahKota].kota, namaKota);
        daftarKota[jumlahKota].head = NULL;
        jumlahKota++;
    } else {
        printf("Maksimum kota telah tercapai.\n");
    }
}

void tambahNama(const char* namaKota, const char* namaOrang) {
    for (int i = 0; i < jumlahKota; i++) {
        if (strcmp(daftarKota[i].kota, namaKota) == 0) {
            Node* baru = buatNode(namaOrang);
            baru->next = daftarKota[i].head;
            daftarKota[i].head = baru;
            return;
        }
    }
    printf("Kota %s tidak ditemukan.\n", namaKota);
}

void hapusKota(const char* namaKota) {
    for (int i = 0; i < jumlahKota; i++) {
        if (strcmp(daftarKota[i].kota, namaKota) == 0) {
            Node* curr = daftarKota[i].head;
            while (curr != NULL) {
                Node* hapus = curr;
                curr = curr->next;
                free(hapus);
            }

            for (int j = i; j < jumlahKota - 1; j++) {
                daftarKota[j] = daftarKota[j + 1];
            }
            jumlahKota--;
            printf("Kota %s dan semua nama telah dihapus.\n", namaKota);
            return;
        }
    }
    printf("Kota %s tidak ditemukan.\n", namaKota);
}

void tampilkanSemua() {
    for (int i = 0; i < jumlahKota; i++) {
        printf("Kota: %s\n", daftarKota[i].kota);
        Node* curr = daftarKota[i].head;
        while (curr != NULL) {
            printf("  - %s\n", curr->nama);
            curr = curr->next;
        }
    }
}

void tampilkanNamaPerKota(const char* namaKota) {
    for (int i = 0; i < jumlahKota; i++) {
        if (strcmp(daftarKota[i].kota, namaKota) == 0) {
            printf("Kota: %s\n", daftarKota[i].kota);
            Node* curr = daftarKota[i].head;
            while (curr != NULL) {
                printf("  - %s\n", curr->nama);
                curr = curr->next;
            }
            return;
        }
    }
    printf("Kota %s tidak ditemukan.\n", namaKota);
}
