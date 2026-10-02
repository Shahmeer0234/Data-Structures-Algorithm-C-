#include <iostream>
using namespace std;

void BubbleSort(int arr[], int size) {
	
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
		
		cout<<"Pass "<<i + 1<<": ";
		for (int k = 0; k < size; k++) {
			cout<<arr[k]<<" ";
		}
		cout<<endl;
	}
}

int main() {
	int arr[] = {64, 25, 12, 22, 11};
	int size = sizeof(arr) / sizeof(arr[0]);
	
	cout<<"=== AI Prediction System (Confidence Scores) ==="<<endl;
	cout<<"Original Array: ";
	for (int i = 0; i < size; i++) {
		cout<<arr[i]<<" ";
		
	cout<<endl<<"======================================"<<endl;
	
	BubbleSort(arr, size);
	
	cout<<"======================================="<<endl;
	cout<<"Sorted Array: ";
	for (int i = 0; i < size; i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}

}