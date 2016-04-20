#ifndef FORUM_H
#define FORUM_H

#include "date.h"
#include "tree.h"
#include "thread.h"

#define OBJ_F_MESSAGES 1

const unsigned int threads = 10;
const unsigned int posts = 10;

using namespace std;

class Forum{
	Data data;
	string title;
	Thread ** thread;
	Tree * tree;
	unsigned int threads;
public:
	Forum(const string, const int);
	Forum(const Forum&);
	const unsigned int get_posts();
	void print(const int) const;
	void print(const unsigned int) const;
	void print(const string) const;
	void print_sorted();
	~Forum();
};

#endif