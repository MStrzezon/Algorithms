#include "binarysearch.h"

double search(const double* arr, int length, double w){
    int left = 0, right = length - 1, mid;
    while(left < right){
        mid = (right+left)/2;
        if(arr[mid] >= w) right = mid;
        else left = mid+1;
    }
    return right;
}