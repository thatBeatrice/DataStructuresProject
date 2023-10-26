#include "SearchTree.h"
#include <queue>
void SearchTree::insert(int key)
{
	node* newNode = new node;
	newNode->value = key;
	if (!root)
		root = newNode;
	else
	{
		node* current = root;
		while (current)
		{
			if (key == current->value)
				return;
			if (key > current->value)
			{
				if (current->right == nullptr)
				{
					current->right = newNode;
					newNode->parent = current;
					break;
				}
				current = current->right;
			}
			if (key < current->value)
			{
				if (current->left == nullptr)
				{
					current->left = newNode;
					newNode->parent = current;
					break;
				}
				current = current->left;
			}
		}
	}
}
node* SearchTree::maxim(node* x)
{
	node* current = x;
	while (current->right)
		current = current->right;
	return current;
}
node* SearchTree::minim(node* x)
{
	node* current = x;
	while (current->left)
		current = current->left;
	return current;
}
node* SearchTree::succesor(node* x)
{
	node* y = nullptr;
	if (x->right != nullptr)
		y = minim(x->right);
	else
	{
		y = x->parent;
		while (y != nullptr && x == y->right)
		{
			x = y;
			y = y->parent;
		}
	}
	return y;
}
node* SearchTree::predecesor(node* x)
{
	node* y = nullptr;
	if (x->left != nullptr)
		y = maxim(x->left);
	else
	{
		y = x->parent;
		while (y != nullptr && x == y->left)
		{
			x = y;
			y = y->parent;
		}
	}
	return y;
}
node* SearchTree::find(int key)
{
	node* current = root;
	while (current)
	{
		if (key == current->value)
			return current;
		if (key > current->value)
			current = current->right;
		else
			current = current->left;
	}
	return nullptr;
}
void SearchTree::transplant(node* u, node* v)
{
	if (u->parent == nullptr)
		root = v;
	else
		if (u == u->parent->left)
			u->parent->left = v;
		else
			u->parent->right = v;
	if (v != nullptr)
		v->parent = u->parent;
}
void SearchTree::deleteNode(int key)
{
	node* x;
	x = find(key);
	if (x != nullptr)
		erase(x);
}
void SearchTree::erase(node* x)
{
	node* y;
	if (x->left == nullptr)
		transplant(x, x->right);
	else
		if (x->right == nullptr)
			transplant(x, x->left);
		else
		{
			y = succesor(x);
			if (y != x->right)
			{
				transplant(y, y->right);
				y->right = x->right;
				x->right->parent = y;
			}
			transplant(x, y);
			y->left = x->left;
			x->left->parent = y;
		}
}
void SearchTree::preordine(node* x)
{
	if (x != nullptr)
	{
		std::cout << x->value << " ";
		preordine(x->left);
		preordine(x->right);
	}
}
void SearchTree::inordine(node* x)
{
	if (x != nullptr)
	{
		inordine(x->left);
		std::cout << x->value << " ";
		inordine(x->right);
	}
}
void SearchTree::postordine(node* x)
{
	if (x != nullptr)
	{
		postordine(x->left);
		postordine(x->right);
		std::cout << x->value << " ";
	}
}
void SearchTree::niveluri()
{
	std::queue<node*> c;
	c.push(root);
	while (!c.empty())
	{
		node* current = c.front();
		c.pop();
		std::cout << current->value << " ";
		if (current->left != nullptr)
			c.push(current->left);
		if (current->right != nullptr)
			c.push(current->right);
	}
}
void SearchTree::print_tree(int option)
{
	if (option == 1)
		preordine(root);
	else
		if (option == 2)
			inordine(root);
		else
			if (option == 3)
				postordine(root);
			else
				niveluri();
}
void SearchTree::construct(std::vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		insert(v[i]);
	}
}
bool SearchTree::empty()
{
	if (root == nullptr)
		return true;
	return false;
}
void SearchTree::clear()
{
	node* current = root;
	while (current)
	{
		erase(current);
		current = root;
	}
}
SearchTree::SearchTree()
{
	root = nullptr;
}
SearchTree::~SearchTree()
{
}
