Dynamic
===========================================
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *dynamicArray;
    dynamicArray = (int *)malloc(5 * sizeof(int));

    if (dynamicArray == NULL) {
        printf("Alokasi memori gagal.\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        dynamicArray[i] = i * 10;
    }

    for (int i = 0; i < 5; i++) {
        printf("dynamicArray[%d] = %d\n", i, dynamicArray[i]);
    }

    free(dynamicArray);

    return 0;
}
===============================================================
Static
===============================================================
#include <stdio.h>

int main() {
    int staticArray[5];

    for (int i = 0; i < 5; i++) {
        staticArray[i] = i * 10;
    }

    for (int i = 0; i < 5; i++) {
        printf("staticArray[%d] = %d\n", i, staticArray[i]);
    }

    return 0;
}
