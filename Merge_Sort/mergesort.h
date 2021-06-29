#ifndef CLASSES_MERGESORT_H
#define CLASSES_MERGESORT_H

#include <stdio.h>

void merge(double *table, int l, int m, int r, int n);
void mergesort(double *table, int left, int right, int n);
void mergesort2(double* table, int start, int stop, int n);
double *merge_iter(double *wejscie, double *wyjscie, int n);
void print_table(const double *arr, int n);

#endif //CLASSES_MERGESORT_H
