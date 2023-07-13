#include <stdio.h>


void merge_sort(int i, int j, int a[], int arr[]) {
    if (j <= i) {
        return;
    }
    int mid = (i + j) / 2;



    merge_sort(i, mid, a, arr);
    merge_sort(mid + 1, j, a, arr);

    int left = i;
    int right = mid + 1;
    int k;


    for (k = i; k <= j; k++) {
        if (left == mid + 1) {
            arr[k] = a[right];
            right++;
        } else if (right == j + 1) {
            arr[k] = a[left];
            left++;
        } else if (a[left] < a[right]) {
            arr[k] = a[left];
            left++;
        } else {
            arr[k] = a[right];
            right++;
        }
    }

    for (k = i; k <= j; k++) {
        a[k] = arr[k];
    }
}


int main() {
  int a[100], arr[100], n, i, d, swap;

  printf("Enter number of elements in the array:\n");
  scanf("%d", &n);

  printf("Enter the numbers\n");

  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);

  merge_sort(0, n - 1, a, arr);

  printf(" the sorted array:\n");

  for (i = 0; i < n; i++)
     printf("%d\n", a[i]);

  return 0;
}
