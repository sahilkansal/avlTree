#include<iostream>
#include"Header.h"

using namespace std;

int main(){
	tree tr;
	tr.insert_node(10);
    tr.insert_node(20);
	tr.insert_node(30);
    tr.insert_node(40);
    //tr.insert_node(2);
	//tr.insert_node(1);
	tr.insert_node(25);
	tr.insert_node(24);
	tr.print_tree();
	cin.get();
}