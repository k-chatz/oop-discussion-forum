#ifndef DATE_H
#define DATE_H

#include <iostream>

#define DATE_STRBUFF 100

#define DATE_FORMAT "%A, %d %B %Y - %X"

extern const unsigned int day_secs;

using namespace std;

class Date {
	struct tm timeInfo;
	static unsigned int sec_add;
	char buffer[DATE_STRBUFF];
public:
	Date();
	Date(int);

	/*Set current time*/
	void set();

	/*Set current time plus seconds*/
	void set(unsigned int);

	/*Set specific time from argument*/
	void set(const time_t&);

	void set_sec(const int);
	void set_min(const int);
	void set_hour(const int);
	void set_day(const int);
	void set_mon(const int);
	void set_weekDay(const int);
	void set_yearDay(const int);
	void set_daylightSavingTime(const int);

	int get_sec() const;
	int get_min() const;
	int get_hour() const;
	int get_day() const;
	int get_mon() const;
	int get_weekDay() const;
	int get_yearDay() const;
	int get_daylightSavingTime() const;
	const string get_str(const char * _format = DATE_FORMAT);
	void print();
};

#endif