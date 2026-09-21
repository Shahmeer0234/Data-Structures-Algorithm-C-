#include <iostream>
using namespace std;

class Selection{
	int arr[6];
	int r;
	
	public:
		void input() {
			r = 6;
			int tempArr[6] = {45, 12, 78, 34, 9, 56};
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
			for (int i=0; i<r-1; i++) {
				
				int minIndex = i;
				
				for (int j=i+1; j<r; j++) {
					if (arr[j] < arr[minIndex]) {
						minIndex = j;
					}
				}
				
				int temp = arr[i];
				arr[i] = arr[minIndex];
				arr[minIndex] = temp;
				
				cout<<"Pass "<<i+1<<endl;
				cout<<"Current i: "<<i<<endl;
				cout<<"Minimum Value: "<<arr[i]<<endl;
				cout<<"Minimum Index: "<<minIndex<<endl;
				cout<<"Array After Swap:"<<endl;
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
	Selection s;
	s.input();
	s.displayOriginal();
	s.sort();
	
	return 0;
}