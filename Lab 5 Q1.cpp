#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
		
		Node(int value) {
			data = value;
			next = NULL;
		}
};

class LinkedList{
	private:
		Node* head;
	public:
		LinkedList() {
			head = NULL;
		}
		
		void InsertStart(int val) {
			Node *newNode = new Node(val);
			newNode->next = head;
			head = newNode;
		}
		
		void InsertEnd(int val) {
			Node* newNode = new Node(val);
			
			if (head == NULL) {
				head = newNode;
				return;
			}
			Node *temp = head;
			
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = newNode;
		}
		
		void search(int value) {
			Node* temp = head;
			int position = 1;

			while (temp != NULL) {
				if (temp->data == value) {
					cout<<"Value found at position: "<<position<<endl;
					return;
				}
				temp = temp->next;
				position++;
			}
			cout<<"Value not found!"<<endl;
		}
		
		void InsertCentre(int pos, int val) {
			Node *newNode = new Node(val);
			
			if (pos <= 1 || head == NULL) {
				newNode->next = head;
				head = newNode;
				return;
			}
			
			Node *temp = head;
			
			for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
				temp = temp->next;
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}
		
		void display() {
			Node* temp = head;

			if (head == NULL) {
				cout<<"List is empty!"<<endl;
				return;
			}

			while (temp != NULL) {
				cout<<temp->data<<" -> ";
				temp = temp->next;
			}
			cout<<"NULL"<<endl;
		}
    	
		void deleteNode(int value) {
			if (head == NULL) {
				cout<<"List is empty!"<<endl;
				return;
			}

			if (head->data == value) {
				Node* temp = head;
				head = head->next;
				delete temp;
				cout<<"Node deleted!"<<endl;
				return;
			}

			Node* temp = head;

			while (temp->next != NULL && temp->next->data != value) {
				temp = temp->next;
			}

			if (temp->next == NULL) {
				cout<<"Value not found!"<<endl;
				return;
			}

			Node* deleteNode = temp->next;
			temp->next = deleteNode->next;
			delete deleteNode;

			cout<<"Node deleted!"<<endl;
		}

		void sortList() {
			if (head == NULL || head->next == NULL) {
				return;
			}

			Node *i, *j;
			int temp;

			for (i = head; i != NULL; i = i->next) {
				for (j = i->next; j != NULL; j = j->next) {
					if (i->data > j->data) {
						temp = i->data;
						i->data = j->data;
						j->data = temp;
					}
				}
			}
		}
};

int main() {
	LinkedList l;
	
	l.InsertStart(6);
	l.InsertEnd(9);
	l.InsertStart(3);
	l.InsertCentre(2, 4);
		
	cout<<"Original List:"<<endl;
	l.display();

	cout<<"\nSorting the list..."<<endl;
	l.sortList();
	l.display();

	cout<<"\nSearching for 6:"<<endl;
	l.search(6);

	cout<<"\nDeleting 6:"<<endl;
	l.deleteNode(6);
	l.display();

	return 0;
}