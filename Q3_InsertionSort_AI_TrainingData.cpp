#include <iostream>
using namespace std;

class Insertion{
	int arr[5];
	int r;
	
	public:
		void input() {
			r = 5;
			int tempArr[5] = {25, 10, 35, 5, 20};
			for (int i=0; i<r; i++) {
				arr[i] = tempArr[i];
			}
		}
		
		void displayOriginal() {
			cout<<"Original Array: "<<endl;
			for (int i=0; i<r; i++) {
				cout<<arr[i]<<" ";
			}
			cout<<endl<<endl;
		}
		
		void sort() {
			for (int i=1; i<r; i++) {
				
				int key = arr[i];
				int j = i-1;
				
				while (j>=0 && arr[j]>key) {
					arr[j+1] = arr[j];
					j = j-1;
				}
				
				arr[j+1] = key;
				
				cout<<"Iteration: "<<i<<endl;
				cout<<"Key: "<<key<<endl;
				cout<<"j: "<<j<<endl;
				cout<<"Array After Insertion:"<<endl;
				for (int k=0; k<r; k++) {
					cout<<arr[k]<<" ";
				}
				cout<<endl<<endl;
			}
			
			cout<<"Final Sorted Array:"<<endl;
			for (int k=0; k<r; k++) {
				cout<<arr[k]<<" ";
			}
			cout<<endl;
		}
};

int main() {
	Insertion ins;
	ins.input();
	ins.displayOriginal();
	ins.sort();
	
	return 0;
}