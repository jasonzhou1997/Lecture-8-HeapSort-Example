#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void fixDown(vector<int> &heap, int start, int end) {

    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) {
        if (son + 1 <= end && heap[son] < heap[son + 1])
            son++;
        if (heap[dad] > heap[son]) 
            return;
        else { 
            swap(heap[dad], heap[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}
void heapify(vector<int> &heap, int len)
{
    for (int i = len / 2 - 1; i >= 0; i--)
    {
        fixDown(heap, i, len - 1);
    }

}

void heap_sort(vector<int> &heap, int len) {

    heapify(heap, len);

    for (int i = len - 1; i > 0; i--) {
        swap(heap[0], heap[i]);
        fixDown(heap, 0, i - 1);
    }
}

int main() {
    vector<int> heap = {4, 2, 5, 1, 7, 9, 14, 18, 81};
    int len = heap.size();
    heap_sort(heap, len);
    for (int i = 0; i < len; i++)
        cout << heap[i] << ' ';
    cout << endl;
    return 0;
}