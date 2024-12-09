 #include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100
#define MAX_VALUE 100

void countingSort(int arr[], int n) {
    int output[n];
    int count[MAX_VALUE + 1] = {0};

    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    for (int i = 1; i <= MAX_VALUE; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[MAX_SIZE];
    srand(time(0));

    printf("Randomly generated array: ");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (MAX_VALUE + 1);
        printf("%d ", arr[i]);
    }
    printf("\n");

    countingSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}



#include <stdio.h>

#define MAX_SIZE 100
#define MAX_VALUE 100

void countingSort(int arr[], int n) {
    int output[n];
    int count[MAX_VALUE + 1] = {0};

    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    for (int i = 1; i <= MAX_VALUE; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[MAX_SIZE];
    printf("Enter the elements (values between 0 and %d): ", MAX_VALUE);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    countingSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

