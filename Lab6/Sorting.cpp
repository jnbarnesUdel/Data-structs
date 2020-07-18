/*
 * Sorting.cpp
 *
 *	TA: Moumita Bhattacharya
 *      Author: Jonathan Barnes, Shane Cincotta
 *      The functions are for lab 6
 */

//answers to questions
//because we have AC set as a friend class it has access to all the stuff in tree class
//findBeg and findEnd use quick sort
#include "Sorting.hpp"



void Sorting::insertionSort(wordInfo *arr[], int len){
	int j = 0;
	wordInfo *temp = arr[j];
	for(int i =1; i<len; i++){
		j = i;
		temp = arr[j];
		j--;
		while(j>=0 && temp->ct > arr[j]->ct){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
	}
	return;
}


void Sorting::selectionSort(wordInfo *arr[], int len){
	int max = 0;
	wordInfo *temp;
	for(int i = 0; i < len-1; i++){
		max = i;
		for(int j = i; j < len; j++){
			if(arr[j]->ct > arr[max]->ct){
				max = j;
			}
		}
		temp = arr[max];
		arr[max] = arr[i];
		arr[i] = temp;
	}

}
void Sorting::quickSort(wordInfo *arr[], int beg, int end){
	  if (end - beg > 1) {  // There is data to be sorted.
	    // Partition the table.
	    int pivot = partition(arr, beg, end);

	    // Sort the left half.
	    quickSort(arr, beg, pivot-1);

	    // Sort the right half.
	    quickSort(arr, pivot + 1, end);
	  }

}



int Sorting::partition(wordInfo *arr[],int beg,int end){
	int high = end;
	int low = beg;
	wordInfo *pivot = arr[high];    // pivot
	int i = (low - 1);  // Index of smaller element
	wordInfo *temp;
	for (int j = low; j <= high- 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (arr[j]->ct >= pivot->ct)
		{
			i++;    // increment index of smaller element
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	temp = arr[i+1];
	arr[i+1] = arr[high];
	arr[high] = temp;
	return (i + 1);
}
void Sorting::mergeSort(wordInfo *arr[],int l1,int l2){
	int l = l1;
	int r = l2;
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }

}
void Sorting::merge(wordInfo *arr[], int l, int m, int r){
	// used by mergeSort
	int i, j, k;
	int n1 = m - l + 1;
	int n2 =  r - m;

	wordInfo *L[n1];
	wordInfo *R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1+ j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2)
	{
		if (L[i]->ct > R[j]->ct)
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}


	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}

}
