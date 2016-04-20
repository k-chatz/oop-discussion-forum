#ifndef DATA_H
#define DATA_H

#include <string>

using namespace std;

class Data{
	static const string Subjects[];
	static const string Creators[];
	static const string Titles[];
	static const string Texts[];
public:
	const string subject(int) const;
	const string creator() const;
	const string title() const;
	const string text() const;
};

#endif
