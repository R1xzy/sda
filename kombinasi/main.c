#include "amll.h"
#include <stdio.h>


int main() {
    Node *list = NULL;
    Node *stack = NULL;
    Node *queueFront = NULL, *queueRear = NULL;

    int pilihan, subPilihan, value;

    do {
        menu();
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("\n1. Tambah Data\n2. Hapus Data\n3. Tampilkan List\nPilihan: ");
                scanf("%d", &subPilihan);
                if (subPilihan == 1) {
                    printf("Masukkan data: ");
                    scanf("%d", &value);
                    insertLast(&list, value);
                } else if (subPilihan == 2) {
                    deleteFirst(&list);
                }
                displayList(list);
                break;

            case 2:
                printf("\n1. Push Stack\n2. Pop Stack\n3. Tampilkan Stack\nPilihan: ");
                scanf("%d", &subPilihan);
                if (subPilihan == 1) {
                    printf("Masukkan data: ");
                    scanf("%d", &value);
                    push(&stack, value);
                } else if (subPilihan == 2) {
                    pop(&stack);
                }
                displayStack(stack);
                break;

            case 3:
                printf("\n1. Enqueue\n2. Dequeue\n3. Tampilkan Queue\nPilihan: ");
                scanf("%d", &subPilihan);
                if (subPilihan == 1) {
                    printf("Masukkan data: ");
                    scanf("%d", &value);
                    enqueue(&queueFront, &queueRear, value);
                } else if (subPilihan == 2) {
                    dequeue(&queueFront, &queueRear);
                }
                displayQueue(queueFront);
                break;

            case 4:
                printf("Keluar...\n");
                break;
        }
    } while (pilihan != 4);

    destroyList(&list);
    destroyList(&stack);
    destroyList(&queueFront);

    return 0;
}
