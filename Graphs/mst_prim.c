#include "mst_prim.h"

void mst_prim(struct edge *ed, int s, int n, struct el_listy3 **successor, int *predecessor) {
    int visited[n];
    struct edge heap[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        predecessor[i] = -1;
    }
    int heap_size = 0;
    visited[s] = 1;
    for (struct el_listy3 *wsk = successor[s]; wsk; wsk = wsk->nast) {
        wstaw_e(heap, wsk->e, &heap_size);
    }
    while(heap_size > 0)
    {
        struct edge kr = min_v_delete(heap, &heap_size);
        if(visited[kr.v]==0)
        {
            visited[kr.v]=1;
            predecessor[kr.v]=kr.u;
            for(struct el_listy3 * wsk=successor[kr.v]; wsk; wsk= wsk->nast)
            {
                wstaw_e(heap, wsk->e, &heap_size);
            }
        }
    }
}