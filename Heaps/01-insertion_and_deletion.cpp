#include<bits/stdc++.h>
using namespace std;

class Heap {
public:
    int arr[100];
    int size;

    heap() {
        arr[0] = -1;
        size = 0;
    }

    // insertion : TC -> O(logN)
    void insert(int val) {
        size = size + 1;
        int index = size;
        arr[index] = val;

        // Max-heap
        while(index > 1) {
            // if child is greater than its parent
            int parent = index/2;
            if(arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else {
                return;
            }
        }
    }

    // deletion : TC -> O(logN)
    // deleting the root node
    void deleteFromHeap() {
        if(size == 0) {
            cout << "No element in the heap already" << "\n";
            return;
        }

        // step-1 : put last node to first index val
        arr[1] = arr[size];

        // step-2 : remove last node
        size = size - 1;

        // step-3 : take the new root node to its correct position
        int i = 1;
        while(i < size) {
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;

            if(leftIndex <= size && arr[i] < arr[leftIndex]) {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            } 
            else if(rightIndex <= size && arr[i] < arr[rightIndex]) {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else return;
        }
    }

    void print() {
        for(int i=1; i<=size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    return 0;
}

// Insertion and Deletion TC in heap is O(logN)