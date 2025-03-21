#include "queueB.h"
#include <stdio.h>

int main() {
    Node *front = NULL, *rear = NULL;
    int pilihan, nomorAntrian = 1;

    do {
        menu();
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Nomor antrian: %d\n", nomorAntrian);
                enqueue(&front, &rear, nomorAntrian++);
                displayQueue(front);
                break;
            case 2:
                printf("Memproses nomor antrian: %d\n", dequeue(&front, &rear));
                displayQueue(front);
                break;
            case 3:
                displayQueue(front);
                break;
            case 4:
                printf("Terima kasih!\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 4);

    destroyList(&front);  // Bersihkan memori sebelum keluar
    return 0;
}
