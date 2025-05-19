#include <iostream>
#include <vector>
#include <utility>


using namespace std;



void Out(std::vector<int>& list){
        std::vector<std:: pair<int, int>> duplas;

        int some = 0;
        for(int i = 0; i+1 < list.size(); i+=2){
        duplas.push_back(std::make_pair(list[i], list[i+1]));

        int menor;
        int first;
        int second;
        first = list[i];
        second = list[i+1];

        if (first < second){
            menor = first;
        }
        else{
            menor = second;
        }

        some += menor;

        }
    
     cout << some << endl;


}

void Merge(std::vector<int>& list, int low, int high, int mid){
    int a, b, c;
    std::vector<int> d(list); // para evitar estourar a pilha, usa-se vector
    a = low;
    b = low;
    c = mid+1;
    
    while(a <= mid && c <= high){
        if(list[a] < list[c]){
            d[b] = list[a];
            b++;
            a++;
        }
        else{
            d[b] = list[c];
            b++;
            c++;
        }
    }

    while(a <= mid){

        d[b] = list[a];
        b++;
        a++;

    }

    while(c<= high){

        d[b] = list[c];
        b++;
        c++;
    }

    for(a = low; a < b; a++){
        list[a] = d[a];
    }
}


void MergeSort(std::vector<int>& list, int low, int high){
    if (low < high){ //pelo amor, não esquecer na EP
    int mid;
    mid = (low+high)/2;

    MergeSort(list, low, mid);
    MergeSort(list, mid+1, high);
    Merge(list, low, high, mid);
    }
}

int main(){
    int testscases;
    cin >> testscases;

    for(int i = 0; i < testscases; i++){
        int n;
        int numbers;
        cin >> n;
        numbers = 2*n;
        vector<int>list(numbers);
        for(int j = 0; j < numbers; j++){
            cin >> list[j];
        }

        int low = 0;
        int high = numbers - 1;

        MergeSort(list, low, high);
        Out(list);
    }
    return 0;

}
