#ifndef THREAD_H
#define THREAD_H

#include "date.h"
#include "post.h"

#define OBJ_T_MESSAGES 1

#define T_ALL 0
#define T_SUBJECT 1
#define T_CREATOR 2
#define T_DATE 3
#define T_POSTS 4

using namespace std;

class Thread{
	const string subject;
	string creator;
	Date * date;
	Post ** post;
	unsigned int posts;
public:
	Thread(const Data&, const string, const string, const unsigned int);
	Thread(const Thread&);
	const string& get_subject() const;
	unsigned int get_posts() const;
	Post& get_post(unsigned int i) const;
	void print() const;
	void print(const int) const;
	void print(const unsigned int) const;
	~Thread();
};

#endif
