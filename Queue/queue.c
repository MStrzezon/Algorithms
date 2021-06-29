#include "queue.h"

double queue[100];
int start = 0, end = 0, el = 0, length = 100;

void enqueue(double a) {
    if(el == length) return;
    queue[end++] = a;
    el++;
    if(end == length) end = 0;
}

double dequeue() {
    if(el == 0) return -997;
    el--;
    double helper = queue[start++];
    if(start == length) start = 0;
    return helper;
}