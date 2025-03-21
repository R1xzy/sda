#include "stackA.h"
#include <stdio.h>


int main() {
    int decimal;

    printf("Masukkan bilangan desimal: ");
    scanf("%d", &decimal);

    convertDecimalToBinary(decimal);

    return 0;
}
