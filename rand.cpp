#include <iostream>
#include <ctime>
#include <cstdlib>

#include "rand.h"

using namespace std;

void inline Rand::swap_(int& r1, int& r2){ int t = r1; r1 = r2; r2 = t; }

void Rand::reset(){
	int x = (max - min + 1);
	for (int i = 0; i < x; i++){
		*values[i] = min + i;
	}
}

Rand::Rand(const unsigned int min, const unsigned int max)
: min(min), max(max)
{
	if (max > min){
		index = max - min + 1;
		values = new int*[index];
		for (int i = 0; i < index; i++)
			values[i] = new int(min + i);
#if (OBJ_R_MESSAGES)
		cout << "I construct a Rand object with min value: " << min << " and max value: " << max << endl;
#endif
	}
	else{
		cerr << "Error:\nCan't create random numbers in function 'Rand::Constructor' with this arguments!" << endl;
		cin.get();
		exit(1);
	}
}

void Rand::print() const{
	int x = (max - min + 1);
	for (int i = 0; i < x; i++)
		cout << "Values[" << i << "] = " << *values[i] << endl;
}

const int Rand::get(){
	int x, number = -1;
	if (index > 0){
		x = rand() % index;
		number = *values[x];
		swap_(*values[x], *values[--index]);
	}
	else{
		cerr << "Error:\nCan't generate more random numbers in function 'Rand::Generate'" << endl;
		cin.get();
		reset();
	}
	return number;
}

Rand::~Rand(){
#if (OBJ_R_MESSAGES)
	cout << "Rand object is about to be destroyed..." << endl;
#endif
	int x = (max - min + 1);
	for (int i = 0; i < x; i++)
		delete values[i];
	delete[] values;
}
