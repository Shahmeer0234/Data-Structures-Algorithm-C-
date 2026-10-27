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
	public:
		Node* root;

		BST() {
			root = NULL;
		}

		void insert(int val) {
			root = insertRec(root, val);
		}

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

		void search(int key) {
			Node* result = searchRec(root, key);
			if (result != NULL) {
				cout << "Student ID " << key << " found!" << endl;
			} else {
				cout << "Student ID " << key << " not found!" << endl;
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
};

int main() {
	BST tree;
	int values[] = {50, 30, 70, 20, 40, 60, 80, 35, 45};

	for (int i = 0; i < 9; i++) {
		tree.insert(values[i]);
	}

	cout << "Search Operations:" << endl;
	tree.search(40);
	tree.search(90);

	return 0;
}