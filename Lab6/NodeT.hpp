/*
 * NodeT.hpp
 *
  *	TA: Moumita Bhattacharya
 *      Author: Jonathan Barnes, Shane Cincotta
 *      The functions are for lab 6
 */

#ifndef NODET_HPP_
#define NODET_HPP_

#include "wordInfo.hpp"
#include <string>
using namespace std;

class NodeT {
	friend class BSTY;
	friend class AC;
	wordInfo *w;
	int height;
	NodeT *left;
	NodeT *right;
	NodeT *parent;
	public:
	NodeT(string x);
	~NodeT();
	void printNode();
};

#endif /* NODET_HPP_ */
