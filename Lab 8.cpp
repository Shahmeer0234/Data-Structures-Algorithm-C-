#include <iostream>
#include <string>
using namespace std;

class Fruits{
	public:
		string data;
		Fruits* left;
		Fruits* right;
		Fruits* root;
		
		Fruits(string v) {
			data = v;
			left = nullptr;
			right = nullptr;
		}
		
		void preorder(Fruits* temp) {
			
			if (temp == nullptr) {
				return;
			}
			
			cout<<temp->data<<" ";
			preorder(temp->left);
			preorder(temp->right);
			
		}
		
		void inorder(Fruits* temp) {
			
			if (temp == nullptr) {
				return;
			}
			
			inorder(temp->left);
			cout<<temp->data<<" ";
			inorder(temp->right);
			
		}
		
		void postorder(Fruits* temp) {
			
			if (temp == nullptr) {
				return;
			}
			
			postorder(temp->left);
			postorder(temp->right);
			cout<<temp->data<<" ";
			
		}
};

int main() {
	
	Fruits* root = new Fruits("Apple");
	Fruits* n2 = new Fruits("Banana");
	Fruits* n3 = new Fruits("Mango");
	Fruits* n4 = new Fruits("Orange");
	Fruits* n5 = new Fruits("Straw Berry");
	Fruits* n6 = new Fruits("Pineapple");
	Fruits* n7 = new Fruits("Peach");
	
	root->left = n2;
	root->right = n3;
	
	root->left->left = n4;
	root->left->right = n5;
	
	root->right->left = n6;
	root->right->right = n7;
	
	
	cout<<"=========Preorder=========="<<endl;
	root->preorder(root);
	
	
	cout<<"\n=========Inorder=========="<<endl;
	root->inorder(root);
	
	cout<<"\n=========Postorder========="<<endl;
	root->postorder(root);
	
	return 0;
}