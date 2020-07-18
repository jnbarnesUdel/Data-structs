/*
 * lab2.cpp
 *
 *  Created on: Sep 12, 2018
 *     TA: Moumita Bhattacharya
 *     Author: Jonathan Barnes, Shane Cincotta
 *     The functions are for lab 2
 */

#include<iostream>
#include<time.h>
#include<math.h>
using namespace std;

void star(); // for separating different parts
void func1();
void func2(int);
int func3();
void func4(int *);
void func5(int &);
void func6(int *, int*);
void func7(char, char *, char &);
bool func8a(int *, int *);
void func8b();
int func8(int, int &);
void func9(int);
void func10(int, int);
int* func11();
void func12(int num[], int);
int *func13(int *, int *, int *);
int *func14(int);
void func15(int *, int);
void func16(double *, int);
int *func17(int *, int *);
int func18(int *, int);
int *func19(int *, int, int);
void func20(int *, int, int, int);
int **func21(int *, int *);

int main(){
	srand(time(NULL));
	star(); //for the line of stars between functions
	cout << "part 1" << endl;

	func1();

	star();
	cout << "part 2" << endl;

	int x = 2;
	func2(x);
	cout << x << ", " << &x << endl;

	star();
	cout << "part 3" << endl;

	int y = func3();
	cout << y << ", " << &y << endl;

	star();
	cout << "part 4" << endl;

	int z = 3;
	cout << z << ", " << &z << endl;
	func4(&z);
	cout << z << ", " << &z << endl;

	star();
	cout << "part 5" << endl;

	int k = 4;
	cout << k << ", " << &k << endl;
	func5(k);
	cout << k << ", " << &k << endl;

	star();
	cout << "part 6" << endl;

	int t = 10;
	int l = 20;
	func6(&t, &l);
	cout << t << ", " << l << endl;

	star();
	cout << "part 7" << endl;

	char r = 'y';
	char i = 'e';
	char w = 's';

	cout << r << i << w << endl;
	func7(r, &i, w);
	cout << r << i << w << endl;

	star();
	cout << "part 8" << endl;

	func8b();
	int num = -1;
	int len = 5;
	cout << func8(len, num) << endl;

	cout << "part 9" << endl;
	star();

	func9(len);

	cout << "part 10" << endl;
	star();

	int max = 50;
	func10(len, max);

	cout << "part 11" << endl;
	star();

	// does nothing because stuff in function is put on stack and is destroyed when leave function
	//does compile though
	int* o;
	o = func11();
	cout << &o << ", " << o << endl;

	cout << "part 12" << endl;
	star();

	int arr12[25];
	for(int i = 0; i < 25; i++){
		arr12[i] = rand()%10 + 1;
	}
	func12(arr12, 25);

	cout << "part 13" << endl;
	star();

	int len13;
	int min13;
	int max13;
	int *add = func13(&len13, &max13, &min13);
	func12(add , len13);
	cout << "length "<< len13 << " " << "max "<< max13 << " " << "min " << min13 << endl;

	cout << "part 14" << endl;
	star();

	int num13 = rand()%25 + 25;
	//func12(func14(num13), num13);
	//doesn't work because array is on stack so gets destroyed after leaving func

	cout << "part 15" << endl;
	star();

	int arr15[4];
	func15(arr15, 4);

	cout << "part 16" << endl;
	star();

	double arr16[4];
	func16(arr16, 4);

	cout << "part 17" << endl;
	star();

	int size = 25;
	int arr17[size] = {5, 4, 4, 3, 6, 6, 6, 8, 9, 5, 1, 3, 8, 8, 1, 8, 9, 9, 3 ,2, 2, 2, 6 ,1, 2};
	int *place = func17(arr17, &size);
	func12(place, size);
	delete []place;

	cout << "part 19" << endl;
	star();

	int arr19[9] = {3,8,2,5,1,4,6,0,2};
	func12(arr19, 9);
	func12(func19(arr19, 9, 5), 9);

	cout << "part 20" << endl;
	star();

	int arr20[35] = {6, -2, -4, 5, -3, -4, -3, -1, 5, 2, -2, 0, -7, 2, -3, -4, -3, -1, -5, -3, 1, 7, 3, -7, -7, 3,
			-8, 1, -5, -4, -2, -5, -8, 0, -4};
	cout << "array: ";
	func12(arr20, 35);
	func20(arr20, 35, 8, -8);
	cout << endl;
	cout << "low passed array: ";
	int *narr20 = func19(arr20, 35, 5);
	func12(narr20, 35);
	func20(narr20, 35, 3, -4);

	cout << "part 21" << endl;
	star();

	int input;
	cout << "enter a number" << endl;
	cin >> input;
	int x21;
	int y21;
	int **Point = NULL;
	for(int i =0; i< input; i++){
		Point = func21(&x21, &y21);
		for(int j = 0; j < y21;j++){
			func12(Point[j], x21);
		}
		cout << endl;

	}
	return 0;
}

//for the line between functions
void star(){
	cout<< "*************" << endl;
}

//print out the adress of variable with arbitrary value
void func1(){
	int x = 3;
	cout << x << ", " << &x << endl;
}

//this was ment to demonstrate pass by value
void func2(int y){
	y = y +4;
	cout << y << ", " << &y << endl;
}

//make an int, set it to a random num, print it and its adress, and in main we printed out its val, and adress
int func3(){
	int x = (rand()%50 + 1);
	cout << x << ", " << &x << endl;
	return x;
}

//demonstrates pass by pointer
void func4(int *p){
	pow(*p, 3);

	cout << *p <<", " << p << ", " << &p << endl;

}

//demonstrates pass by reference
void func5(int &k)
{
	int v =  rand()%11;

	k = k + v;

	cout << v << ", " << k << ", " << &k << endl;
}

//send in a 10 and 20, use call by pointer without returning anything, show how pass by
//pointer changes values at the adress
void func6(int *t, int *l)
{
	int *x = t;
	*x = 32;
	x = l;
	*x = 42;

}

// did word scramble thing showing differences between pass by pointer, value, and refference
void func7(char x, char *y, char &z)
{
	x = 'n';
	*y = 'o';
	z = '!';
}

//for func 8 stuff swapp ints, returns false if no swap, loops 20 times makes 2 rand nums and sees if
//they get swapped, takes in 2 ints one for len and makes an array, prints the array, and makes changes to the array
bool func8a(int *x, int *y)
{
	int temp = 0;
	if(*x > *y)
	{
		temp = *x;
		*x = *y;
		*y = temp;
		return true;
	}
	return false;
}


void func8b(){
	for(int x = 0; x < 20; x++)
	{
		int f = rand()%26;
		int s = rand()%26;
		cout << f << ", " << s << endl;
		if(func8a(&f, &s))
		{
			cout << "swapped " << f << ", " << s << endl;
		}
	}
}

int func8(int len, int &x){
	int arr[len];
	for(int i = 0; i < len; i ++)
	{
		arr[i] = rand()%50 + 1;
	}
	int smallest = arr[0];
	for(int y : arr)
	{
		cout << y << ", ";
		if(y < smallest)
		{
			smallest = y;
		}
	}
	cout << endl;
	x = smallest;

	return smallest;
}

//takes in an int for len, and makes an array filled with random numbers and prints the array
// reverses the array and prints it
void func9(int len){
	int arr[len];
	int temp = 0;
	int count = 0;
	for(int i = 0; i < len; i ++)
	{
		arr[i] = rand()%50 + 1;
		cout << arr[i] << ", ";
	}
	cout << endl;
	for(int y = len-1; y > len/2; y--)
	{
		temp = arr[count];
		arr[count] = arr[y];
		arr[y] = temp;
		count = count +1;
	}
	for(int z = 0; z < len; z ++)
	{
		cout << arr[z] << ", ";
	}
	cout << endl;
}

//takes in a len and a max makes an array, finds smallest, prints array in order
void func10(int len, int max){
	int arr[len];
	int loc;
	for(int x = 0; x < len; x++)
	{
		arr[x] = rand()%max;
	}


	for(int y = 0; y < len; y++)
	{
		int smallest = arr[0];
		loc = 0;
		for(int y = 0; y<len; y++)
		{
			if(arr[y] < smallest){
				smallest = arr[y];
				loc = y;
			}
		}
		arr[loc] = max + 1;
		cout << smallest << ", ";
	}
	cout << endl;
}

//creates var on stack, prints val and address, returns address, doesn't work because on stack and
//gets destroyed
int *func11(){
	int x=3;
	cout << &x << ", " << x << endl;
	return &x;
}
//generates an array of length 25 with random ints that range from 1-10
void func12(int *arr, int size){
	for(int i = 0; i < size ; i++){
		cout << arr[i] << ", ";
	}
	cout << endl;
}
//takes in 3 ints using call by pointer
//generates a random number between 25 and 50
//creates array on the heap of that length
//generates a random high and a low number between 5->10 and -10->-5, then fills array with random
//nunbers between the high and low ranges
int *func13(int *len, int *max, int *min){
	int x = rand()%25 + 25;
	int high = rand()%6 + 5;
	int low = -1 * (rand()%6 + 5);
	int *arr = new int[x];
	int range = high - low + 1;
	*len = x;
	*max = high;
	*min = low;

	for(int i = 0; i < x; i++){
			arr[i] = rand()%range + low;
	}

	return arr;
}
//Same as func 13 but it takes in and integer.
//creates array on the stack willed with random numbers
//Returns the address of the first value of the array
// Doesn't work because the array was made on the stack, the array get's DESTROYED after the function is called
int *func14(int num){
	int high = rand()%6 + 5;
	int low = -1 * (rand()%6 + 5);
	int arr[num];
	int range = high - low + 1;

	for(int i = 0; i < num; i++){
			arr[i] = rand()%range + low;
	}

	return arr;

}
//takes as input an array of ints, it then prints out the addresses of each value in the array
void func15(int arr[], int num){
	for(int i = 0; i < num; i++){
		cout << &arr[i] << ", ";
	}
	cout << endl;
}
//takes as a parameter an array of doubles, it then prints out the addresses of each value in the array
void func16(double arr[], int num){
	for(int i = 0; i<num; i++){
		cout << &arr[i] << ", ";
	}
	cout << endl;
}
//takes as input an array of ints, and the size of the array as a pointer
//itterates through the array and creates a new array on the heap with all the double numbers
//that are next to each other removed
//changes the array size to the size of the new array
//returns new array
int *func17(int arr[], int *num){
	int count = 0;
	for(int i = 0; i<*num;i++){
		if(i == 0 && arr[i] == arr[i + 1])
		{
			arr[i] = -1;
		}
		else if(i == (*num -1) && arr[i] == arr[i-1])
		{
			arr[i] = -1;
		}
		else if(arr[i] == arr[i-1] || arr[i] == arr[i +1])
		{
			arr[i] = -1;
		}
		else
		{
			count++;
		}

	}
	int removed = 0;
	int *arr2 = new int[count];
	 cout << count << endl;
	for(int i = 0; i<*num; i++){
		if(arr[i] > 0){
			arr2[i-removed] = arr[i];
		}
		else{
			removed++;
		}
	}

	*num = count;
	return arr2;
}
//for func 18 and 19 we are making a low pass filter that takes in an array, a size, and a window size
//these functions smooth the values
int func18(int arr[], int size){
	int av = 0;
	int a[size];
	int weight =0;

	for(int k =0; k<=size/2; k++){
		if(k != size/2){
			a[k] = arr[k]* (k+1);
			a[size - k-1] = arr[size - k-1] * (k+1);
			weight = weight +(2 * (k+1));
		}
		else{
			a[k] = arr[k] * (k+1);
			weight = weight + k + 1;
		}
	}

	for(int i = 0; i < size ;i++){
		av = a[i] + av;
	}
	return (av / weight);
}

int *func19(int arr[], int size, int window){
	int *nArr = new int[size];
	for(int k = 0; k<window/2;k++){
		nArr[k] = 0;
		nArr[size - k - 1] = 0;
	}
	for(int i=(window/2);i<size-(window/2);i++){
		nArr[i]= func18(&arr[i-(window/2)],window);
	}

	return nArr;
}

//takes as input an array, the length of the array, as well as the highest and lowest values in the array
//prints out a "*" for each value in the appropriate place
void func20(int arr[], int size, int max, int min){
	int range = max - min;
	unsigned long long int a[range] = {0};
	unsigned long long int k = 1;

	for(int i = 0; i<size; i++){
		for(int j = min; j<=max; j++){
			if(j == arr[i]){
				a[max - j] = (a[max - j] <<1) | 1; //We're representing the value in binary
			}
			else{
				a[max - j] = a[max - j] <<1;
			}
		}
	}

	for(int i = 0; i< size; i++){
		k = k *2;
	}

	for(int i = max; i>=min; i--){
		cout << i << ":";
		for(int j=0; j<=size;j++){
			if((a[max - i] & k) == k){
				cout << "*";
			}
			else
			{
				cout << " ";
			}
			a[max - i] = a[max - i] << 1;
		}
		cout << endl;
	}
}

//Takes as input 2 integer addresses
//generate a random number from 5->10, this represents the size of the array of addresses (y)
//generate another random int from 4->8, this is the size of each array of ints (x)
//created a 2d array of size y and x
//filled the array with zeroes, then generated 5 cords and set their coresponding cells to 1
//then printed it in main
//returns address of the 2d array
int **func21(int *x, int *y){
	*x = rand()%6 + 5;
	*y = rand()%5 + 4;
	int **arr = NULL;
	arr = new int *[*y];

	for(int i = 0; i< *y; i++){
		arr[i] = new int[*x];
	}

	for(int i = 0; i< *y; i++)
	{
		for(int j = 0; j < *x; j++){
			arr[i][j] = 0;
		}
	}

	for(int i =0; i<5;i++){
		int cX = rand()%(*x);
		int cY = rand()%(*y);
		if(arr[cY][cX] == 1)
		{
			i = i-1;
		}
		else{
			arr[cY][cX] = 1;
		}
	}
	return arr;
}



