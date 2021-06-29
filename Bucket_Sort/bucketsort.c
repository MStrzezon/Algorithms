#include "bucket_sort.h"

int *bucket_sort_0(int *values, int n) {
    struct el_listy *poczatek[100];
    struct el_listy *ws;
    struct el_listy *koniec[100];
    for (int i = 0; i < 100; i++) {
        poczatek[i] = 0;
        koniec[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        ws = malloc(sizeof(struct el_listy));
        ws->value = values[i];
        ws->next = 0;
        if (poczatek[values[i]] == 0) {
            poczatek[values[i]] = ws;
            koniec[values[i]] = ws;
        }
        else {
            koniec[values[i]]->next = ws;
            koniec[values[i]] = ws;
        }
    }
    int i = 0;
    struct el_listy *ws0;
    for (i; poczatek[i] == 0; i++);
    ws = koniec[i];
    ws0 = poczatek[i];
    for (i; i < 100; i++) {
        if (poczatek[i] != 0) {
            ws->next = poczatek[i];
            ws = koniec[i];
        }
    }
    for (ws = ws0; ws != 0; ws = ws->next) {
        printf("%d ", ws->value);
    }
    struct el_listy *todel;
    ws = ws0;
    while(ws) {
        todel = ws;
        ws = ws->next;
        free(todel);
    }
}

int *bucket_sort(int *values, int n)
{
    struct el_listy *poczatek[100];
    struct el_listy *ws;
    for (int i = 0; i < 100; ++i)
    {
        poczatek[i]=0;
    }
    for (int i = 0; i < n; ++i) {
        ws= (malloc(sizeof(struct el_listy)));
        ws->value=values[i];
        ws->next=0;
        if (poczatek[values[i]]==0)
        {
            poczatek[values[i]]=ws;
        }
        else
        {
            struct el_listy *ws_pomoc = poczatek[values[i]];
            poczatek[values[i]] = ws;
            ws->next = ws_pomoc;
        }
    }
    ws=0;
    struct el_listy *ws0;
    int i=0;
    for (i ; poczatek[i]==0; ++i);
    ws0=poczatek[i];
    ws=ws0;
    ++i;
    for (; i<100 ; ++i)
    {
        if (poczatek[i]!=0){
            ws->next=poczatek[i];
            while( ws->next !=0)
            {

                ws=ws->next;
            }
        }
    }
    i = 0;
    for (struct el_listy *ws = ws0;  ws!=0; ws = ws->next) {
        values[i] = ws->value;
        i++;
    }
    for (ws = ws0; ws != 0; ws = ws->next) {
        printf("%d ", ws->value);
    }
    struct el_listy *todel;
    ws = ws0;
    while(ws) {
        todel = ws;
        ws = ws->next;
        free(todel);
    }
    return values;
}

int bucket_sort2(int *arr, int n, int buckets, struct el_listy2 *element) {
    int start[buckets + 1];
    int end[buckets + 1];
    struct el_listy2 *ws = element;
    int ws0, ws1;
    for (int i = 0; i < buckets + 1; i++) {
        start[i] = -1;
        end[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        ws->value = arr[i];
        ws->next = -1;
        if (start[ws->value] == -1) {
            start[ws->value] = i;
            end[ws->value] = i;
        } else {
            element[end[ws->value]].next = i;
            end[ws->value] = i;
        }
        ws++;
    }
    int i = 0;
    for (i = 0; start[i] == -1; i++);
    ws0 = start[i];
    ws1 = end[i];
    for (i++; i <= buckets; i++) {
        if (start[i] != -1) {
            element[ws1].next = start[i];
            ws1 = end[i];
        }
    }
    return ws0;
}