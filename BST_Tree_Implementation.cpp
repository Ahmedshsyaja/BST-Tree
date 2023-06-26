#include<iostream>
using namespace std;
struct node {
	int data;
	node* left;
	node* right;
};
node* root = NULL;
class BST {
public:
	int search(int data) {
		node* temp = root;
		while (temp!=NULL)
		{
			if (temp->data == data) {
				return temp->data;
			}
			else if (data < temp->data) {
				temp = temp->left;
			}
			else {
				temp = temp->right;
			}
		}
		return 0;
	}
	int height(node* root) {
		if(root)
		if (root->left == NULL && root->right == NULL) {
			return 0;
		}
	}
	node* inorder(node *root) {
		if (root == NULL) {
			return NULL;
		}
		inorder(root->left);
		cout << root->data<<" ";
		inorder(root->right);
	}
	node* Prerder(node *root) {
		if (root == NULL) {
			return NULL;
		}
		cout << root->data << " ";
		Prerder(root->left);
		Prerder(root->right);
	}
	node* PostOrder(node *root) {
		if (root == NULL) {
			return NULL;
		}
		PostOrder(root->left);
		PostOrder(root->right);
		cout << root->data << " ";
	}
	void insert(int data) {
		node*temp=new node;
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;
		if (root == NULL) {
			root = temp;
		}
		else {
			node* temp1 = root;
			while (true) {
				if (temp1->data >= data) {
					if (temp1->left != NULL) {
						temp1 = temp1->left;
					}
					else {
						temp1->left = temp;
						return;
					}
				}
				else if (temp1->data < data) {
					if (temp1->right != NULL) {
						temp1 = temp1->right;
					}
					else {
						temp1->right = temp;
						return;
					}
				}
			}
		}
	}
};
int main() {
	BST a;
	while (true) {
		cout << "Enter the Respective Number To Perfrom the Operation\n";
		cout << "1 Insertation\n";
		cout << "2 Search \n";
		cout << "3 Inorder\n";
		cout << "4 preorder\n";
		cout << "5 postorder\n";
		cout << "Enter 7 To break\n";
		int in;
		cin >> in;
		if (in == 1) {
			cout << "Enter the data to insert \n";
			int data;
			cin >> data;
			a.insert(data);
		}
		if (in == 2) {
			cout << "Enter the Data you want to insert\n";
			int data1;
			cin >> data1;
			if (a.search(data1) == 0) {
				cout << "Data Not Found\n";
			} else {
				cout << "Data Found\n";
			}
		}
		if (in == 3) {
			a.inorder(root);
			cout << "\n";
		}
		if (in == 4) {
			a.Prerder(root);
			cout << "\n";
		}
		if (in == 5) {
			a.PostOrder(root);
			cout << "\n";
		}
		if (in == 7)
		{
			break;
		}
	}
}