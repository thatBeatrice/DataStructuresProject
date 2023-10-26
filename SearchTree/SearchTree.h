#pragma once
#include <vector>
#include <iostream>
struct node {
	int value;
	node* left = nullptr, * right = nullptr, * parent = nullptr;
	node(int key) : value(key), left(nullptr), right(nullptr), parent(nullptr) {}
	node() : value(NULL), left(nullptr), right(nullptr), parent(nullptr) {}
};
class SearchTree
{
private:
	node* root;
public:
	void insert(int key);
	node* maxim(node* x);
	node* minim(node* x);
	node* succesor(node* x);
	node* predecesor(node* x);
	node* find(int key);
	void transplant(node* u, node* v);
	void deleteNode(int key);
	void erase(node* x);
	void preordine(node* x);
	void inordine(node* x);
	void postordine(node* x);
	void niveluri();
	void print_tree(int option);
	void construct(std::vector<int> v);
	bool empty();
	void clear();
	SearchTree();
	~SearchTree();
};

