#include <iostream>
using namespace std;

void BinarySearch(int arr[], int size, int key) {
	int low = 0;
	int high = size - 1;
	int found = 0;
	int comparisonCount = 0;
	
	while(low <= high) {
		int mid = low + (high - low) / 2;
		comparisonCount++;
		
		if (arr[mid] == key) {
			cout<<"Accuracy Score Found at index ["<<mid<<"]"<<endl;
			found++;
			break;
		}
		else if (arr[mid] < key) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	
	if (found == 0) {
		cout<<"Accuracy Score not Found!"<<endl;
	}
	
	cout<<"Total Comparison: "<<comparisonCount<<endl;
}

int main() {
	int arr[] = {72, 75, 78, 80, 82, 85, 87, 90, 92, 95};
	int key;
	
	cout<<"Enter Accuracy Score to Search: ";
	cin>>key;
	
	int size = sizeof(arr) / sizeof(arr[0]);
	
	BinarySearch(arr, size, key);
	
	return 0;
}