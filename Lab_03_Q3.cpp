#include <iostream>
#include <string>
using namespace std;

void IterativeBinarySearch(int arr[], int size, int key) {
	int low = 0;
	int high = size - 1;
	int iteration = 1;
	int found = 0;
	
	while(low <= high) {
		int mid = low + (high - low) / 2;
		string action = "";
		
		if (arr[mid] == key) {
			action = "key Found";
		}
		else if (arr[mid] < key) {
			action = "Search Right Half";
		}
		else {
			action = "Search Left Half";
		}
		
		cout<<"Iteration: "<<iteration<<endl;
		cout<<"Low: "<<low<<endl;
		cout<<"High: "<<high<<endl;
		cout<<"Mid: "<<mid<<endl;
		cout<<"arr[Mid]: "<<arr[mid]<<endl;
		cout<<"Action: "<<action<<endl;
		cout<<"---------------------------------------"<<endl;
		
		if (arr[mid] == key) {
			found++;
			break;
		}
		else if (arr[mid] < key) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
		
		iteration++;
	}
	
	if (found == 0) {
		cout<<"Sensor ID "<<key<<" not Found!"<<endl;
	}
}

int main() {
	int arr[] = {105, 110, 115, 120, 125, 130, 135, 140, 145, 150, 155};
	int key;
	
	cout<<"Enter Key to Search: ";
	cin>>key;
	
	int size = sizeof(arr) / sizeof(arr[0]);
	
	cout<<"=== Autonomous Vehicle Sensor ID Search ==="<<endl;
	cout<<"Searching for Sensor ID: "<<key<<endl;
	cout<<"==========================================="<<endl;
	
	IterativeBinarySearch(arr, size, key);
	
	return 0;
}