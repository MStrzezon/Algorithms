#include "heapsort.h"

int parent(int i) {
    return i/2;
}

int left(int i) {
    return 2*i + 1;
}

int right(int i) {
    return 2*i + 2;
}

void heapify(double *tab, int i, int heap_size) {
    int l = left(i);
    int r = right(i);
    int max_index;
    double pom;
    if (l <= heap_size && tab[l] > tab[i]) {
        max_index = l;
    }
    else {
        max_index = i;
    }
    if (r <= heap_size && tab[r] > tab[max_index]) {
        max_index = r;
    }
    if (max_index != i) {
        pom = tab[i];
        tab[i] = tab[max_index];
        tab[max_index] = pom;
        heapify(tab, max_index, heap_size);
    }
}

void build_heap(double *tab, int heap_size) {
    for (int i = heap_size/2; i >= 0 ; i--) {
        heapify(tab, i, heap_size);
    }
}

void heapsort(double *tab, int heap_size) {
    build_heap(tab, heap_size);
    for (int i = heap_size - 1; i >= 1; i--) {
        double tmp = tab[0];
        tab[0] = tab[i];
        tab[i] = tmp;
        heap_size -= 1;
        heapify(tab, 0, heap_size -1 );
    }
}
