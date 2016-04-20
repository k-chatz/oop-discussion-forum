#ifndef RAND_H
#define RAND_H

#define OBJ_R_MESSAGES 1

class Rand{
	unsigned int min;
	unsigned int max;
	int ** values;
	int index;
	void inline swap_(int&, int&);
	void reset();
public:
	Rand(const unsigned int, const unsigned int);
	void print() const;
	const int get();
	~Rand();
};

#endif