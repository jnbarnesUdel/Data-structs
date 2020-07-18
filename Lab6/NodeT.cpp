/*
 * NodeT.cpp
 *
 *	TA: Moumita Bhattacharya
 *      Author: Jonathan Barnes, Shane Cincotta
 *      The functions are for lab 6
 */

#include "NodeT.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

NodeT::NodeT(string x) {
	w = new wordInfo(x);
	left = NULL;
	right = NULL;
	parent = NULL;
	height = 1;
}
NodeT::~NodeT() {
	if ((left != NULL) || (right != NULL)) {
		cout << "deleting may leave dangling Nodes" << endl;
	}
}
void NodeT::printNode() {
	cout << "|"<<w->word << "("<< height <<"): " <<w->ct<<"|" <<endl;
}



