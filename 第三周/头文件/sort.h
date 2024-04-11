#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 插入排序
void insertionSort(int arr[], int n);

// 归并排序
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);

// 快速排序
void quickSort(int arr[], int low, int high);

// 计数排序
void countSort(int arr[], int n);

// 基数计数排序
void radixCountSort(int arr[], int n);

// 打印数组
void printArray(int arr[], int n);

#endif /* SORT_H */
