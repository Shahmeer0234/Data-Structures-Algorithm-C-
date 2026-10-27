#include <iostream>
using namespace std;

class Node {
	public:
		int data;
		Node* left;
		Node* right;

		Node(int val) {
			data = val;
			left = NULL;
			right = NULL;
		}
};

class BST {
	private:
		Node* root;

		Node* insertRec(Node* node, int val) {
			if (node == NULL) {
				return new Node(val);
			}
			if (val < node->data) {
				node->left = insertRec(node->left, val);
			} else if (val > node->data) {
				node->right = insertRec(node->right, val);
			}
			return node;
		}

		void inorderRec(Node* node) {
			if (node != NULL) {
				inorderRec(node->left);
				cout<<node->data<<" ";
				inorderRec(node->right);
			}
		}

		Node* searchRec(Node* node, int key) {
			if (node == NULL || node->data == key) {
				return node;
			}
			if (node->data < key) {
				return searchRec(node->right, key);
			}
			return searchRec(node->left, key);
		}

		Node* findMin(Node* node) {
			while (node->left != NULL) {
				node = node->left;
			}
			return node;
		}

		Node* deleteRec(Node* root, int key) {
			if (root == NULL) {
				return root;
			}

			if (key < root->data) {
				root->left = deleteRec(root->left, key);
			} else if (key > root->data) {
				root->right = deleteRec(root->right, key);
			} else {
				if (root->left == NULL) {
					Node* temp = root->right;
					delete root;
					return temp;
				} else if (root->right == NULL) {
					Node* temp = root->left;
					delete root;
					return temp;
				}

				Node* temp = findMin(root->right);
				root->data = temp->data;
				root->right = deleteRec(root->right, temp->data);
			}
			return root;
		}

	public:
		BST() {
			root = NULL;
		}

		void insert(int val) {
			root = insertRec(root, val);
		}

		void display() {
			inorderRec(root);
			cout<<endl;
		}

		void search(int key) {
			Node* result = searchRec(root, key);
			if (result != NULL) {
				cout<<"Value found: "<<key<<endl;
			} else {
				cout<<"Value not found!"<<endl;
			}
		}

		void remove(int key) {
			root = deleteRec(root, key);
		}
};

int main() {
	BST tree;
	int values[] = {45, 25, 65, 15, 35, 55, 75, 30, 40};

	for (int i = 0; i < 9; i++) {
		tree.insert(values[i]);
	}

	cout<<"Original BST Inorder:"<<endl;
	tree.display();

	cout<<"\nSearching for 35:"<<endl;
	tree.search(35);

	cout<<"\nDeleting 25..."<<endl;
	tree.remove(25);
	
	cout<<"Inorder after deleting 25:"<<endl;
	tree.display();

	return 0;
}