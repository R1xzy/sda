#include <stdio.h>
#include <string.h>
#include "buku_sll.h"
#include "undo.h"

int main() {
    ListBuku daftar;
    StackUndo undo;
    initBukuList(&daftar);
    createStack(&undo);

    // a) Tambah Buku1 dan Buku2
    tambahBuku(&daftar, "Buku1", 1);
    pushUndo(&undo, "Tambah Buku1");
    tambahBuku(&daftar, "Buku2", 1);
    pushUndo(&undo, "Tambah Buku2");

    // b) Mahasiswa ke Buku1
    tambahPeminjam(&daftar, "Buku1", "Anggota1", MAHASISWA);
    pushUndo(&undo, "Anggota1 pinjam Buku1");

    // c) Dosen ke Buku1
    tambahPeminjam(&daftar, "Buku1", "Dosen1", DOSEN);
    pushUndo(&undo, "Dosen1 pinjam Buku1");

    // d) Umum ke Buku1
    tambahPeminjam(&daftar, "Buku1", "Umum1", UMUM);
    pushUndo(&undo, "Umum1 pinjam Buku1");

    // e) Umum ke Buku2
    tambahPeminjam(&daftar, "Buku2", "Umum1", UMUM);
    pushUndo(&undo, "Umum1 pinjam Buku2");

    // f) Proses peminjaman Buku1
    prosesPeminjaman(&daftar, "Buku1");
    pushUndo(&undo, "Proses pinjam Buku1");

    // g) Pengembalian Buku1
    prosesPengembalian(&daftar, "Buku1");
    pushUndo(&undo, "Kembali Buku1");

    // h) Undo untuk batal pinjam Buku2
    char aksi[100];
    if (popUndo(&undo, aksi)) {
        if (strstr(aksi, "Umum1 pinjam Buku2")) {
            batalkanPeminjaman(&daftar, "Buku2", "Umum1");
        }
    }

    // i) Tampilkan hasil akhir
    tampilkanDaftarBuku(daftar);

    return 0;
}
