/*
 * SLL.cpp
 *
 *  Created on: Oct 5, 2018
 *      Author: Jonathan Barnes
 */


#include "SLL.hpp"
#include<iostream>
#include <string>
using namespace std;

SLL::SLL(){
	first = NULL;
	last = NULL;
	size = 0;
}

void SLL::printSLL(){
	SNode *temp = first;
	for(int i = 0; i<size;i++){
		cout << "rate: " << temp->rating << ",   ";
		cout << "com: " << temp->comments << endl;
		temp = temp->next;
	}
	cout << endl;

}

void SLL::insertInOrder(int r, string c){
	SNode *temp = first;
	int changed = 0;
	if(size == 0){
		addFirst(r, c);
	}
	else if(first->rating > r){
		addAtFront(r, c);
	}
	else if(last->rating < r){
		push(r, c);
	}
	else
	{
		for(int i=0; i < size; i++)
		{
			if(temp->next->rating >= r && changed !=1){
				SNode *temp2 = temp->next;
				temp->next = new SNode(r, c);
				temp->next->next = temp2;
				size++;
				changed = 1;
			}
			else{
				temp = temp->next;
			}
		}
	}

}

void SLL::push(int r, string c){
	SNode *thing = new SNode(r, c);
	last->next = thing;
	last = thing;
	size++;
}

void SLL::addAtFront(int r, string c){
	SNode *thing = new SNode(r, c);
	thing->next = first;
	first = thing;
	size++;
}

void SLL::addFirst(int r, string c){
	size++;
	first = new SNode(r, c);
	last = first;
}

int SLL::pop(){
	SNode *temp = first;
	for (int i = 0; i < (size - 2);i++) {
		temp = temp->next;
	}
	cout << "removing: " << last->rating << ", " << last->comments << endl;
	int rate = last->rating;
	delete last;
	last = temp;
	last->next = NULL;
	size = size -1;
	return rate;
}

double SLL::getAve(){
	double sum = 0;
	SNode *temp = first;
	for(int i = 0; i< size; i++){
		sum = sum + temp->rating;
		temp = temp->next;
	}
	return (double)(sum / size);
}


SLL::~SLL(){
	cout << "deleted each node in 11" << endl;

}
