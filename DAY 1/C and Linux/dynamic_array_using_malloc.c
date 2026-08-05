#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) {
        arr[i] = i+1;
        printf("%d ", arr[i]);
    }

    // free up the heap allocated memory
    free(arr);
    arr = NULL; // good practice to avoid dangling pointer
    return 0;
}