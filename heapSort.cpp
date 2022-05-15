#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void fixDown(vector<int> &heap, int heapsize, int k) {

    while (2 * k + 1 <= heapsize) {
        int j = k * 2 + 1;
        if (j < heapsize && heap[j] < heap[j + 1])
        {
            ++j;
        }
        if (heap[k] > heap[j]) 
            return;
        else { 
            swap(heap[k], heap[j]);
            k = j;
        }
    }
}

void heapify(vector<int> &heap, int len)
{
    for (int i = len / 2 - 1; i >= 0; i--)
    {
        fixDown(heap, len - 1, i);
        for (int i = 0; i < len; i++)
        {
            cout << heap[i] << ' ';
        }
        cout << "\n";

    }

}

void heap_sort(vector<int> &heap, int len) {

    heapify(heap, len);
    for (int i = len - 1; i > 0; i--) {
        swap(heap[0], heap[i]);
        fixDown(heap, i - 1, 0);
    }
}

int main() {
    vector<int> heap = {4, 2, 5, 1, 7, 9, 14, 18, 81};
    int len = heap.size();
    heap_sort(heap, len);
    cout << "\n";
    for (int i = 0; i < len; i++)
        cout << heap[i] << ' ';
    cout << "\n";

    return 0;
}