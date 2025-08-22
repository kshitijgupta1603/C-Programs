#include <stdio.h>

int main() {
    int arr[20];
    int x;

    printf("Enter the size of the array: ");
    scanf("%d", &x);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < x; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Reversed array: ");
    for (int i = x - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }

    return 0;
}
