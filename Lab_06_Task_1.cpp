#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		Node* prev;
		
		Node(int v) {
			data = v;
			next = NULL;
			prev = NULL;
		}
};

class DoublyStudentList{
	public:
		Node* head;
		
		DoublyStudentList() {
			head = NULL;
		}
		
		~DoublyStudentList() {
			while (head != NULL) {
				deleteFromBeginning();
			}
		}

		Node* createNode(int value) {
			return new Node(value);
		}
		
		void InsertAtBeginning(int val) {
			Node* newNode = createNode(val);
			
			if (head == NULL) {
				head = newNode;
				return;
			}
			
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
		
		void insertAtEnd(int value) {
			Node* newNode = createNode(value);
			
			if (head == NULL) {
				head = newNode;
				return;
			}
			
			Node* n = head;
			while(n->next != NULL) {
				n = n->next;
			}
			
			n->next = newNode;
			newNode->prev = n;
		}
		
		void Display_Forward() {
			if (head == NULL) {
				cout<<"List is Empty!"<<endl;
				return;
			}
			
			Node* n = head;
			while(n != NULL) {
				cout<<n->data<<" ";
				n = n->next;
			}
			cout<<endl;
		}
		
		void Display_Backward() {
			if (head == NULL) {
				cout<<"List is Empty!"<<endl;
				return;
			}
			
			Node* n = head;
			while(n->next != NULL) {
				n = n->next;
			}
			
			while(n != NULL) {
				cout<<n->data<<" ";
				n = n->prev;
			}
			cout<<endl;
		}
		
		bool Search(int value) {
			Node* n = head;
			int index = 1;
			while (n != NULL) {
				if (n->data == value) {
					cout<<"Student Found at Position ["<<index<<"]"<<endl;
					return true;
				}
				n = n->next;
				index++;
			}
			cout<<"Student Not Found!"<<endl;
			return false;
		}

		void deleteFromBeginning() {
			if (head == NULL) {
				cout<<"List is Empty!"<<endl;
				return;
			}
			
			Node* temp = head;
			head = head->next;
			
			if (head != NULL) {
				head->prev = NULL;
			}
			
			delete temp;
		}

		void deleteFromEnd() {
			if (head == NULL) {
				cout<<"List is Empty!"<<endl;
				return;
			}
			
			if (head->next == NULL) {
				delete head;
				head = NULL;
				return;
			}
			
			Node* n = head;
			while (n->next != NULL) {
				n = n->next;
			}
			
			n->prev->next = NULL;
			delete n;
		}

		void deleteByValue(int value) {
			if (head == NULL) {
				cout<<"List is Empty!"<<endl;
				return;
			}
			
			Node* n = head;
			
			while (n != NULL && n->data != value) {
				n = n->next;
			}
			
			if (n == NULL) {
				cout<<"Value not found in list!"<<endl;
				return;
			}
			
			if (n == head) {
				deleteFromBeginning();
				return;
			}
			
			if (n->next == NULL) {
				deleteFromEnd();
				return;
			}
			
			n->prev->next = n->next;
			n->next->prev = n->prev;
			delete n;
		}

		int countNodes() {
			int count = 0;
			Node* n = head;
			while (n != NULL) {
				count++;
				n = n->next;
			}
			return count;
		}
};

int main() {
	
	DoublyStudentList l;
	
	l.InsertAtBeginning(101);
	l.InsertAtBeginning(100);
	l.insertAtEnd(102);
	l.insertAtEnd(103);
	
	cout<<"Forward Display: ";
	l.Display_Forward();
	
	cout<<"Backward Display: ";
	l.Display_Backward();
	
	cout<<"Count Students: "<<l.countNodes()<<endl;
	
	l.Search(102);
	
	cout<<"Deleting from beginning..."<<endl;
	l.deleteFromBeginning();
	l.Display_Forward();
	
	cout<<"Deleting from end..."<<endl;
	l.deleteFromEnd();
	l.Display_Forward();
	
	cout<<"Deleting by value 102..."<<endl;
	l.deleteByValue(102);
	l.Display_Forward();
		
	return 0;
}