#include <iostream>
#include <vector>

using namespace std;

void Merge(std::vector<int>& numbers, int low, int high, int mid){
    int a, b, c, d[100000];
    a = low;
    b = low;
    c = mid + 1;

    while (a <= mid && c <= high){
        if ( numbers[a] < numbers[c]){
            d[b] = numbers[a];
            b++;
            a++;
        }
        else{
            d[b] = numbers[c];
            b++;
            c++;
        }
    }

    while (a <= mid){

        d[b] = numbers[a];

        b++;
        a++;
    }

    while ( c <= high){

        d[b] = numbers[c];

        b++;
        c++;


    }

    for( a = low; a < b; a++){

        numbers[a] = d[a];

    }

}

void MergeSort(std::vector<int>& numbers, int low, int high){
    if (low < high){
    int mid;
    mid = (low+high)/2;
    MergeSort(numbers, low, mid);
    MergeSort(numbers, mid+1, high);
    Merge(numbers, low, high, mid);
    }
}


int main(){
    int cases;
    cin >> cases; 
    //cases = 3;
    for (int j = 0; j < cases; j++){
        int ArraySize;
        //ArraySize = 7;
        cin >> ArraySize;
        vector<int> numbers(ArraySize);
        for (int i = 0; i < ArraySize; i++){
            cin >> numbers[i];
        }
        int low = 0;
        int high = ArraySize-1;
    
        MergeSort(numbers, low, high);

       for (int a = 0; a < ArraySize; a++) {
        cout << numbers[a];
        if (a != ArraySize - 1) cout << " ";
        }
        cout << endl;

    }
    return 0;
}