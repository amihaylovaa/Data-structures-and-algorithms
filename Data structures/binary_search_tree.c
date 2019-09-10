#include <stdio.h>
#include <malloc.h>

struct tree
{
	int key;
	struct tree* left;
	struct tree* right;
};

typedef struct tree TREE;

void add_bst_node(TREE**, TREE*);
void insert_bst_node(TREE*, TREE*);
TREE* find_bst_node(TREE*, int);
void delete_bst_node(TREE*, int);
TREE* findmin(TREE*);
void inorder(TREE*);
void preorder(TREE*);
void postorder(TREE*);

void binary_search_tree()
{
	TREE* root = NULL;
	TREE* data;

	do
	{
		data = (TREE*)malloc(sizeof(TREE));
		data->left = data->right = NULL;
		printf("Enter data");
		scanf_s("%d", &data->key);

		add_bst_node(&root, data);
	} while (data->key != 0);

	int key;
	printf("\nSearch node by value");
	scanf_s("%d", &key);
	if (find_bst_node(root, key) == NULL)
		printf("\nNode with value %d does not exist", key);
	else
		printf("\nSearched value is %d", key);

	TREE* new = (TREE*)malloc(sizeof(TREE));
	new->left = new->right = NULL;
	printf("\nInsert new node");
	scanf_s("%d", &new->key);
	insert_bst_node(root, new);

	int delete_key;
	printf("\nDelete node by value:");
	scanf_s("%d", &delete_key);
	delete_bst_node(root, delete_key);

	printf("\nINORDER"); inorder(root);
	printf("\nPOSTORDER"); postorder(root);
	printf("\nPREORDER"); preorder(root);
}

void add_bst_node(TREE** root, TREE* data)
{
	if (*root == NULL)
		* root = data;

	if ((*root)->key > data->key)
		add_bst_node(&(*root)->left, data);

	if ((*root)->key < data->key)
		add_bst_node(&(*root)->right, data);

}
void postorder(TREE* root)
{
	if (root == NULL) return;

	postorder(root->left);
	postorder(root->right);
	printf("\n%d", root->key);
}

void preorder(TREE* root)
{
	if (root == NULL) return;

	printf("\n %d", root->key);
	preorder(root->left);
	preorder(root->right);
}

void inorder(TREE* root)
{
	if (root == NULL) return;

	inorder(root->left);
	printf("\n%d", root->key);
	inorder(root->right);
}

TREE* find_bst_node(TREE* root, int key)
{
	if (root == NULL) return NULL;

	if (root == NULL || root->key == key)
		return root;

	if (root->key > key)
		return find_bst_node(root->left, key);
	return find_bst_node(root->right, key);

	/*
	iterative algorithm

	while (1)
	{
		if (root == NULL || root->key == key)
		return root;

		if (root->key > key)
			root = root->left;
		else
			root = root->right;
	}
	*/
}

void insert_bst_node(TREE* root, TREE* data)
{
	if (root == NULL) return;

	if (root->key > data->key)
	{
		if (root->left == NULL)
			root->left = data;
		else
			insert_bst_node(root->left, data);
	}
	else if (root->right == NULL)
		root->right = data;
	else
		insert_bst_node(root->right, data);
}

void delete_bst_node(TREE* root, int dlt)
{
	TREE* node, * p1;

	node = find_bst_node(root, dlt);
	if (node == NULL) return;

	if (node->left == NULL && node->right == NULL)
	{
		free(node);
		return;
	}

	p1 = (node->left == NULL) ? node->right : node->left;
	*node = *p1;
	free(p1);

	if (node->left != NULL && node->right != NULL)
	{
		p1 = findmin(node->right);
		node->key = p1->key;
		delete_bst_node(p1, p1->key);
		return;
	}
}

TREE* findmin(TREE* p)
{
	if (p == NULL) return NULL;

	if (p->left == NULL) return p;

	return findmin(p->left);
}