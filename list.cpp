#include <iostream>
#include <string>

#include "list.h"

struct List::Node{
	const Post& post;
	Node * next;
	Node(const Post &post, Node * next = NULL)
	: post(post), next(next)
	{
#if (OBJ_LIST_MESSAGES)
		cout << "List::Node[" << this << "]: Node with post: " << post.getId() << " have been created!" << endl;
#endif
	}

	Node(const Node& node, Node * next = NULL)
		: post(node.post), next(next)
	{
#if (OBJ_LIST_MESSAGES)
		cout << "List::Node[" << this << "]: Node with post: " << post.getId() << " have been created by copying!" << endl;
#endif
	}
};

List::List()
: start(NULL), size(0)
{
#if (OBJ_LIST_MESSAGES)
	cout << "I create a List object" << endl;
#endif
}

List::List(const List& list)
:start(NULL), size(0)
{
	append(list);
#if (OBJ_LIST_MESSAGES)
	cout << "I create a List object by copying" << endl;
#endif
}

const unsigned int List::get_size(){
	return size;
}

void List::pushFront(Node * node){
	Node * n = new Node(*node, start);
	start = n;
	size++;
}

void List::pushFront(const Post& post){
	Node * node = new Node(post, start);
	start = node;
	size++;
}

const bool List::pop(const unsigned int index){
	if (index >= size) return false;
	if (index == 0){
		Node * temp = start;
		start = start->next;
		delete temp;
	}
	else{
		Node * temp = start;
		Node * temp2 = NULL;
		for (unsigned int s = 0; s <= index - 1; s++){
			temp = temp->next;
			temp2 = temp->next;
			if (temp->next != NULL)
				temp->next = temp->next->next;
			else
				temp->next = NULL;
		}
		delete temp2;
	}
	size--;
	return true;

}

void List::append(const List& list){
	Node * n = list.start;
	while (n != NULL){
		pushFront(n);
		n = n->next;
	}
}

void List::print(){
	Node * n = start;
	for (unsigned int i = 0; i < size; i++){
		if (n != NULL){
			n->post.print();
			n = n->next;
		}
	}
}

List::~List(){
	Node * t1, *t2;
	t1 = start;
	while (t1 != NULL){
		t2 = t1;
		t1 = t1->next;
		delete t2;
	}
#if (OBJ_LIST_MESSAGES)
	cout << "I destroy a List object" << endl;
#endif
}
