#include "countingsort.h"

void countingsort1(int *tab, int n, int k) {
    int c[k], wynik[n];
    int i;
    for (int i = 0; i < n; i++) wynik[i] = 0;
    for (i = 0; i < k; i++) c[i] = 0;
    for (i = 0; i < n; i++) c[tab[i]] += 1;
    for (i = 1; i < k; i++) c[i] += c[i-1];
    for (i = 0; i < n; i++) {
        wynik[c[tab[i]]-1] = tab[i];
        c[tab[i]] -= 1;
    }
    for (int j = 0; j < n; j++) {
        tab[j] = wynik[j];
    }
}

void countingsort2(int *tab, int n, int k) {
    int c[100], wynik[20];
    int i, it_wynik=0;
    for (i = 0; i < k; i++) c[i] = 0;
    for (i = 0; i < n; i++) c[tab[i]]++;
    for(int j=0; j<k; j++) {
        for (int h = 0; h < c[j]; h++) {
            wynik[it_wynik++] = j;
        }
    }
    for (int j = 0; j < n; j++) {
        tab[j] = wynik[j];
    }
}