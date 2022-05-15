#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void max_heapify(vector<int> &arr, int start, int end) {

    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) {
        if (son + 1 <= end && arr[son] < arr[son + 1])
            son++;
        if (arr[dad] > arr[son]) 
            return;
        else { 
            swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

void heap_sort(vector<int> &arr, int len) {

    for (int i = len / 2 - 1; i >= 0; i--)
        max_heapify(arr, i, len - 1);

    for (int i = len - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        max_heapify(arr, 0, i - 1);
    }
}

int main() {
    vector<int> arr = {4, 2, 5, 1, 7, 9, 14, 18, 81};
    int len = arr.size();
    heap_sort(arr, len);
    for (int i = 0; i < len; i++)
        cout << arr[i] << ' ';
    cout << endl;
    return 0;
}