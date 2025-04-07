#include <stdio.h>
#include "listnama.h"

int main() {
    inisialisasi();

    tambahKota("Bandung");
    tambahKota("Jakarta");

    tambahNama("Bandung", "Yahya");
    tambahNama("Bandung", "Wahab");
    tambahNama("Bandung", "Amir");

    tambahNama("Jakarta", "Hasan");
    tambahNama("Jakarta", "Badu");

    printf("\n--- Data Awal ---\n");
    tampilkanSemua();

    printf("\n--- Hapus Kota Jakarta ---\n");
    hapusKota("Jakarta");

    printf("\n--- Data Setelah Dihapus ---\n");
    tampilkanSemua();

    return 0;
}
