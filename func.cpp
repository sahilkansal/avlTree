#include"Header.h"
#include<iostream>

using namespace std;


int max(int a, int b){ return (a > b) ? a : b; }

tree::tree(){
	head = NULL;
}

node::node(){
	info = 0;
	left = NULL;
	right = NULL;
}

node::node(int a, node *left, node*right){
	info = a;
	this->left = left;
	this->right = right;
	this->height = 1;
}

int tree::height(node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

int tree::get_balance(node*ptr){
	if (ptr == NULL){ return 0; }
	else{
		return (height(ptr->left) - height(ptr->right));
	}
}

node* tree::insert_node(node*root, int val){
	if (root == NULL){
		node *ptr = new node(val, NULL, NULL);
		return ptr;
	}
	else if (root->info>val){
		root->left=insert_node(root->left,val);
		root->height = max(height(root->left), height(root->right)) + 1;
		return root;
	}
	else if (root->info < val){
		root->right = insert_node(root->right, val);
		root->height = max(height(root->left), height(root->right)) + 1;
		return root;
	}
	root->height = max(height(root->left), height(root->right)) + 1;
	//cout <<"sahil  "<< root->height << endl;
}

node* tree::ll_rotation(node *ptr){
	node *left = ptr->left;
	node *right = left->right;

	left->right = ptr;
	ptr->left = right;

	ptr->height = max(height(ptr->left), height(ptr->right)) + 1;
	left->height = max(height(left->left), height(left->right)) + 1;
	//ptr=left;
	return left;
}

void tree::ll_rotation(){
	node *left = head->left;
	node *right = left->right;
	
	left->right = head;
	head->left = right;
	
	head->height = max(height(head->left), height(head->right)) + 1;
	left->height = max(height(left->left),height(left->right)) + 1;
	head = left;
}


void tree::rr_rotation(){
	node *right = head->right;
	node *left = right->left;

	right->left = head;
	head->right = left;

	head->height = max(height(head->left), height(head->right)) + 1;
	right->height = max(height(right->left), height(right->right)) + 1;
	head = right;
}

node* tree::rr_rotation(node *ptr){
	node *right = ptr->right;
	node *left = right->left;

	right->left = ptr;
	ptr->right = left;

	ptr->height = max(height(ptr->left), height(ptr->right)) + 1;
	right->height = max(height(right->left), height(right->right)) + 1;
	//ptr = right;
	return right;
}

void tree::insert_node(int val){
	if (head == NULL){
		node *ptr = new node(val, NULL, NULL);
		head = ptr;
	}
	else if(head->info>val){
		head->left=insert_node(head->left, val);
	}
	else{
		head->right = insert_node(head->right, val);
	}
	head->height = max(height(head->left), height(head->right)) + 1;

	int balance = get_balance(head);
	//cout << balance << endl;
	if (balance > 1&&val<head->left->info){
		ll_rotation();
	}
	if (balance < -1&&val>head->right->info){
		rr_rotation();
	}
	if (balance>1 && val > head->left->info){
		head->left=rr_rotation(head->left);
		ll_rotation();
	}
	if (balance < -1 && val < head->right->info){
		head->right=ll_rotation(head->right);
		rr_rotation();
	}
}

void tree::print_tree(node *curr){
	if (curr != NULL){
		print_tree(curr->left);
		cout << curr->info <<"        " << curr->height << endl;
		print_tree(curr->right);
	}
}


void tree::print_tree(){
	if (head != NULL){
		print_tree(head);
		cout << endl;
	}
	else{
		cout << "tree is empty" << endl;
	}
}