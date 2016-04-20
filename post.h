#ifndef POST_H
#define POST_H

#include <iostream>
#include <string>

#include "data.h"
#include "date.h"

#define OBJ_P_MESSAGES 1

#define P_TITLE 1
#define P_CREATOR 2
#define P_DATE 3
#define P_TEXT 4

using namespace std;

class Post{
	unsigned int id;
	static unsigned int lastId;
	string title;
	string creator;
	Date * date;
	string text;
public:
	Post(const string, const string, const string);
	Post(const Post&);
	string get_creator() const;
	unsigned int getId() const;
	static unsigned int getLastId();
	void print() const;
	void print(const int) const;
	~Post();
};

#endif
