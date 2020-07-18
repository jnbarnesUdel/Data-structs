/*
 * Book.cpp
 *
 *  Created on: Oct 3, 2018
 *      Author: Jonathan Barnes
 */

#include"Book.hpp"
#include<iostream>
#include<string>
using namespace std;

Book::Book(string fn, string ln, string bn, int yr){
	set_firstName(fn);
	set_lastName(ln);
	set_bookName(bn);
	set_year(yr);
	set_rate();
}

Book::Book(string fn, string ln, string bn, int yr, int *rt){
	set_firstName(fn);
	set_lastName(ln);
	set_bookName(bn);
	set_year(yr);
	set_rate(rt);
}

void Book::set_firstName(string fn){
	firstName = fn;
}
void Book::set_lastName(string ln){
	lastName = ln;
}
void Book::set_bookName(string bn){
	bookName = bn;
}
void Book::set_year(int yr){
	year = yr;
}
void Book::set_rate(int *rt){
	for(int i = 0; i<10; i++){
		rate[i] = rt[i];
	}
}
void Book::set_rate(){
	rate = {};

}

string Book::get_firstName(){
	return firstName;
}
string Book::get_lastName(){
	return lastName;
}
string Book::get_bookName(){
	return bookName;
}
int Book::get_year(){
	return year;
}
int* Book::get_rate(){
	return rate;
}

double Book::average(int *rt){
	double av = 0;
	for(int i = 0; i<10; i++){
		av = av + (double)rt[i];
	}
	return (double)(av/10);
}

void Book::printRate(int *rt){
	for(int i=0; i<10;i++)
	{
		if(rt[i] == 0){
			cout << "no rate yet" << endl;
		}
		else
		{
			cout << rt[i] << endl;
		}
	}
}

void Book::printStuff(string fn, string ln, string bn, int yr, double av){
	cout << "Auth :" << fn << " ";
	cout << ln << endl;
	cout << "book name: " << bn << endl;
	cout << "year pub: " << yr << endl;
	cout <<"av: " << av << endl;
	cout << endl;
}

bool Book::operator >(Book b){
	if(this->average(this->get_rate()) > b.average(b.get_rate())){
		return true;
	}
	else
	{
		return false;
	}
}



Book::~Book(){
	delete []rate;
}




