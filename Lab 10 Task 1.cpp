#include <iostream>
using namespace std;

struct Node {
public:
	int key;
	int height;
	Node *left, *right;

	Node(int k) {
		key = k;
		height = 1;
		left = nullptr;
		right = nullptr;
	}
};

int maxVal(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

int height(Node* n) {
	if (n == nullptr) {
		return 0;
	}
	else {
		return n->height;
	}
}

int getBalance(Node* n) {
	if (n == nullptr) {
		return 0;
	}
	else {
		return height(n->left) - height(n->right);
	}
}

Node* rightRotate(Node* y) {
	Node* x = y->left;
	Node* T2 = x->right;
	x->right = y;
	y->left = T2;
	y->height = 1 + maxVal(height(y->left), height(y->right));
	x->height = 1 + maxVal(height(x->left), height(x->right));
	return x;
}

Node* leftRotate(Node* x) {
	Node* y = x->right;
	Node* T2 = y->left;
	y->left = x;
	x->right = T2;
	x->height = 1 + maxVal(height(x->left), height(x->right));
	y->height = 1 + maxVal(height(y->left), height(y->right));
	return y;
}

Node* insert(Node* node, int key) {
	if (node == nullptr) {
		return new Node(key);
	}

	if (key < node->key) {
		node->left = insert(node->left, key);
	}
	else if (key > node->key) {
		node->right = insert(node->right, key);
	}
	else {
		return node;
	}

	node->height = 1 + maxVal(height(node->left), height(node->right));
	int balance = getBalance(node);

	if (balance > 1 && key < node->left->key) {
		return rightRotate(node);
	}
	if (balance < -1 && key > node->right->key) {
		return leftRotate(node);
	}
	if (balance > 1 && key > node->left->key) {
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	if (balance < -1 && key < node->right->key) {
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

void inOrder(Node* root) {
	if (root != nullptr) {
		inOrder(root->left);
		cout << root->key << " ";
		inOrder(root->right);
	}
}

int main() {
	Node* root = nullptr;

	root = insert(root, 40);
	root = insert(root, 20);
	root = insert(root, 60);
	root = insert(root, 10);
	root = insert(root, 30);
	root = insert(root, 25);

	cout << "Inorder traversal: ";
	inOrder(root);
	cout << endl;

	return 0;
}