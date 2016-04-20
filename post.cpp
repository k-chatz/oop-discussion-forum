#include <cstdlib>

#include "post.h"
#include "rand.h"

using namespace std;

unsigned int Post::lastId = 0;

/*Constructor*/
Post::Post(const string title, const string creator, const string text)
: title(title), creator(creator), text(text)
{
	id = ++lastId;
	date = new Date(rand() % day_secs);

#if (OBJ_P_MESSAGES)
	cout << "I create a post with Id: " 
		<< this->id 
		<< ", title: '" 
		<< this->title 
		<< "', Creator: '" 
		<< this->creator 
		<< "', Date: " 
		<< date->get_str() 
		<< endl;
#endif
}

/*Copy constructor*/
Post::Post(const Post& post)
: id(post.id), title(post.title), creator(post.creator), text(post.text)
{
	this->date = new Date(*post.date);
#if (OBJ_P_MESSAGES)
	cout << "Post with title: '" 
		<< post.title 
		<< "' has been copied!" 
		<< endl;
#endif
}

string Post::get_creator() const {
	return this->creator;
}

/*Accesors*/
unsigned int Post::getId() const{
	return this->id;
}

unsigned int Post::getLastId(){
	return lastId;
}

/*Prints*/
void Post::print() const{
	cout << "\t\t#" 
		<< this->id 
		<< "  '" 
		<< this->title 
		<< "'\n\t\tMessage: '" 
		<< this->text 
		<< "'\n\t\t(created by '" 
		<< this->creator 
		<< "' at " 
		<< date->get_str() 
		<< ")\n" 
		<< endl;
}

/*Print for each field*/
void Post::print(const int field) const{
	switch (field){
	case P_TITLE:
		cout << "\t'" << title << "'" << endl;
		break;
	case P_CREATOR:
		cout << "\t'" << creator << "'" << endl;
		break;
	case P_DATE:
		cout << "\t";
		date->print();
		break;
	case P_TEXT:
		cout << "\t'" << text << "'" << endl;
		break;
	default:
		cerr << "Field not exists!" << endl;
		cin.get();
		exit(1);
		break;
	}
}

/*Destructor*/
Post::~Post(){
#if (OBJ_P_MESSAGES)
	cout << "Post number: " 
		<< this->id 
		<< " is about to be destroyed" 
		<< endl;
#endif
	delete date;
}
