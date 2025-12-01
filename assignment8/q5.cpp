#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= n && arr[largest] < arr[left]) largest = left;
    if (right <= n && arr[largest] < arr[right]) largest = right;
    if (largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2; i >= 1; i--)
        heapify(arr, n, i);
}

void heapSortInc(int arr[], int n) {
    buildMaxHeap(arr, n);
    int size = n;
    while (size > 1) {
        swap(arr[1], arr[size]);
        size--;
        heapify(arr, size, 1);
    }
}

void heapSortDec(int arr[], int n) {
    heapSortInc(arr, n);
    for (int i = 1, j = n; i < j; i++, j--)
        swap(arr[i], arr[j]);
}

int main() {
    int arr[7] = {-1, 54, 53, 55, 52, 50};
    int n = 6;
    heapSortInc(arr, n);
    cout << "Increasing: ";
    for (int i = 1; i <= n; i++) cout << arr[i] << " ";
    cout << endl;

    int arr2[7] = {-1, 54, 53, 55, 52, 50};
    heapSortDec(arr2, n);
    cout << "Decreasing: ";
    for (int i = 1; i <= n; i++) cout << arr2[i] << " ";
    cout << endl;
}
