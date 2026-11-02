#include <iostream>
using namespace std;

int main() {
	int num = 10;
	int *ptr = &num;
	
	cout<<"Value: "<<num<<endl;
	cout<<"Address: "<<&ptr<<endl;
	cout<<"Address: "<<ptr<<endl;
	cout<<"Value: "<<*ptr<<endl;
	
	*ptr = 20;
	cout<<"New Value: "<<*ptr<<endl;
	cout<<"New Address: "<<ptr<<endl;
	
	return 0;
}