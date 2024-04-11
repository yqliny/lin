#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 插入排序
void insertSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// 归并排序
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// 快速排序
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// 计数排序
void countSort(int arr[], int n) {
    int output[n];
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    int count[max + 1];
    for (int i = 0; i <= max; ++i)
        count[i] = 0;
    for (int i = 0; i < n; i++)
        count[arr[i]]++;
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// 基数计数排序
void countSortForRadix(int arr[], int n, int exp) {
    int output[n];
    int i, count[10] = { 0 };

    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixCountSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    for (int exp = 1; max / exp > 0; exp *= 10)
        countSortForRadix(arr, n, exp);
}

// 测试程序
void testSortingAlgorithm(int arr[], int n, char* algorithm) {
    clock_t begin, end;
    double time_spent;

    begin = clock();
    if (strcmp(algorithm, "Insertion Sort") == 0)
        insertSort(arr, n);
    else if (strcmp(algorithm, "Merge Sort") == 0)
        mergeSort(arr, 0, n - 1);
    else if (strcmp(algorithm, "Quick Sort") == 0)
        quickSort(arr, 0, n - 1);
    else if (strcmp(algorithm, "Count Sort") == 0)
        countSort(arr, n);
    else if (strcmp(algorithm, "Radix Count Sort") == 0)
        radixCountSort(arr, n);
    end = clock();

    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%s took %f seconds to sort %d elements.\n", algorithm, time_spent, n);
}

int main() {
    int i, n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    srand(time(NULL));
    for (i = 0; i < n; i++)
        arr[i] = rand() % 1000;

    testSortingAlgorithm(arr, n, "Insertion Sort");
    testSortingAlgorithm(arr, n, "Merge Sort");
    testSortingAlgorithm(arr, n, "Quick Sort");
    testSortingAlgorithm(arr, n, "Count Sort");
    testSortingAlgorithm(arr, n, "Radix Count Sort");

    return 0;
}
