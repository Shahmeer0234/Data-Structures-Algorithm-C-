#include <iostream>
using namespace std;

void swapVal(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

struct MaxHeap {
public:
	int heap[100];
	int size;

	MaxHeap() {
		size = 0;
	}

	int parent(int i) {
		return (i - 1) / 2;
	}

	int leftChild(int i) {
		return (2 * i) + 1;
	}

	int rightChild(int i) {
		return (2 * i) + 2;
	}

	void heapifyUp(int index) {
		while (index > 0 && heap[parent(index)] < heap[index]) {
			swapVal(heap[parent(index)], heap[index]);
			index = parent(index);
		}
	}

	void heapifyDown(int index) {
		int largest = index;
		int left = leftChild(index);
		int right = rightChild(index);

		if (left < size && heap[left] > heap[largest]) {
			largest = left;
		}
		if (right < size && heap[right] > heap[largest]) {
			largest = right;
		}

		if (largest != index) {
			swapVal(heap[index], heap[largest]);
			heapifyDown(largest);
		}
	}

	void insert(int key) {
		heap[size] = key;
		heapifyUp(size);
		size++;
	}

	int peekMax() {
		if (size == 0) {
			return -1;
		}
		else {
			return heap[0];
		}
	}

	int extractMax() {
		if (size == 0) {
			return -1;
		}
		else {
			int maxVal = heap[0];
			heap[0] = heap[size - 1];
			size--;
			if (size > 0) {
				heapifyDown(0);
			}
			return maxVal;
		}
	}

	void printArray() {
		for (int i = 0; i < size; i++) {
			cout << heap[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	MaxHeap h;

	h.insert(18);
	h.insert(35);
	h.insert(12);
	h.insert(40);
	h.insert(25);
	h.insert(50);

	cout << "Heap Array after insertions: ";
	h.printArray();

	cout << "Extracted 1st Max: " << h.extractMax() << endl;
	cout << "Array after 1st extraction: ";
	h.printArray();

	cout << "Extracted 2nd Max: " << h.extractMax() << endl;
	cout << "Array after 2nd extraction: ";
	h.printArray();

	return 0;
}