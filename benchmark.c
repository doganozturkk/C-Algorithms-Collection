#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

#define SIZE 50000

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int* copyArray(int* arr, int n) {
    int* newArr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) newArr[i] = arr[i];
    return newArr;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;
        swap(&arr[minIndex], &arr[i]);
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;

    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

double measure(void (*sortFunc)(int*, int), int* arr, int n) {
    clock_t start = clock();
    sortFunc(arr, n);
    return ((double)(clock() - start)) / CLOCKS_PER_SEC;
}

double measureQuick(int* arr, int n) {
    clock_t start = clock();
    quickSort(arr, 0, n - 1);
    return ((double)(clock() - start)) / CLOCKS_PER_SEC;
}

double measureMerge(int* arr, int n) {
    clock_t start = clock();
    mergeSort(arr, 0, n - 1);
    return ((double)(clock() - start)) / CLOCKS_PER_SEC;
}

int main() {
    srand(time(NULL));

    int* original = (int*)malloc(sizeof(int) * SIZE);
    for (int i = 0; i < SIZE; i++)
        original[i] = rand() % 100000;

    printf("\n--- Benchmark Results (n = %d) ---\n", SIZE);

    int* arr;

    arr = copyArray(original, SIZE);
    printf("Bubble Sort:    %f sec\n", measure(bubbleSort, arr, SIZE));
    free(arr);

    arr = copyArray(original, SIZE);
    printf("Insertion Sort: %f sec\n", measure(insertionSort, arr, SIZE));
    free(arr);

    arr = copyArray(original, SIZE);
    printf("Selection Sort: %f sec\n", measure(selectionSort, arr, SIZE));
    free(arr);

    arr = copyArray(original, SIZE);
    printf("Merge Sort:     %f sec\n", measureMerge(arr, SIZE));
    free(arr);

    arr = copyArray(original, SIZE);
    printf("Quick Sort:     %f sec\n", measureQuick(arr, SIZE));
    free(arr);

    free(original);
    return 0;
}
