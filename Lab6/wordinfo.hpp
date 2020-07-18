/*
/ * wordinfo.hpp
 *	TA: Moumita Bhattacharya
 *      Author: Jonathan Barnes, Shane Cincotta
 *      The functions are for lab 6
 */

#ifndef WORDINFO_HPP_
#define WORDINFO_HPP_

#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
class wordInfo {
	friend class NodeT;
	friend class BSTY;
	friend class Sorting;
	friend class AC;
	string word;
	int ct;
	public:
	wordInfo(string w, int x);
	wordInfo(string w);
	wordInfo();
	void printWord();
};

#endif /* WORDINFO_HPP_ */
