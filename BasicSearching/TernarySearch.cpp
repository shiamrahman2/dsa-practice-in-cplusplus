#include<bits/stdc++.h>
using namespace std;

int ternarySearch(int arr[], int l, int r, int target) {
    while (l <= r) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        if (arr[mid1] == target)
            return mid1;

        if (arr[mid2] == target)
            return mid2;

        if (target < arr[mid1]) {
            r = mid1 - 1;
        }
        else if (target > arr[mid2]) {
            l = mid2 + 1;
        }
        else {
            l = mid1 + 1;
            r = mid2 - 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int n = sizeof(arr) / sizeof(arr[0]);

    int target = 10;

    int idx = ternarySearch(arr, 0, n - 1, target);

    if (idx != -1)
        cout << "Found at index " << idx << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}