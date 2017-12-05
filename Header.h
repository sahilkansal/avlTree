struct node{
	int info;
	node *left;
	node*right;
	int height;
	node();
	node(int , node *, node*);
};

class tree{
	node*head;
	node * insert_node(node*, int);
	void print_tree(node *);
public:
	int height(node *);
	tree();
	void insert_node(int);
	void print_tree();
	int get_balance(node*);
	node* ll_rotation(node *);
	void ll_rotation();
	void rr_rotation();
	node* rr_rotation(node *);
	node *get_head()const{ return head; }
};