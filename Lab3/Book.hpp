/*
 * Book.hpp
 *
 *  Created on: Oct 3, 2018
 *      Author: Jonathan Barnes
 */
#include<string>
using namespace std;

class Book{
	string firstName;
	string lastName;
	int *rate = new int[10];
	string bookName;
	int year;
	void set_firstName(string fn);
	void set_lastName(string ln);
	void set_bookName(string bn);
	void set_year(int yr);
	void set_rate(int *rt);
	void set_rate();
public:
	Book(string fn, string ln, string bn, int yr);
	Book(string fn, string ln, string bn, int yr, int *rt);
	string get_firstName();
	string get_lastName();
	string get_bookName();
	int get_year();
	int* get_rate();
	double average(int *rt);
	void printRate(int *rt);
	void printStuff(string fn, string ln, string bn, int yr, double av);
	bool operator>(Book b);
	~Book();

};
