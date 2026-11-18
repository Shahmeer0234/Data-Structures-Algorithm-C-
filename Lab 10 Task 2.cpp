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

int getHeight(Node* n) {
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
		return getHeight(n->left) - getHeight(n->right);
	}
}

Node* rightRotate(Node* y) {
	Node* x = y->left;
	Node* T2 = x->right;
	x->right = y;
	y->left = T2;
	y->height = 1 + maxVal(getHeight(y->left), getHeight(y->right));
	x->height = 1 + maxVal(getHeight(x->left), getHeight(x->right));
	return x;
}

Node* leftRotate(Node* x) {
	Node* y = x->right;
	Node* T2 = y->left;
	y->left = x;
	x->right = T2;
	x->height = 1 + maxVal(getHeight(x->left), getHeight(x->right));
	y->height = 1 + maxVal(getHeight(y->left), getHeight(y->right));
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

	node->height = 1 + maxVal(getHeight(node->left), getHeight(node->right));
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

Node* minValueNode(Node* node) {
	Node* current = node;
	while (current->left != nullptr) {
		current = current->left;
	}
	return current;
}

Node* deleteNode(Node* root, int key) {
	if (root == nullptr) {
		return root;
	}

	if (key < root->key) {
		root->left = deleteNode(root->left, key);
	}
	else if (key > root->key) {
		root->right = deleteNode(root->right, key);
	}
	else {
		if (root->left == nullptr && root->right == nullptr) {
			delete root;
			root = nullptr;
		}
		else if (root->left == nullptr) {
			Node* temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == nullptr) {
			Node* temp = root;
			root = root->left;
			delete temp;
		}
		else {
			Node* temp = minValueNode(root->right);
			root->key = temp->key;
			root->right = deleteNode(root->right, temp->key);
		}
	}

	if (root == nullptr) {
		return root;
	}

	root->height = 1 + maxVal(getHeight(root->left), getHeight(root->right));
	int balance = getBalance(root);

	if (balance > 1 && getBalance(root->left) >= 0) {
		return rightRotate(root);
	}
	if (balance > 1 && getBalance(root->left) < 0) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	if (balance < -1 && getBalance(root->right) <= 0) {
		return leftRotate(root);
	}
	if (balance < -1 && getBalance(root->right) > 0) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

bool search(Node* root, int key) {
	if (root == nullptr) {
		return false;
	}
	else if (root->key == key) {
		return true;
	}
	else if (key < root->key) {
		return search(root->left, key);
	}
	else {
		return search(root->right, key);
	}
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

	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 40);
	root = insert(root, 10);

	root = deleteNode(root, 40);

	if (search(root, 10)) {
		cout << "10 Found" << endl;
	}
	else {
		cout << "10 Not Found" << endl;
	}

	return 0;
}