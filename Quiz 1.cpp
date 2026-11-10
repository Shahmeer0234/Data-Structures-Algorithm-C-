#include <iostream>
using namespace std;

void InsertAtEnd(int value, int arr[], int size) {
	
	arr[size++] = value;
	
}

void InsertAtPosition(int pos, int value, int arr[], int size) {
	for (int i=size; i<pos; i--){
		arr[i] = arr[i - 1];
		arr[pos] = value;
		size++;
	}
}

void Search(int size, int key, int arr[]) {
	for (int i=0; i<size; i++) {
		if (arr[i] == key) {
			cout<< i;
		}
	}
}

void Update(int pos, int value, int arr[]) {
	arr[pos] = value;
}

void Delete(int pos, int arr[], int size) {
	for (int i=pos; i<size-1; i++) {
		arr[i] = arr[i+1];
		size--;
	}
}

int main() {
	int arr[100];
	int size = 100;
	
	InsertAtEnd(9, arr, size);
	
	InsertAtPosition(9, 65, arr, 100);
	
	Search(100, 9, arr);
	
	Update(9, 78, arr);
	
	Delete(9, arr, 100);
	
	return 0;
}