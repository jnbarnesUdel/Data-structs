/*
 * Sorting.hpp
 *
 *	TA: Moumita Bhattacharya
 *      Author: Jonathan Barnes, Shane Cincotta
 *      The functions are for lab 6
 */

#ifndef SORTING_HPP_
#define SORTING_HPP_

#include "wordinfo.hpp"


class Sorting{
	public:
	void insertionSort(wordInfo *arr[], int len);
	void selectionSort(wordInfo *arr[], int len);
	void quickSort(wordInfo *arr[], int beg, int end);
	int partition(wordInfo *arr[],int beg,int end); // used by quickSort
	void mergeSort(wordInfo *arr[],int l1,int l2);
	void merge(wordInfo *arr[], int l, int m, int r); // used by mergeSort
};

#endif /* SORTING_HPP_ */
