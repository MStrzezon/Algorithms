#include "queue_edges.h"

void heapify_e(struct edge *tab, int i, int heap_size) {
    int l = left(i), r = right(i), max_index;
    struct edge tmp;
    if(l <= heap_size && tab[l].wage < tab[i].wage) {
        max_index = l;
    }
    else {
        max_index = i;
    }

    if(r <= heap_size && tab[r].wage < tab[max_index].wage) {
        max_index = r;
    }

    if(max_index != i) {
        tmp = tab[i];
        tab[i] = tab[max_index];
        tab[max_index] = tmp;
        heapify_e(tab, max_index, heap_size);
    }
}

struct edge min_v_delete (struct edge *tab, int *heap_size)
{
//if (heap_size < 1) return -1;
    struct edge tmp_min = tab[0];
    tab[0] = tab[--(*heap_size)];
    heapify_e(tab, 0, *heap_size);
    return tmp_min;
}

void zmniejsz_wartosc_e (struct edge * tab, int i, struct edge a)
{
//if (a < tab[i]) return;
    tab[i]=a;
    while (i > 1 && tab[i].wage < tab[parent(i)].wage)
    {
        struct edge tmp = tab[i];
        tab[i] = tab[parent(i)];
        tab[parent(i)] = tmp;
        i= parent(i);
    }
}

void wstaw_e (struct edge *tab, struct edge a, int *heap_size)
{
    zmniejsz_wartosc_e (tab, *heap_size, a);
    (*heap_size)++;
}