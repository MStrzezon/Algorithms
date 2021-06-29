#include "mergesort.h"

void print_table(const double *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
}

void merge(double *table, int l, int m, int r, int n){
    int idL = l, idR = r, idM = m + 1, k = l;
    double b[n];
    for (int x = idL; x <= r; x++){
        b[x] = table[x];
    }
    while(idL <= m && idM <= r) {
        if (b[idL] < b[idM]) {
            table[k++] = b[idL++];
        }
        else {
            table[k++] = b[idM++];
        }
    }
    while(idL <= m){
        table[k++] = b[idL++];
    }
    while(idM <= r){
        table[k++] = b[idM++];
    }
}

void mergesort(double *table, int left, int right, int n) {
    if (left < right) {
        int mid = (left + right)/2;
        mergesort(table, left, mid, n);
        mergesort(table, mid + 1, right, n);
        merge(table, left, mid, right, n);
    }
}

void mergesort2(double* table, int start, int stop, int n)
{
    int przeskok = 2, poczatek, koniec;
    while(przeskok <= stop - start)
    {
        poczatek = start;
        koniec = stop;
        for(; poczatek <= stop; poczatek += przeskok)
        {
            koniec = poczatek + przeskok - 1;
            if(koniec > stop) { koniec = stop; }
            printf("(%d, %d, %d)", poczatek, (poczatek + koniec)/2, koniec);
            merge(table, poczatek, (poczatek + koniec) / 2, koniec, n);
        }
        printf("\n");
        print_table(table, n);
        printf("\n");
        przeskok += przeskok;
        printf("Przeskok: %d\n", przeskok);
    }
    printf("(%d, %d, %d)\n", 0, (poczatek)/2 - 1, koniec);
    merge(table, 0, (poczatek) / 2 - 1, koniec, n);
    print_table(table, n);
}

double *merge_iter(double *wejscie, double *wyjscie, int n){
    int dlugosc_podciagu, poczatek_podciagu;
    int i, j, ograniczenie_i,  ograniczenie_j, k;
    double *pomoc;
    for (dlugosc_podciagu=1; dlugosc_podciagu<n; dlugosc_podciagu*=2){
        for (poczatek_podciagu=0, k=0; k<n ; poczatek_podciagu += 2*dlugosc_podciagu){
            i = poczatek_podciagu;
            j = poczatek_podciagu + dlugosc_podciagu;
            ograniczenie_i = poczatek_podciagu + dlugosc_podciagu;
            ograniczenie_j = poczatek_podciagu + 2*dlugosc_podciagu;
            if (ograniczenie_i > n) ograniczenie_i = n;
            if (ograniczenie_j > n) ograniczenie_j=n;
            while (i < ograniczenie_i && j < ograniczenie_j){
                if (wejscie[i]>=wejscie[j]) wyjscie[k++] = wejscie[j++];
                else {
                    wyjscie[k++] = wejscie[i++];
                }
            }
            while (i < ograniczenie_i){
                wyjscie[k++] = wejscie[i++];
            }
            while (j < ograniczenie_j){
                wyjscie[k++] = wejscie[j++];
            }
        }
        pomoc = wejscie;
        wejscie = wyjscie;
        wyjscie = pomoc;
    }
    return wejscie;
}



