#include "priority_queue.h"

double max(double *arr) {
    return arr[0];
}

double max_delete(double *arr, int *heap_size) {
    if (heap_size < 0) return -1;
    double max = arr[0];
    arr[0] = arr[(*heap_size)--];
    heapify(arr, 0, *heap_size);
    return max;
}

void increase_value(double *arr, int i, double a) {
    arr[i] = a;
    while (i > 0 && arr[parent(i)] < a) {
        double tmp = arr[i];
        arr[i] = arr[parent(i)];
        arr[parent(i)] = tmp;
        i = parent(i);
    }
}

void insert(double *arr, double a, int *heap_size) {
    (*heap_size)++;
    increase_value(arr, *heap_size, a);
}
