#include <bits/stdc++.h>
using namespace std;

void insertionSort(int *arr, int n) {
    for (int starting = 1; starting < n; starting++) {
        int current = arr[starting];
        int previous = starting - 1;

        // Move elements greater than current one step ahead
        while (previous >= 0 && arr[previous] > current) {
            arr[previous + 1] = arr[previous];
            previous--;
        }
        arr[previous + 1] = current;
    }
}

int main() {
    int arr[] = {10, 9, 4, 5, 2, 2, 4, 5, 3};
    int n = sizeof(arr) / sizeof(int);

    insertionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
