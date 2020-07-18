/*
 * hashNode.cpp
 *
 *  Created on: Nov 16, 2018
 *      Author: Jonathan Barnes and Shane Cincotta
 */

#include<string>
#include<time.h>
#include<iostream>
#include "hashNode.hpp"
using namespace std;

hashNode::hashNode(){
	keyword = "";
	currSize = 0;
	valuesSize = 0;
	values = NULL;
}

hashNode::hashNode(string s){
	keyword = s;
	currSize = 0;
	valuesSize = 100;
	values = new string[100];
}

hashNode::hashNode(string s, string v){
	keyword = s;
	currSize = 1;
	valuesSize = 100;
	values = new string[100]{v};
}

void hashNode::addValue(string v){
	values[currSize] = v;
	currSize = currSize + 1;
	if((currSize >= (.7 * valuesSize))){ // this could be a problem if string is not size 100
		dblArray();
	}
}

void hashNode::dblArray(){
	int og = valuesSize;
	int n = og * 2;
	string *newArr = new string[n];
	for(int i = 0; i<og; i++){
		newArr[i] = values[i];
	}
	delete []values;
	values = newArr;
	valuesSize = n;
}

string hashNode::getRandValue(){
	//srand(time(NULL));
	if(currSize > 0){
		return values[rand()%currSize];
	}
	else{
		return "";
	}
}

