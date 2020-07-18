/*
 * Node.cpp
 *
 *  Created on: Oct 5, 2018
 *      Author: Jonathan Barnes
 */

#include "SNode.hpp"
#include<iostream>
#include<string>
using namespace std;

SNode::SNode(){
	int ra;
	string c;
	cout << " what rate?" << endl;
	cin >> ra;

	rating = ra;

	cout << "comments?" << endl;
	cin >> c;
	comments = c;

	next = NULL;
}
SNode::SNode(int r, string c){
	rating = r;
	comments = c;
	next = NULL;
}

void SNode::printNode(){
	 cout << "rate " << rating << endl;
	 cout << "comments: " << comments << endl;
}


SNode::~SNode(){
	if (next != NULL) {
		cout << "del stuff" << endl;
	}
	cout << "delete " << this->rating  << ", " << this->comments << endl;
}

