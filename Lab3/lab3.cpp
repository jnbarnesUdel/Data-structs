/*
/ * lab3.cpp
 *	TA: Moumita Bhattacharya
 *  Created on: Oct 3, 2018
 *      Author: Jonathan Barnes, Shane Cincotta
 *      The functions are for lab 3
 */


#include"Book.hpp"
#include<time.h>
#include<iostream>
using namespace std;
//Book *b = new Book[2] {b1, b2}
void greatestBook(Book *);

int main(){
	srand(time(NULL));
	int rate[10];

	for(int i = 0; i<10; i++){
		rate[i] = rand()%10 +1;
	}

	Book b1("Walt", "Whitman", "Leaves of Grass", 1800, rate);
	cout << b1.get_bookName() << endl;
	cout << b1.average(rate) << endl;

	for(int i = 0; i<10; i++){
		rate[i] = rand()%10 +1;
	}

	Book b2("James", "Boswell", "Life of Johnson", 2000, rate);
	cout << b2.get_bookName() << endl;
	cout << b2.average(rate) << endl;

	for(int i = 0; i<10; i++){
		rate[i] = rand()%10 +1;
	}


	Book b3("Thomas", "Carlyle", "of Heroes", 1900, rate);
	cout << b3.get_bookName() << endl;
	cout << b3.average(rate) << endl;

	for(int i = 0; i<10; i++){
		rate[i] = rand()%10 +1;
	}


	Book b4("Nicolo", "Machiavelli", "The Prince", 1500, rate);
	cout << b4.get_bookName() << endl;
	cout << b4.average(rate) << endl;

	for(int i = 0; i<10; i++){
		rate[i] = rand()%10 +1;
	}

	Book b5("Loard", "Dunsany", "Time and the Gods", 1600, rate);
	cout << b5.get_bookName() << endl;
	cout << b5.average(rate) << endl;

	Book books[5]= {b1, b2, b3, b4, b5};

	greatestBook(books);

	for(int i = 0; i<10; i++){
		rate[i] = rand()%10 +1;
	}


	//for part 2
	Book *b6 = new Book("Willia", "Cather", "My Antonia", 1990, rate);
	b6->printStuff(b6->get_firstName(), b6->get_lastName(), b6->get_bookName(), b6->get_year(), b6->average(b6->get_rate()));

	//for part 3
	for(int i = 0; i<10; i++){
		rate[i] = rand()%10 +1;
	}
	Book b7("Bradford", "Torrey", "A Ramblers lease", 1200, rate);

	for(int i = 0; i<10; i++){
		rate[i] = rand()%10 +1;
	}
	Book b8("Henrietta", "Haynes", "Henrietta Maria", 2014, rate);

	Book *books2 = new Book[2] {b7, b8};

	for(int i = 0; i < 2; i++){
		Book book = books2[i];
		book.printStuff(book.get_firstName(), book.get_lastName(), book.get_bookName(), book.get_year(), book.average(book.get_rate()));
	}


	return 0;
}


void greatestBook(Book *book){
	Book great = book[0];
	for(int i = 0; i<10; i++){
		if(book[i] > great)
		{
			great = book[i];
		}
	}
	great.printStuff(great.get_firstName(), great.get_lastName(), great.get_bookName(), great.get_year(), great.average(great.get_rate()));
}


