#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		
		Node(int v) {
			data = v;
			next = NULL;
		}
};

class CircularBusRoute{
	public:
		Node* head;
		Node* currentBus;
		
		CircularBusRoute() {
			head = NULL;
			currentBus = NULL;
		}

		~CircularBusRoute() {
			if (head == NULL) return;
			
			Node* current = head;
			Node* nextNode;
			
			do {
				nextNode = current->next;
				delete current;
				current = nextNode;
			} while (current != head);
			
			head = NULL;
		}

		Node* createNode(int value) {
			return new Node(value);
		}

		void insertAtBeginning(int value) {
			Node* newNode = createNode(value);
			
			if (head == NULL) {
				head = newNode;
				newNode->next = head;
				currentBus = head;
				return;
			}
			
			Node* temp = head;
			while (temp->next != head) {
				temp = temp->next;
			}
			
			newNode->next = head;
			temp->next = newNode;
			head = newNode;
		}

		void insertAtEnd(int value) {
			Node* newNode = createNode(value);
			
			if (head == NULL) {
				head = newNode;
				newNode->next = head;
				currentBus = head;
				return;
			}
			
			Node* temp = head;
			while (temp->next != head) {
				temp = temp->next;
			}
			
			temp->next = newNode;
			newNode->next = head;
		}

		void display() {
			if (head == NULL) {
				cout<<"Route is Empty!"<<endl;
				return;
			}
			
			Node* temp = head;
			do {
				cout<<temp->data<<" ";
				temp = temp->next;
			} while (temp != head);
			cout<<endl;
		}

		bool search(int value) {
			if (head == NULL) return false;
			
			Node* temp = head;
			int index = 1;
			do {
				if (temp->data == value) {
					cout<<"Bus Stop Found at Position ["<<index<<"]"<<endl;
					return true;
				}
				temp = temp->next;
				index++;
			} while (temp != head);
			
			cout<<"Bus Stop Not Found!"<<endl;
			return false;
		}

		void deleteFromBeginning() {
			if (head == NULL) {
				cout<<"Route is Empty!"<<endl;
				return;
			}
			
			if (head->next == head) {
				delete head;
				head = NULL;
				currentBus = NULL;
				return;
			}
			
			Node* temp = head;
			while (temp->next != head) {
				temp = temp->next;
			}
			
			Node* toDelete = head;
			head = head->next;
			temp->next = head;
			
			if (currentBus == toDelete) {
				currentBus = head;
			}
			
			delete toDelete;
		}

		void deleteFromEnd() {
			if (head == NULL) {
				cout<<"Route is Empty!"<<endl;
				return;
			}
			
			if (head->next == head) {
				delete head;
				head = NULL;
				currentBus = NULL;
				return;
			}
			
			Node* temp = head;
			Node* prev = NULL;
			
			while (temp->next != head) {
				prev = temp;
				temp = temp->next;
			}
			
			prev->next = head;
			
			if (currentBus == temp) {
				currentBus = head;
			}
			
			delete temp;
		}

		void deleteByValue(int value) {
			if (head == NULL) {
				cout<<"Route is Empty!"<<endl;
				return;
			}
			
			if (head->data == value) {
				deleteFromBeginning();
				return;
			}
			
			Node* current = head;
			Node* prev = NULL;
			
			do {
				prev = current;
				current = current->next;
				if (current->data == value) {
					prev->next = current->next;
					if (currentBus == current) {
						currentBus = current->next;
					}
					delete current;
					return;
				}
			} while (current != head);
			
			cout<<"Stop not found!"<<endl;
		}

		int countNodes() {
			if (head == NULL) return 0;
			
			int count = 0;
			Node* temp = head;
			do {
				count++;
				temp = temp->next;
			} while (temp != head);
			
			return count;
		}

		void nextStop() {
			if (currentBus != NULL) {
				cout<<"Bus moved from Stop ["<<currentBus->data<<"] to Stop [";
				currentBus = currentBus->next;
				cout<<currentBus->data<<"]"<<endl;
			}
		}
};

int main() {
	
	CircularBusRoute route;
	
	route.insertAtBeginning(10);
	route.insertAtEnd(20);
	route.insertAtEnd(30);
	route.insertAtEnd(40);
	
	cout<<"Circular Route: ";
	route.display();
	
	cout<<"Count Stops: "<<route.countNodes()<<endl;
	
	route.search(30);
	
	route.nextStop();
	route.nextStop();
	
	cout<<"Deleting stop 20..."<<endl;
	route.deleteByValue(20);
	route.display();
		
	return 0;
}