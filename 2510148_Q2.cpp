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
		
		void insertAtBeginning(int val) {
			Node *newNode = new Node(val);
			newNode->next = head;
			head = newNode;
			cout<<"Inserted successfully!"<<endl;
		}
		
		void insertAtEnd(int val) {
			Node* newNode = new Node(val);
			
			if (head == NULL) {
				head = newNode;
				cout<<"Inserted successfully!"<<endl;
				return;
			}
			Node *temp = head;
			
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = newNode;
			cout<<"Inserted successfully!"<<endl;
		}
		
		void insertAtPosition(int pos, int val) {
			if (pos <= 1 || head == NULL) {
				insertAtBeginning(val);
				return;
			}
			
			Node *newNode = new Node(val);
			Node *temp = head;
			
			for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
				temp = temp->next;
			}
			newNode->next = temp->next;
			temp->next = newNode;
			cout<<"Inserted successfully!"<<endl;
		}
		
		void removeFromBeginning() {
			if (head == NULL) {
				cout<<"List is empty!"<<endl;
				return;
			}
			Node* temp = head;
			head = head->next;
			delete temp;
			cout<<"Removed from beginning!"<<endl;
		}

		void removeFromEnd() {
			if (head == NULL) {
				cout<<"List is empty!"<<endl;
				return;
			}

			if (head->next == NULL) {
				delete head;
				head = NULL;
				cout<<"Removed from end!"<<endl;
				return;
			}

			Node *temp = head;
			while (temp->next->next != NULL) {
				temp = temp->next;
			}

			delete temp->next;
			temp->next = NULL;
			cout<<"Removed from end!"<<endl;
		}

		void removeAtPosition(int pos) {
			if (head == NULL) {
				cout<<"List is empty!"<<endl;
				return;
			}

			if (pos == 1) {
				removeFromBeginning();
				return;
			}

			Node *temp = head;
			for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
				temp = temp->next;
			}

			if (temp->next == NULL) {
				cout<<"Position out of range!"<<endl;
				return;
			}

			Node *nodeToDelete = temp->next;
			temp->next = nodeToDelete->next;
			delete nodeToDelete;
			cout<<"Removed from position "<<pos<<"!"<<endl;
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
};

int main() {
	LinkedList l;
	int choice, val, pos;

	while (true) {
		cout<<"\n--- MENU ---"<<endl;
		cout<<"1. Insert at beginning"<<endl;
		cout<<"2. Insert at end"<<endl;
		cout<<"3. Insert at specific position"<<endl;
		cout<<"4. Remove from beginning"<<endl;
		cout<<"5. Remove from end"<<endl;
		cout<<"6. Remove at specific position"<<endl;
		cout<<"7. Display list"<<endl;
		cout<<"8. Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;

		if (choice == 1) {
			cout<<"Enter value: ";
			cin>>val;
			l.insertAtBeginning(val);
		}
		else if (choice == 2) {
			cout<<"Enter value: ";
			cin>>val;
			l.insertAtEnd(val);
		}
		else if (choice == 3) {
			cout<<"Enter position: ";
			cin>>pos;
			cout<<"Enter value: ";
			cin>>val;
			l.insertAtPosition(pos, val);
		}
		else if (choice == 4) {
			l.removeFromBeginning();
		}
		else if (choice == 5) {
			l.removeFromEnd();
		}
		else if (choice == 6) {
			cout<<"Enter position: ";
			cin>>pos;
			l.removeAtPosition(pos);
		}
		else if (choice == 7) {
			l.display();
		}
		else if (choice == 8) {
			break;
		}
		else {
			cout<<"Invalid choice! Try again."<<endl;
		}
	}

	return 0;
}