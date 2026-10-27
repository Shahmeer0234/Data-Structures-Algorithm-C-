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

		void display() {
			inorder(root);
			cout << endl;
		}

		void inorder(Node* node) {
			if (node != NULL) {
				inorder(node->left);
				cout << node->data << " ";
				inorder(node->right);
			}
		}
};

int main() {
	BST tree;
	int values[] = {50, 30, 70, 20, 40, 60, 80, 35, 45};

	for (int i = 0; i < 9; i++) {
		tree.insert(values[i]);
	}

	cout << "Inorder Traversal:" << endl;
	tree.display();

	return 0;
}