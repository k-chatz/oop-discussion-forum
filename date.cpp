#include <ctime>
#include "date.h"

const unsigned int day_secs = 86400;

unsigned int Date::sec_add = 0;

/*Date constructor*/
Date::Date(){
	set();
}

Date::Date(int _s = 0){
	sec_add += _s;
	set(sec_add);
}

/*Set current time*/
void Date::set(){
	time_t unix_time;
	time(&unix_time);
	timeInfo = *localtime(&unix_time);
}

/*Set current time plus seconds*/
void Date::set(unsigned int s){
	time_t unix_time;
	time(&unix_time);
	unix_time += s;
	timeInfo = *localtime(&unix_time);
}

/*Set specific time from argument*/
void Date::set(const time_t& t){
	timeInfo = *localtime(&t);
}

void Date::set_sec(const int x){
	timeInfo.tm_sec = x;
}
void Date::set_min(const int x){
	timeInfo.tm_min = x;
}
void Date::set_hour(const int x){
	timeInfo.tm_hour = x;
}
void Date::set_day(const int x){
	timeInfo.tm_mday = x;
}
void Date::set_mon(const int x){
	timeInfo.tm_mon = x;
}
void Date::set_weekDay(const int x){
	timeInfo.tm_wday = x;
}
void Date::set_yearDay(const int x){
	timeInfo.tm_yday = x;
}
void Date::set_daylightSavingTime(const int x){
	timeInfo.tm_isdst = x;
}

int Date::get_sec() const{
	return timeInfo.tm_sec;
}
int Date::get_min() const{
	return timeInfo.tm_min;
}
int Date::get_hour() const{
	return timeInfo.tm_hour;
}
int Date::get_day() const{
	return timeInfo.tm_mday;
}
int Date::get_mon() const{
	return timeInfo.tm_mon;
}
int Date::get_weekDay() const{
	return timeInfo.tm_wday;
}
int Date::get_yearDay() const{
	return timeInfo.tm_yday;
}
int Date::get_daylightSavingTime() const{
	return timeInfo.tm_isdst;
}

/*///////////////////////////////////*/

const string Date::get_str(const char * format) {
	/*
	* Date format arguments for print:
	* http://www.cplusplus.com/reference/ctime/strftime/
	*/
	strftime(buffer, DATE_STRBUFF, format, &timeInfo);
	return buffer;
}

void Date::print(){
	//cout << "" << get_str(DATE_FORMAT) << endl;
}