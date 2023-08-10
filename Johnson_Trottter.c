#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void generatePermutations(int arr[], int n) {
    int directions[n];
    for (int i = 0; i < n; i++) {
        directions[i] = -1; // Initialize all directions to left (-1)
    }

    printArray(arr, n);

    int mobileIndex, mobileElement;
    do {
        // Find the largest mobile element and its index
        mobileIndex = -1;
        mobileElement = 0;
        for (int i = 0; i < n; i++) {
            if ((directions[i] == -1 && i > 0 && arr[i] > arr[i - 1]) ||
                (directions[i] == 1 && i < n - 1 && arr[i] > arr[i + 1])) {
                if (arr[i] > mobileElement) {
                    mobileElement = arr[i];
                    mobileIndex = i;
                }
            }
        }

        // If no mobile element found, break the loop
        if (mobileIndex == -1) {
            break;
        }

        // Swap the mobile element with its adjacent element in the direction of movement
        if (directions[mobileIndex] == -1) {
            swap(&arr[mobileIndex], &arr[mobileIndex - 1]);
            swap(&directions[mobileIndex], &directions[mobileIndex - 1]);
            mobileIndex--;
        } else {
            swap(&arr[mobileIndex], &arr[mobileIndex + 1]);
            swap(&directions[mobileIndex], &directions[mobileIndex + 1]);
            mobileIndex++;
        }

        // Change the direction for all elements greater than the mobile element
        for (int i = 0; i < n; i++) {
            if (arr[i] > mobileElement) {
                directions[i] = -directions[i];
            }
        }

        // Print the current permutation
        printArray(arr, n);

    } while (1);
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nAll permutations:\n");
    generatePermutations(arr, n);

    return 0;
}
