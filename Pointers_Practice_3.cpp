#include <iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

int main() {
	Node *n1 = new Node();
	n1->data = 100;
	n1->next = nullptr;
	
	cout<<"Node Data: "<<n1->data<<endl;
	
	delete n1;
	
	return 0;
}