#include <iostream>
using namespace std;
/*
/ * lab1.cpp
 *	TA: Moumita Bhattacharya
 *  Created on: Aug 30, 2018
 *      Author: Jonathan Barnes, Shane Cincotta
 *      The functions are for lab 1
 */
void star();
bool isPrime(int);
void sum();
void HunThous();
int MulTable(int);
void loop();
int prob(int);
bool LeapYear(int);
void NextLeap();
void StarLoop(int);
void sumModified(int, int);
bool isPrimeRe(int, int);
int MulTableRe(int, int);

int main(){
	int num = 17;
	cout << "hello world"<< endl;
	cout << "**********************"<< endl;
	cout << " prob 2" << endl;

	star();
	star();
	cout << " prob 3" << endl;

	for(int num = 17; num <20; num++)
	{
		if(isPrime(num))
		{
			cout << "Prime" << endl;
		}
		else
		{
			cout << "Not Prime" << endl;
		}
	}

	star();
	cout << " prob 4" << endl;

	sum();

	star();
	cout << " prob 5" << endl;

	HunThous();
	star();
	cout << " prob 6" << endl;
	MulTable(3);
	MulTable(6);
	MulTable(10);

	star();
	cout << " prob 7" << endl;

	loop();

	star();
	cout << " prob 8" << endl;
	prob(6);
	prob(7);
	prob(10);

	star();
	cout << " prob 9" << endl;

	LeapYear(2000);
	LeapYear(2100);
	LeapYear(2400);
	NextLeap();//add leap stuff


	star();
	cout << " prob 10" << endl;

	StarLoop(4);
	StarLoop(6);
	StarLoop(5);

	star();
	cout << " prob 11" << endl;

	sumModified(4, 12);
	sumModified(5,16);
	sumModified(13, 15);


	star();
	cout << " prob 12" << endl;

	for(int x = 16; x < 19; x++)
	{
		if(isPrimeRe(x, 2))
			{
				cout << "Is Prime" << endl;
			}
		else
			{
				cout << "Not Prime" << endl;
			}
	}

	star();
	cout << " prob 13" << endl;

	MulTableRe(10, 1);
	MulTableRe(4, 1);
	MulTableRe(6, 1);
}

void star(){
	cout << "********" << endl;
}

// input parameters is a int because prime values can only be ints
// Purpose is to test if prime or not
// return type is bool because either prime or not prime
bool isPrime(int num){
	int count = num-1;
	while(count > 1)
	{
		if(num % count == 0)
		{
			return false;
		}
		count--;
	}
	return true;
}

// no input
// Purpose is to sum between 1 and 300
// return type is none
void sum(){
	int total = 0;
	for(int x =1; x<= 300; x++)
	{
		total = total + x;
		if(x%20 == 0)
		{
			cout << total << endl;
		}
	}
}

// no input
// Purpose is to count number of terms it takes to reach 100000
// return type is none
void HunThous(){
	int total = 0;
	int count = 1;
	while(total < 100000)
	{
		total = total + count;
		count++;
	}
	cout << count << endl;
}

// input is an int because multiplication tables are usually for integers
// Purpose is to make a multiplication table for a number from one to 12
// return type is an int because we use it in the next func
int MulTable(int num){
	for(int x = 1; x<=12; x++)
	{
		cout << num * x << endl;
	}
}

// no input
// Purpose is to make a table of multipication tables for 1 to 12
// return type is none
void loop(){
	for(int x = 1; x <=12; x++)
	{
		MulTable(x);
	}
}

// input is an int to test collatz conjecture on
// Purpose is to test if a number meets the collatz conjecture
// return type is int because we later call this to make shure final num is 1
int prob(int num){
	int count = 0;
	while( num != 1)
	{
		count++;
		if(num%2 ==0)
		{
			num = num / 2;
		}
		else
		{
			num = num *3 +1;
		}
	}
	cout << count << endl;
	return num;
}

// input is an integer resembling a year
// Purpose is to test if current year is a leap year
// return type is bool because eiter true or false
bool LeapYear(int year)
{
	if(year % 4 == 0)
	{
		if(year % 100 == 0)
		{
			if(year % 400 == 0)
			{
				return true;
			}
		}
	}
	return false;
}

// no input
// Purpose is to test for leap years in next 400 years
// return type is none
void NextLeap(){


	for(int year = 2017; year<=2417;year++)
	{
		if(LeapYear(year))
		{
			cout << year << endl;
		}
	}
}

// input is number of stars till center
// Purpose is to make an x of stars
// return type is none
void StarLoop(int num)
{
	for(int x = 1; x < num; x++ )
	{
		for(int y = 0; y< x; y++)
		{
			cout << " ";
		}
		cout << "* ";

		for(int z = num; z > x; z = z -1)
		{
			cout << "  ";
		}
		cout << "*" << endl;
	}

	for(int x = 0; x <= num; x++)
	{
		cout << " ";
	}
	cout << "*" << endl;

	for(int x = num; x > 1; x-- )
	{
		for(int y = 1; y< x; y++)
		{
			cout << " ";
		}
		cout << "* ";

		for(int z = x; z <= num; z = z +1)
		{
			cout << "  ";
		}
		cout << "*" << endl;
	}

}

// 2 int inputs first one is smaller than second
// Purpose is to test for collatz conjecture for each number between num1 and num2
// return type is none
void sumModified(int num1, int num2){
	for(int x=num1; x<num2; x++)
	{
		cout << x << endl;
		prob(x);
		int col = prob(x);
		if(col == 1)
		{
			cout<<"Collatz conjecture is still working!" << endl;
		}

	}
}

// input is a number to test if prime, and a count that starts at one
// Purpose is to find out if num is prime though recursion
// return type is bool because it either is prime or not
bool isPrimeRe(int num, int count){
	if(num % count != 0 && count == num-1)
	{
		return true;
	}
	if(num % count == 0)
	{
		return false;
	}
	isPrimeRe(num, count +1);
}

// input is a number to receive a multiplication table, and a count that starts at one
// Purpose is to make a multiplication table from 1 to 12 for an inputed number though recursion
// return type is int because i wanted to use return 0 to end the recursion
int MulTableRe(int num, int count){
	if(count == 12)
	{
		cout << num * count << endl;
		return 0;
	}
	cout << num * count << endl;
	MulTableRe(num, count + 1);


}
