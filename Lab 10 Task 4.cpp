#include <iostream>
using namespace std;

void swapVal(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void heapify(int arr[], int n, int i) {
	int largest = i;
	int left = (2 * i) + 1;
	int right = (2 * i) + 2;

	if (left < n && arr[left] > arr[largest]) {
		largest = left;
	}
	if (right < n && arr[right] > arr[largest]) {
		largest = right;
	}

	if (largest != i) {
		swapVal(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void buildMaxHeap(int arr[], int n) {
	int startIdx = (n / 2) - 1;
	for (int i = startIdx; i >= 0; i--) {
		heapify(arr, n, i);
	}
}

int extractMax(int arr[], int &n) {
	if (n <= 0) {
		return -1;
	}
	else {
		int maxVal = arr[0];
		arr[0] = arr[n - 1];
		n--;
		if (n > 0) {
			heapify(arr, n, 0);
		}
		return maxVal;
	}
}

void printArray(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[] = {15, 5, 20, 2, 17, 10, 30};
	int n = 7;

	buildMaxHeap(arr, n);
	cout << "Max-Heap Array: ";
	printArray(arr, n);

	int extracted = extractMax(arr, n);
	cout << "Extracted Max: " << extracted << endl;
	cout << "Array after extraction: ";
	printArray(arr, n);

	return 0;
}