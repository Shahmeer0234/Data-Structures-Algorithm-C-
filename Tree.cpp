#include <iostream>
using namespace std;

class BinaryTree{
	public:
		int data;
		BinaryTree* left;
		BinaryTree* right;
		
		BinaryTree(int v) {
			data = v;
			left = NULL;
			right = NULL;
		}
		
		void preorder(BinaryTree* temp) {
			if (temp == nullptr) {
				return;
			}
			
			cout<<temp->data<<" ";
			
			preorder(temp->left);
			
			preorder(temp->right);
		}
		
		void inorder(BinaryTree* temp) {
			if (temp == nullptr) {
				return;
			}
			
			inorder(temp->left);
			
			cout<<temp->data<<" ";
			
			inorder(temp->right);
		}
		
		void postorder(BinaryTree* temp) {
			if (temp == nullptr) {
				return;
			}
			
			postorder(temp->left);
			
			postorder(temp->right);
			
			cout<<temp->data<<" ";
		}
};

int main() {
	
	BinaryTree* root = new BinaryTree(1);
	BinaryTree* n1 = new BinaryTree(2);
	BinaryTree* n2 = new BinaryTree(3);
	BinaryTree* n3 = new BinaryTree(4);
	BinaryTree* n4 = new BinaryTree(5);
	BinaryTree* n5 = new BinaryTree(6);
	BinaryTree* n6 = new BinaryTree(7);
	
	root->left = n1;
	root->right = n2;
	
	n1->left = n3;
	n1->right = n4;
	
	n2->left = n5;
	n2->right = n6;
	
	cout<<"PreOrder: "<<endl;
	root->preorder(root);
	cout<<endl;
	
	cout<<"Inorder: "<<endl;
	root->inorder(root);
	cout<<endl;
	
	cout<<"Postorder: "<<endl;
	root->postorder(root);
	cout<<endl;
	
	
	return 0;
}