#include <iostream>
#include <ctime>
#include <cstdlib>

#include "data.h"
#include "rand.h"

const string Data::Subjects[15] {"Rules and useful information",
"Swap function with references instead pointers",
"Private and public data members",
"Virtual table", "Integer values and if statements", "Initializer List",
"Namespaces", "References and pointers", "Constructors and destructors",
"Function overloads", "Const", "Static types", "Inheritance",
"Linker error and header files", "Structs in classes",
};

const string Data::Creators[26] {"Adam", "Billy", "Chris", "Dennis",
"Elvis", "Frank", "Gary", "Henry", "Iona", "Jay", "Ketty", "Lukas",
"Mark", "Nick", "Oliver", "Patrick", "Quincy", "Robin", "Smith",
"Tayler", "Ulger", "Vivian", "Whitney", "Xandra", "Yule", "Zak"
};

const string Data::Titles[15] {"Please help!!",
"It's nesessery!", "I do not understand it!",
"Problem", "What should I do ?", "Problem solved!",
"Is it correct that?", "C++", "Java", "Compile",
"Error while creating object", "Linking",
"Help me", "Just tell me", "Undefined reference"
};

const string Data::Texts[15]{"text1", "text2", "text3",
"text4", "text5", "text6", "text7", "text8", "text9", "text10",
"text11", "text12", "text13", "text14", "text15"
};

const string Data::subject(int index) const{
	return this->Subjects[(index == 0) ? 0 : rand() % 15];
}

const string Data::creator() const{
	return this->Creators[rand() % 26];
}

const string Data::title() const{
	return this->Titles[rand() % 15];
}

const string Data::text() const{
	return this->Texts[rand() % 15];
}
