#ifndef LIST_H
#define LIST_H

#define OBJ_LIST_MESSAGES 0

#include "post.h"

class List{
	struct Node;
	Node * start;
	unsigned int size;
public:
	List();
	List(const List&);
	const unsigned int get_size();
	void pushFront(const Post& post);
	void pushFront(Node *);
	const bool pop(const unsigned int);
	void append(const List&);
	void print();
	~List();
};

#endif
