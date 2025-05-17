#include <iostream>
#include <vector>

using namespace std;

void merge(int A[], int low, int high, int mid){
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high){
        if (A[i] < A[j]){
            c[k] = A[i];
            k++;
            i++;
        }
        else{
            c[k] = A[j];
            k++;
            j++;
        }

    }
    while (i <=mid){
        c[k] = A[i];
        k++;
        i++;

    }
    while ( i <= high){
        c[k] = A[j];
        k++;
        i++;
    }

    for (i = low; i < k; i++){

        A[i] = c[i];

    }
}

void mergeSort(int A[], int low, int high){
    if (low < high){
        int mid;

        mid = (low+high)/2;

        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge(A, low, high, mid);

    }
}

int main (){
    int arraySize = 7;
    int A[7] = {38, 27, 43, 3, 9, 82, 10};
    
    int low = 0;
    int high = arraySize-1;

    mergeSort(A, low, high);

    for (int i = 0; i < 7; i++){
        cout<< A[i]<< endl;
    }

    return 0;
}
