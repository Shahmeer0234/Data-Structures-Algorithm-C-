#include <iostream>
using namespace std;

int main() {
	int *ptr = new int(50);
	
	cout<<"Value in Heap: "<<*ptr<<endl;
	
	delete ptr;
	ptr = nullptr;
	
	return 0;
}