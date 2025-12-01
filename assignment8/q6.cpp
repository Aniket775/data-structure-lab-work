#include <iostream>
using namespace std;

struct PriorityQueueHeap {
    static const int MAXN = 1000;
    int arr[MAXN];
    int size;

    PriorityQueueHeap() {
        size = 0;
    }

    bool empty() {
        return size == 0;
    }

    int top() {
        if (size == 0) return -1;
        return arr[1];
    }

    void push(int x) {
        if (size + 1 >= MAXN) return;
        size++;
        arr[size] = x;
        int i = size;
        while (i > 1 && arr[i / 2] < arr[i]) {
            swap(arr[i / 2], arr[i]);
            i /= 2;
        }
    }

    void heapify(int i) {
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;

        if (left <= size && arr[left] > arr[largest]) largest = left;
        if (right <= size && arr[right] > arr[largest]) largest = right;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }

    void pop() {
        if (size == 0) return;
        arr[1] = arr[size];
        size--;
        heapify(1);
    }
};

int main() {
    PriorityQueueHeap pq;
    pq.push(10);
    pq.push(5);
    pq.push(20);
    pq.push(7);

    cout << "Priority queue (max-heap order): ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}
