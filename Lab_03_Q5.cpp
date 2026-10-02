#include <iostream>
using namespace std;

void SelectionSort(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		int minIndex = i;
		
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		
		int temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
		
		cout<<"Pass Number: "<<i + 1<<endl;
		cout<<"Current i: "<<i<<endl;
		cout<<"Minimum Value: "<<arr[i]<<endl;
		cout<<"Minimum Index: "<<minIndex<<endl;
		cout<<"Array After Swap: ";
		for (int k = 0; k < size; k++) {
			cout<<arr[k]<<" ";
		}
		cout<<endl;
		cout<<"---------------------------------------"<<endl;
	}
}

int main() {
	int arr[] = {45, 12, 78, 34, 9, 56};
	
	int size = sizeof(arr) / sizeof(arr[0]);
	
	cout<<"=== AI Image-Processing System (Feature Values) ==="<<endl;
	cout<<"Original Array: ";
	for (int i = 0; i < size; i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl<<"======================================="<<endl;
	
	SelectionSort(arr, size);
	
	cout<<"Sorted Array: ";
	for (int i = 0; i < size; i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}