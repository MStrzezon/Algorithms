#include "quicksort.h"

void quicksort(double *arr, int p, int r) {
    int q;
    if (p < r) {
        q = partition(arr, p, r);
        quicksort(arr, p, q);
        quicksort(arr, q + 1, r);
    }
}

int partition(double *arr, int p, int r) {
    int i = p -1, j = r + 1;
    double q = arr[p];
    double pom;
    while(1) {
        j--;
        while(arr[j] > q) j--;
        i++;
        while (arr[i] < q) i++;
        if (i < j) {
            pom = arr[i];
            arr[i] = arr[j];
            arr[j] = pom;
        } else return j;
    }
}