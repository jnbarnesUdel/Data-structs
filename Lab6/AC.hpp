/*
 * AC.hpp
 *
 *	TA: Moumita Bhattacharya
 *      Author: Jonathan Barnes, Shane Cincotta
 *      The functions are for lab 6
 */

#ifndef AC_HPP_
#define AC_HPP_

#include "BSTY.hpp" // You update
#include "wordInfo.hpp"
#include "Sorting.hpp" // You write
#include <iostream>
using namespace std;

class AC {
	bool verbose;
	BSTY *tree;
	string fn;
	wordInfo **wordarr;
	wordInfo **predictions;
	int currSize;
	string curr;
	Sorting sorts;
	public:
		AC(string f1,bool isverbose=false);
		void readFile();
		void convertToArray();
		void convertToArray(NodeT *n);
		void printArr();
		string stripSpace(string s);
		void ui();
		void getPredictions();
		int findBeg();
		int findEnd();
};



#endif /* AC_HPP_ */
