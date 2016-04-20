#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

#include "thread.h"

using namespace std;

/*Constructor*/
Thread::Thread(const Data& data, const string subject, const string creator, const unsigned int posts)
: subject(subject), creator(creator), posts(posts){
	date = new Date(rand() % day_secs);
	post = new Post*[posts];
	for (unsigned int i = 0; i < posts; i++)
		post[i] = new Post(data.title(), (i == 0) ? creator : data.creator(), data.text());
#if (OBJ_T_MESSAGES)
	cout << "Thread with subject: '" << subject << "' has just been created!" << endl;
#endif
}

/*Copy constructor*/
Thread::Thread(const Thread& thread)
: subject(thread.subject), creator(thread.creator), posts(thread.posts)
{
	date = new Date(*thread.date);
	post = new Post*[posts];
	for (unsigned int i = 0; i < thread.posts; i++)
		this->post[i] = new Post(*thread.post[i]);					/*Copy Constructor*/
#if (OBJ_T_MESSAGES)
	cout << "Thread with subject: '" << thread.subject << "' has been copied!" << endl;
#endif
}

const string& Thread::get_subject() const{
	return this->subject;
}

unsigned int Thread::get_posts() const{
	return this->posts;
}

Post& Thread::get_post(unsigned int i) const{
	if (i < 0 || i > posts){
		cerr << "Invalid post id: " << i << endl;
		cin.get();
		exit(1);
	}
	else
		return *post[i];
}

/*Print for all thread fields*/
void Thread::print() const{
	cout << "\tThread with Subject '" << this->subject << "'\t(created by '" << this->creator << "' at " << date->get_str() << ")\n\tPosts:" << endl;
	print(T_POSTS);
}

/*Print for each field*/
void Thread::print(const int field = 0) const{
	switch (field){
	case T_SUBJECT:
		cout << "\t'" << subject << "'" << endl;
		break;
	case T_CREATOR:
		cout << "\t'" << creator << "'" << endl;
		break;
	case T_DATE:
		cout << "\t";
		date->print();
		break;
	case T_POSTS:
		for (unsigned int i = 0; i < posts; i++)
			post[i]->print();
		break;
	default:
		cerr << "Field not exists!" << endl;
		cin.get();
		exit(1);
		break;
	}
}

void Thread::print(const unsigned int selectedId) const{
	for (unsigned int i = 0; i < this->posts; i++){
		if (post[i]->getId() == selectedId)
			post[i]->print();
	}
}

Thread::~Thread(){
#if (OBJ_T_MESSAGES)
	cout << "Thread with subject: '" << this->subject << "' is about to be destroyed." << endl;
#endif
	delete date;
	for (unsigned int i = 0; i < posts; i++)
		delete post[i];
	delete[] post;
}
