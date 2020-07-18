/*
 * lab5.cpp
 *
 *  Created on: Nov 17, 2018
 *      Author: Jonathan Barnes Shane Cincotta
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include "hashNode.hpp"
#include "hashMap.hpp"
#include "makeSeuss.hpp"
using namespace std;
int main() {
	srand(time(NULL));

	//hash function one and collision function 1
	//collision by hashing 7535
	//collision by collision handle 4625314
	makeSeuss("DrS.txt", "test1", true, true);

	//hash function one and collision function 2
	//collision by hashing 7507
	//collision by collision handle 81362
	makeSeuss("DrS.txt", "test2", true, false);

	//hash function two and collision function 1
	//collision by hashing 9473
	//collision by collision handle 5869328
	makeSeuss("DrS.txt", "test3", false, true);

	//hash function two and collision function 2
	//collision by hashing 9997
	//collision by collision handle 120415
	makeSeuss("DrS.txt", "test4", false, false);
	return 0;
}


