#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Merge_Sort/mergesort.h"
#include "Heap_Sort/heapsort.h"
#include "Quicksort/quicksort.h"
#include "Bucket_Sort/bucket_sort.h"
#include "Counting_Sort/countingsort.h"
#include "Insertion_Sort/insertionsort.h"
#include "Bubble_Sort/bubblesort.h"
#include "Counting_Sort/countingsort.h"
#include "Queue/queue.h"
#include "Priority_Queue/priority_queue.h"
#include "Binary_Search/binarysearch.h"
#include "Trees/binarytree.h"
#include "Trees/showtree.h"
#include "Trees/avl_tree.h"
#include "Graphs/graph_search.h"
#include "Graphs/mst_prim.h"
#include "Graphs/shortest_path.h"
#include "Graphs/queue_edges.h"

void mergesort_test() {
    double tab[20] = {43, 68, 93, 29, 34, 65, 96, 82, 39, 96, 21, 45, 69, 32, 24, 57, 18, 90, 43, 49};
    int n = 20;
    mergesort(tab, 0, 19, n);
    for (int i = 0; i < 20; i++) {
        printf("%f ", tab[i]);
    }
}

void mergesort2_test() {
    double tab[20] = {43, 68, 93, 29, 34, 65, 96, 82, 39, 96, 21, 45, 69, 32, 24, 57, 18, 90, 43, 49};
    int n = 20;
    mergesort2(tab, 0, 19, 20);
}

void mergesortiter_test() {
    double tab[20] = {43, 68, 93, 29, 34, 65, 96, 82, 39, 96, 21, 45, 69, 32, 24, 57, 18, 90, 43, 49};
    double wynik[20];
    int n = 20;
    merge_iter(tab, wynik, n);
    print_table(wynik, n);
}

void heapsort_test() {
    double tab2[20] =  {43, 68, 93, 29, 34, 65, 96, 82, 39, 96, 21, 45, 69, 32, 24, 57, 18, 90, 43, 49};
    heapsort(tab2, 20);
    print_table(tab2, 20);
}

void quicksort_test() {
    srand(1);
    double tab2[200];
    for (int i = 0; i < 200; i++) {
        tab2[i] = (int)(rand() / (RAND_MAX + 1.0) * 100.0);
    }
//    double tab2[20] =  {43, 68, 93, 29, 34, 65, 96, 82, 39, 96, 21, 45, 69, 32, 24, 57, 18, 90, 43, 49};
    quicksort(tab2, 0, 199);
    print_table(tab2, 200);
}

void bucketsort2_test() {
    int tab[10] = {1, 2, 42, 5, 34, 68, 42, 12, 23, 5};
    int n =10;
    int w;
    int liczba_kubelkow = 68;
    struct el_listy2 tab2[10] ;
    w = bucket_sort2(tab, n, liczba_kubelkow, tab2);
    for(int i =0 ; i<n;i++){
        printf("%d ",  tab2[w].value);
        w = tab2[w].next;
    }
}

void insertionsort_test() {
    int tab2[20] =  {43, 68, 93, 29, 34, 65, 96, 82, 39, 96, 21, 45, 69, 32, 24, 57, 18, 90, 43, 49};
    insertionsort(tab2, 20);
    for (int i = 0; i < 20; i++) {
        printf("%d ", tab2[i]);
    }
}

void bubblesort_test() {
    int arr[20] =  {43, 68, 93, 29, 34, 65, 96, 82, 39, 96, 21, 45, 69, 32, 24, 57, 18, 90, 43, 49};
    bubblesort(arr, 20);
    for (int i = 0; i < 20; i++) {
        printf("%d ", arr[i]);
    }
}

void countingsort1_test() {
    int arr[20] =  {43, 68, 93, 29, 34, 65, 96, 82, 39, 96, 21, 45, 69, 32, 24, 57, 18, 90, 43, 49};
    countingsort1(arr, 20, 100);
    for (int i = 0; i < 20; i++) {
        printf("%d ", arr[i]);
    }
}

void countingsort2_test() {
    int tab[] = {43, 68, 93, 29, 34, 65, 96, 82, 39, 96, 21, 45, 69, 32, 24, 57, 18, 90, 43, 49};
    countingsort2(tab, 20, 100);
    for (int i = 0; i < 20; i++) {
        printf("%d ", tab[i]);
    }
}

void bucket_sort_0_test() {
    int tab[] = {43, 68, 93, 29, 34, 65, 96, 82, 39, 96, 21, 45, 69, 32, 24, 57, 18, 90, 43, 49};
    bucket_sort_0(tab, 20);
}

void bucket_sort_test() {
    int tab[] = {43, 68, 93, 29, 34, 65, 96, 82, 39, 96, 21, 45, 69, 32, 24, 57, 18, 90, 43, 49};
    bucket_sort(tab, 20);
}

void bucket_sort_2_test() {
    struct el_listy2 tab2[20];
    int n = 20;
    int tab[] = {43, 68, 93, 29, 34, 65, 96, 82, 39, 96, 21, 45, 69, 32, 24, 57, 18, 90, 43, 49};
    int w = bucket_sort2(tab, 20, 100, tab2);
    for(int i =0 ; i<n;i++){
        printf("%d ",  tab2[w].value);
        w = tab2[w].next;
    }
}

void queue_test() {
    enqueue(7);
    enqueue(5);
    enqueue(3);
    printf("%lf\n", dequeue());
    printf("%lf\n", dequeue());
    enqueue(15);
    printf("%lf\n", dequeue());
    enqueue(1);
    printf("%lf\n", dequeue());
    printf("%lf\n", dequeue());
    printf("%lf\n", dequeue());
}

void priorityqueue_test() {
    double tab[1000];
    int heap_size =0;
    insert(tab, 7, &heap_size);
    insert(tab, 3, &heap_size);
    insert(tab, 4, &heap_size);
    insert(tab, 5, &heap_size);
    printf("%lf\n", max_delete(tab, &heap_size));
    printf("%lf\n", max_delete(tab, &heap_size));
    insert(tab, 10, &heap_size);
    printf("%lf\n", max_delete(tab, &heap_size));
    insert(tab, 2, &heap_size);
    printf("%lf\n", max_delete(tab, &heap_size));
    printf("%lf\n", max_delete(tab, &heap_size));
    printf("%lf\n", max_delete(tab, &heap_size));
}

void binarysearch_test() {
    double tab[] = {1, 2, 3, 4, 5, 6, 7, 12, 13, 14, 15};
    int dlugosc_tab = 11;
    printf("%lf", search(tab, dlugosc_tab, 12));
}

void binarytree_test() {
    struct element *root = 0;
    insert_tree(&root, 4);
    insert_tree(&root, 2);
    insert_tree(&root, 6);
    insert_tree(&root, 1);
    insert_tree(&root, 3);
    insert_tree(&root, 5);
    insert_tree(&root, 7);
    print_tree(root, 1);
}
void dsw_test() {
    struct element *root = 0;
    insert_tree(&root, 1);
    insert_tree(&root, 2);
    insert_tree(&root, 3);
    insert_tree(&root, 4);
    insert_tree(&root, 5);
    insert_tree(&root, 6);
    insert_tree(&root, 7);
    print_tree(root, 1);
    DSW(&root, 7);
    print_tree(root, 1);
    dfs_release(root);
}

void avltree_test() {
    struct element *root = 0;
    insert_avl(&root, 1);
    insert_avl(&root, 2);
    insert_avl(&root, 3);
    insert_avl(&root, 4);
    insert_avl(&root, 5);
    insert_avl(&root, 6);
    insert_avl(&root, 7);
    print_tree(root, 1);
    dfs_release(root);
}

void bfs_test() {
    struct edge edges[6] = {{0,1,1},{0,4,1},{0,3,2},{1,2,2},{3,2,2},{4,3,5}};
    int n = 5;
    int m = 6;
    int prev[n];
    int d[n];
    bfs(edges,0,n,m,prev,d);
    for(int i=0;i<n;i++){
        printf("Numer wierzcholka= %d poprzednik = %d d = %d\n",i,prev[i],d[i]);
    }
}

void bfs_better_test() {
    struct edge edges[6] = {{0,1,1},{0,4,1},{0,3,2},{1,2,2},{3,2,2},{4,3,5}};
    int n = 5;
    int m = 6;
    int prev[n];
    int d[n];
    bfs_better(edges,0,n,m,prev,d);
    for(int i=0;i<n;i++){
        printf("Numer wierzcholka= %d poprzednik = %d d = %d\n",i,prev[i],d[i]);
    }
}

void dfs_test() {
    struct edge edges[6] = {{0,1,1},{0,4,1},{0,3,2},{1,2,2},{3,2,2},{4,3,5}};
    int n = 5;
    int m = 6;
    int prev[n];
    int visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        prev[i] = -1;
    }
    dfs(edges, 0, n, m, prev, visited);
    for(int i=0;i<n;i++){
        printf("Numer wierzcholka= %d poprzednik = %d\n",i,prev[i]);
    }
}

void bellman_ford_test() {
    int s = 0;
    int n = 6;
    int m = 11;
    struct edge edges[11] = {{0, 1, 5}, {1, 3, 3}, {1, 4, 9}, {2, 0, 3}, {2, 1, -4}, {3, 4, 3},
                            {3, 5, 2}, {4, 2, -1}, {4, 5, -5}, {5, 0, 9}, {5, 2, 8}};
    int p[n];
    double d[n];
    for (int i = 0; i < n; i++) {
        p[i] = -1;
        d[i] = INFINITY;
    }
    bellman_ford(edges, s, n, m, p, d);
    for (int i = 0; i < n; i++) {
        printf("%d     %lf\n", p[i], d[i]);
    }
}

void dijkstra_test() {
    int s = 0;
    int n = 6;
    int m = 9;
    struct edge edges[9] = {{0, 1, 3}, {0, 4, 3}, {1, 2, 1}, {2, 3, 3}, {2, 5, 1},
                            {3, 1, 3}, {4, 5, 2}, {5, 0, 6}, {5, 3, 1}};
    int p[n];
    double d[n];
    for (int i = 0; i < n; i++) {
        p[i] = -1;
        d[i] = INFINITY;
    }
    dijkstra(edges, s, n, m, p, d);
    for (int i = 0; i < n; i++) {
        printf("%d     %d\n", p[i], (int)d[i]);
    }
}

void mst_prim_test() {
    int s = 0;
    int n = 8;
    int p[n];
    struct el_listy3 *nastepniki[n];
    struct edge edges[16] = {{0, 1, 5}, {0, 3, 9}, {0, 6, 3}, {1, 2, 9}, {1, 4, 8}, {1, 5, 6},
                             {1, 7, 7}, {2, 3, 9}, {2, 4, 4}, {2, 6, 5}, {2, 7, 3},
                             {3, 6, 8}, {4, 5, 2}, {4, 6, 1}, {5, 6, 6}, {6, 7, 9}};
    struct el_listy3 *pom;
    for (int i = 0; i < n; i++) {
        nastepniki[i] = NULL;
    }
    for (int i = 0; i < 16; i++) {
        pom = malloc (sizeof(struct el_listy3));
        pom->e = edges[i];
        pom->nast = nastepniki[edges[i].u];
        nastepniki[edges[i].u] = pom;
    }
    mst_prim(edges, s, n, nastepniki, p);
    for (int i = 0; i < n; i++) {
        printf("%d ", p[i]);
    }
    struct el_listy3 *ws;
    for (int i = 0; i < 8; i++) {
        ws = nastepniki[i];
        while (ws) {
            pom = ws;
            ws = ws->nast;
            free(pom);
        }
    }
}

int main() {
    bucket_sort_2_test();
    return 0;
}

