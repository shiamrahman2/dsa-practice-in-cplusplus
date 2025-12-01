#include<bits/stdc++.h>
using namespace std;

void CountingSort(int arr[], int n){
    int minValue = INT_MAX;
    int maxValue = INT_MIN;

    for(int i = 0; i < n; i++){
        minValue = min(minValue, arr[i]);
        maxValue = max(maxValue, arr[i]);
    }

    int range = maxValue + 1;

    vector<int> freq(range, 0);  

    for(int i = 0; i < n; i++){
        freq[arr[i]]++;
    }

    int j = 0;
    for(int i = minValue; i <= maxValue; i++){
        while(freq[i] > 0){
            arr[j++] = i;
            freq[i]--;
        }
    }
}

void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[]={3,4,2,3,6,3,2,1,5,2,5,23,52};
    int n = sizeof(arr)/sizeof(int);

    CountingSort(arr, n);
    printArr(arr, n);

    return 0;
}
