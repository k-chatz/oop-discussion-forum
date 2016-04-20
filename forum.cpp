#include <iostream>
#include <string>
#include <cstdlib>

#include "forum.h"

using namespace std;

/*Constructor*/
Forum::Forum(const string title, const int threads = 0)
: title(title), threads(threads)
{
	thread = new Thread*[this->threads];
	for (unsigned int i = 0; i < this->threads; i++)
		thread[i] = new Thread(data, data.subject(i), data.creator(), rand() % posts + 1);
#if (OBJ_F_MESSAGES)
	cout << "Forum with title: '" << this->title << "' has just been created!" << endl;
#endif
}

/*Copy constructor*/
Forum::Forum(const Forum& forum)
: title(forum.title), data(forum.data)
{
	threads = forum.threads;
	thread = new Thread*[forum.threads];
	for (unsigned int i = 0; i < forum.threads; i++)
		thread[i] = new Thread(*forum.thread[i]);
#if (OBJ_F_MESSAGES)
	cout << "Forum with title: '" << forum.title << "' has been copied!" << endl;
#endif
}

/*Accesors--------------------------------------------------------------------------------*/
const unsigned int Forum::get_posts(){
	return Post::getLastId();
}
/*----------------------------------------------------------------------------------------*/

/*Prints----------------------------------------------------------------------------------*/
void Forum::print(const int action) const{
	cout << "Forum: '" << title << "'\nThreads:" << endl;
	for (unsigned int i = 0; i < threads; i++){
		switch (action){
		case T_SUBJECT:
			thread[i]->print(T_SUBJECT);
			break;
		case T_CREATOR:
			thread[i]->print(T_CREATOR);
			break;
		case T_DATE:
			thread[i]->print(T_DATE);
			break;
		case T_POSTS:
			thread[i]->print(T_POSTS);
			break;
		default:
			thread[i]->print();
			break;
		}
	}
}

void Forum::print(const unsigned int selectedId) const{
	for (unsigned int i = 0; i < this->threads; i++){
		thread[i]->print(selectedId);
	}
}

void Forum::print(const string subject) const{
	cout << "Search for: '" << subject << "' thread.." << endl;
	for (unsigned int i = 0; i < threads; i++){
		if (thread[i]->get_subject().compare(subject) == 0){
			thread[i]->print();
		}
	}
}

void Forum::print_sorted(){
	tree = new Tree(*thread[0]);
	for (unsigned int i = 1; i < threads; i++){
		//cin.get();
		//cout << "\n\ni = " << i << endl;
		Tree tree(*thread[i]);
		//cin.get();
		//cout << "\n\nForum::TREE1 before." << endl;
		//this->tree->print();
		//cin.get();

		//cout << "\n\nTREE2 temporary for thread." << endl;
		//tree.print();
		//cin.get();

		this->tree->enhance(tree);
		//cin.get();

		//cout << "\n\nForum::TREE1 after." << endl;
		//this->tree->print();
		//cin.get();

	}
	this->tree->print();
	delete tree;
}
/*----------------------------------------------------------------------------------------*/

/*Destructor*/
Forum::~Forum(){
#if (OBJ_F_MESSAGES)
	cout << "Forum with title: '" << this->title << "' is about to be destroyed" << endl;
#endif
	for (unsigned int i = 0; i < threads; i++)
		delete thread[i];
	delete[] thread;
}
