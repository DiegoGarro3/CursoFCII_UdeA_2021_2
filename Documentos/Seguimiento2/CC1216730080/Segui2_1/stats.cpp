#include <iostream>
#include <iomanip>
#include <math.h>

#include "stats.h"

using namespace std;

float calc_prom(int arr[],int size){
    float prom=0;
    for(int n=0;n<size;n++){
        prom+=arr[n];
    };
    return prom/size;
}

float varianza(int arr[],int size){
    float sumSqr=0;
    float mean=calc_prom(arr,size);
    for(int n=0;n<size;n++){
        sumSqr+=pow(arr[n]-mean,2);
    };
    return sumSqr/size;
}

