#include <iostream>
using namespace std;

class Bubble{
	int arr[5];
	int r;
	
	public:
		void input() {
			r = 5;
			int tempArr[5] = {64, 25, 12, 22, 11};
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
			
				for (int j=0; j<r-i-1; j++) {
					
					if (arr[j] > arr[j+1]) {
					
						int temp = arr[j];
						arr[j] = arr[j+1];
						arr[j+1] = temp;	
					}
				}
				cout<<"Pass "<<i+1<<":"<<endl;
				for (int k=0; k<r; k++) {
					cout<<arr[k]<<" ";
				}
				cout<<endl;
			}
			
			cout<<endl<<"Final Sorted Array:"<<endl;
			for (int k=0; k<r; k++) {
				cout<<arr[k]<<" ";
			}
			cout<<endl;
		}
};

int main() {
	Bubble b;
	b.input();
	b.displayOriginal();
	b.sort();
	
	return 0;
}