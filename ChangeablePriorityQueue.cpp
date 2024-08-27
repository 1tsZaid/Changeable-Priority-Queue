#include <limits.h>

class nodeP {
    public:
    int id;
    int key;
};

class PriorityQueue {
    private:
    nodeP* heap;
    int heapSize;
    int* arr;


    void minHeapifyUp(int index) {
        if (index == 0) return;
        int parent = (index-1) / 2;

        if (heap[parent].key > heap[index].key) {
            swap(heap[parent], heap[index]);
            swap(arr[heap[parent].id], arr[heap[index].id]);

            minHeapifyUp(parent);
        }

    }
    void minHeapifyDown(int index) {
        if (heapSize / 2  - 1 < index) return;

        int l = index * 2 + 1;
        int r = index * 2 + 2;

        if (heap[index].key > heap[l].key) {
            swap(heap[l], heap[index]);
            swap(arr[heap[l].id], arr[heap[index].id]);

            minHeapifyDown(l);
        }
        else if (heap[index].key > heap[r].key) {
            swap(heap[r], heap[index]);
            swap(arr[heap[r].id], arr[heap[index].id]);

            minHeapifyDown(r);
        }
    }


    void swap(nodeP& a, nodeP& b) {
        nodeP temp = a;
        a = b;
        b = temp;
    }
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
    public:
    PriorityQueue (int x) {
        arr = new int[x];
        heap = new nodeP[x];
        for (int i = 0; i<x; i++) {
            heap[i].id = i;
            heap[i].key = INT_MAX;
            arr[i] = i;
        }

        heapSize = x;
    }
    ~PriorityQueue() {
        delete[] heap;
        delete[] arr;
    }

    int deleteMin() {
        nodeP* min = heap;
        swap(heap[0], heap[heapSize-1]);
        swap(arr[heap[0].id], arr[heap[heapSize-1].id]);
        heapSize--;
        minHeapifyDown(0);

        return min->id;
    }

    void decreaseKey(int id, int key) {
        heap[arr[id]].key = key;

        minHeapifyUp(arr[id]);
    }

    bool empty() {
        return (heapSize == 0 ? 1 : 0);
    }
};