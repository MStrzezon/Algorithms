#ifndef ALGORITHMS_BUCKET_SORT_H
#define ALGORITHMS_BUCKET_SORT_H

#include <stdlib.h>
#include <stdio.h>

struct el_listy
{
    struct el_listy *next;
    int value;
};

struct el_listy2
{
    int next;
    int value;
};

int *bucket_sort_0(int *value, int n);
int *bucket_sort(int *values, int n);
int bucket_sort2(int *arr, int n, int buckets, struct el_listy2 *element);

#endif //ALGORITHMS_BUCKET_SORT_H
