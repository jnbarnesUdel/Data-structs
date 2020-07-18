/*
 * hashMap.cpp
 *
 *  Created on: Nov 16, 2018
 *      Author: Jonathan Barnes and Shane Cincotta
 */

#include<string>
#include<time.h>
#include<iostream>
#include"hashNode.hpp"
#include"hashMap.hpp"
using namespace std;

hashMap::hashMap(bool hash1, bool coll1){
	numKeys = 0;
	collisionct1 = 0;
	collisionct2 = 0;
	c1 = coll1;
	h1 = hash1;
	mapSize = 13;
	map = new hashNode*[mapSize]{NULL};
}

void hashMap::addKeyValue(string k, string v){
	hashNode *n = new hashNode(k, v);

	hashing(n);

	numKeys = numKeys + 1; //may want to put somewhere else doesn't know if actually unique key or not
	if(numKeys > .7*mapSize){
		getClosestPrime();
	}
}

//first hash function
//add together the values of each letter in the key string then mod by the map size
int hashMap::calcHash(string k){
	int count = 0;

	for(char c : k){
		count = count + c;
	}
	count = count % mapSize;
	return count;
}

//only look at first 3 letters and add a weighting to them so order matters
int hashMap::calcHash2(string k){
	int count = 0;
	int weighting = 3;
	int temp;

	for(char c : k){
		temp = c * weighting;
		weighting = weighting - 1;
		count = count + temp;
		if(weighting == 0){
			return count % mapSize;
		}
	}
	count = count % mapSize;
	return count;
}

void hashMap::hashing(hashNode *n){
	//cout << mapSize << endl;
	//cout << numKeys << endl;
	int count = 0;
	if(h1){
		//hash 1
		count = calcHash(n->keyword);
	}
	else
	{
		//hash 2
		count = calcHash2(n->keyword);
	}

	if(map[count] != NULL){
		if(map[count]->keyword == n->keyword){
			map[count]->addValue(n->values[0]);
		}
		else if(c1){
			count = collHash1(n, count);
			if(map[count] == NULL){
				map[count] = n;
			}
			else{
				map[count]->addValue(n->values[0]);
			}
		}
		else{
			count = collHash2(n, count);
			if(map[count] == NULL){
				map[count] = n;
			}
			else{
				map[count]->addValue(n->values[0]);
			}
		}
	}
	else{
		map[count] = n;
	}
}

//doubles map size then gets it up to a prime then rehashes the map
void hashMap::getClosestPrime(){
	int len = mapSize * 2;
	int size = mapSize;

	while(isPrime(len) != true){
		len = len +1;
	}

	hashNode **temp = map; //look at this
	map = new hashNode*[len]{NULL};
	mapSize = len;

	for(int i =0; i<size; i++){
		if(temp[i] != NULL){
			hashing(temp[i]);
		}
	}
}

//calculates if the number sent in is prime, did this in another lab
// return s true or false
bool hashMap::isPrime(int num){
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

//we rehashed in isPrime so we don't use this function
//thought it would be easier to do that way
void hashMap::reHash(){

}

//first collision type
//linear probing style collision handling
int hashMap::collHash1(hashNode *n, int count){
	collisionct1++;//collisions by hashing func
	while(map[count] != NULL){
		if(map[count]->keyword == n->keyword){
			return count;
		}
		count++;
		while(count >= mapSize){
			count = count - mapSize;
		}
		collisionct2++;//collisions by collision func
	}
	return count;
}

//second collison type
//quadratic probing
// use num for quadrat, count for starting location
int hashMap::collHash2(hashNode *n, int count){
	collisionct1++;//collisions by hashing func
	int num = 0;
	while(map[count] != NULL){
		if(map[count]->keyword == n->keyword){
			return count;
		}
		count = count + num * num;
		num = num + 1;
		while(count >= mapSize){
			count = count - mapSize;
		}
		collisionct2++; //collisions by collision func
	}
	return count;
}

int hashMap::findKey(string k){
	int start = 0;
	if(h1){
		start = calcHash(k);
		if(map[start]->keyword != k){
			if(c1){
				//c1 is a linear probe from the start hash
				while(map[start] != NULL){
					if(map[start]->keyword == k){
						return start;
					}
					start++;
					while(start >= mapSize){
						start = start - mapSize;
					}
				}
			}
			else{
				//c2 is a quadradic probe from start hash
				int num = 0;
				while(map[start] != NULL){
					if(map[start]->keyword == k){
						return start;
					}
					start = start + num * num;
					num = num + 1;
					while(start >= mapSize){
						start = start - mapSize;
					}
				}
			}
		}
		else{
			return start;
		}
	}
	else{
		start = calcHash2(k);
		if(map[start]->keyword != k){
			if(c1){
				//c1 is a linear probe from the start hash
				while(map[start] != NULL){
					if(map[start]->keyword == k){
						return start;
					}
					start++;
					while(start >= mapSize){
						start = start - mapSize;
					}
				}
			}
			else{
				//c2 is a quadradic probe from start hash
				int num = 0;
				while(map[start] != NULL){
					if(map[start]->keyword == k){
						return start;
					}
					start = start + num * num;
					num = num + 1;
					while(start >= mapSize){
						start = start - mapSize;
					}
				}
			}
		}
		else{
			return start;
		}

	}
	return -1;
}

int hashMap::getIndex(string k){
	int count = 0;
	while(1)
	{
		if(map[count] != NULL){
			if(map[count]->keyword == k){
				return count;
			}
		}
		count++;
	}
	return count;
}
