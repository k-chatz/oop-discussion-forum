#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

#define OS 1	/*0 if current system is windows, 1 for linux*/

#if (OS)
#include <sys/ioctl.h>
#include <unistd.h>
#else
#include <windows.h>
#endif

#include "forum.h"
#include "rand.h"

using namespace std;

void separate(){
	int col;
#if (OS)
	/*The following code is from: 
	* http://stackoverflow.com/questions/1022957/getting-terminal-width-in-c 
	*/
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	col = w.ws_col;
#else
	/*The following code is from:
	* http://stackoverflow.com/questions/6812224/getting-terminal-size-in-c-for-windows
	*/
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	col = csbi.srWindow.Right - csbi.srWindow.Left + 1;
#endif
	for (int i = 1; i <= col; i++)
		(i == 1 || i == col) ? cout << '+' : cout << '-';
	cout << endl;
}

int main(){
	srand((unsigned int)time(NULL));
	{
		cout << "Exercise 1:" << endl;
		/*Question 1*/
		separate();
		cout << "Question 1)\n" << endl;
		Forum f1("Object Oriented Programming", rand() % threads + 1);
		separate();
		cin.get();

		/*
		Prints all threads with their posts for debugging.
		separate();
		f1.print(T_ALL);		
		separate();
		*/

		/*Question 2*/
		separate();
		cout << "Question 2)\n" << endl;
		f1.print(T_SUBJECT);	/*Prints all threads.*/
		separate();
		cin.get();

		/*Question 3*/
		separate();
		cout << "Question 3)\n" << endl;
		f1.print("Rules and useful information");
		separate();
		cin.get();

		/*Question 4*/
		separate();
		cout << "Question 4)\n" << endl;
		unsigned int posts = f1.get_posts();
		Rand r_p(1, posts);
		unsigned int x = rand() % posts;
		cout << x << " out of " << posts << " posts have been selected randomly:" << endl;
		for (unsigned int i = 0; i < x; i++)
			f1.print((unsigned int)r_p.get());
		separate();
		cin.get();

		//cout << "\n\nf2 generated from f1..." << endl;
		//Forum f2(f1);
		//getchar();
		//cout << "Done!\n\n\n\n" << endl;

		cout << "Exercise 2:" << endl;
		/*Question 2*/
		separate();
		cout << "Question 2)\n" << endl;
		f1.print_sorted();
		separate();
		cin.get();
	}
	cin.get();
	return 0;
}
