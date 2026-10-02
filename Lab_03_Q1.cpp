#include <iostream>
using namespace std;

void SequentialSearch(int arr[], int size, int key) {
	int found = 0;
	int comparisonCount = 0;
	
	for (int i=0; i<size; i++) {
		
		comparisonCount++;
		
		if (arr[i] == key) {
			cout<<"Roll Number is Found at Index ["<<i<<"]"<<endl;
			found++;
		}
	}
	
	if (found == 0) {
		cout<<"Roll Number doesn't Exists!"<<endl;
	}
	cout<<"Total Comparisons: "<<comparisonCount<<endl;
}

int main() {
	int arr[] = {101, 115, 123, 140, 156, 178, 190, 205, 218, 230};
	int key;
		
	cout<<"Enter the Roll Number to Search: ";
	cin>>key;
	
	int size = sizeof(arr) / sizeof(arr[0]);
	
	SequentialSearch(arr, size, key);
	
	return 0;
}