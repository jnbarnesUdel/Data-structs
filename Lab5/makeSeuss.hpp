/*
 * makeSeuss.hpp
 *
 *  Created on: Nov 16, 2018
 *      Author: Jonathan Barnes and Shane Cincotta
 */

#ifndef MAKESEUSS_HPP_
#define MAKESEUSS_HPP_
#include "hashMap.hpp"
#include <iostream>
using namespace std;

class makeSeuss {
		hashMap *ht;
		string fn; // file name for input (“DrSeuss.txt”)
		string newfile; // name of output file
		public:
		makeSeuss(string file,string newf,bool h1, bool c1);
		void readFile();
		void writeFile();
};

#include "makeSeuss.hpp"
#include "hashMap.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;

makeSeuss::makeSeuss(string f1,string f2,bool h1, bool c1) {
	ht = new hashMap(h1,c1);
	newfile = f2;
	fn = f1;
	readFile();
	writeFile();
}

void makeSeuss::readFile() {
	ifstream infile(fn.c_str(),ios::in); // open file
	string key = "";
	string value= "";
	infile>> key;
	ht->first = key;
	while (infile >> value) { // loop getting single characters
	cout << key <<": " << value << endl;
	ht->addKeyValue(key,value);
	key = value;
	value = "";
	}
	ht->addKeyValue(key,value);
	cout << endl;
	infile.close();

	cout << "collision by hashing: " << ht->collisionct1 << endl;
	cout << "collision by collision handle: " << ht->collisionct2 << endl;
}

void makeSeuss::writeFile() {
	ofstream outfile(newfile.c_str(),ios::out);
	outfile << ht->first << " ";
	string key = "";
	string value = ht->map[ht->getIndex(ht->first)]->getRandValue();
	int ct = 0;
	int len = 0;
	while (ct < 500 && value != "") {
		key = value;
		outfile << key << " ";
		if (len == 11) {
			outfile << "\n";
			len = 0;
		}
		else len++;
		value = ht->map[ht->getIndex(key)]->getRandValue();
		ct ++;
	}
	outfile.close();
}
#endif /* MAKESEUSS_HPP_ */
