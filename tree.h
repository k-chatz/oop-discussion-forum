#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <string>

#define OBJ_TREE_MESSAGES 0

#include "thread.h"

class Tree{
	struct Node;
	Node * root;
	void printNode(Node *) const;
	void recInsert(Node *, const Post&);
	void recInsert(Node *, Node *);
	void recMerge(Node *);
	void destroy(Node *);
public:
	Tree(const Thread&);
	void enhance(const Tree&);
	void print() const;
	~Tree();
};

#endif
