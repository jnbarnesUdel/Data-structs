/*
/ * BSTY.cpp
 *	TA: Moumita Bhattacharya
 *  Created on: Oct 19, 2018
 *      Author: Jonathan Barnes, Shane Cincotta
 *      The functions are for lab 4
 */

#include "BSTY.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

BSTY::BSTY() {
	root = NULL;
}

// You write:  insert a new node with data x (a string) into the 
// binary search tree
// This method should return true if a new node is inserted and 
// false if the data x is already in the tree
// Remember to check whether the new node will be the root
// (meaning the root is currently NULL) and if so, set the root
// to be the new node.
// Note: Make sure you make the new node point to its parent!!! 
// Note2: after you've inserted a new node, you should call the 
// adjustHeights method that will update the heights of all the 
// ancestors of the node that was just inserted.
bool BSTY:: insertit(string x ) {
	NodeT *n = new NodeT(x);
	NodeT *temp = root;
	while(1){
		if(temp == NULL){
			root = n;
			adjustHeights(n);
			return true;
		}
		else if(temp->data == x){
			return false;
		}
		else if(temp->data > x){
			if(temp->left != NULL){
				temp = temp->left;
			}
			else{
				temp->left = n;
				n->parent = temp;
				adjustHeights(n);
				return true;
			}
		}
		else if(temp->data < x){
			if(temp->right != NULL){
				temp = temp->right;
			}
			else{
				temp->right = n;
				n->parent = temp;
				adjustHeights(n);
				return true;
			}
		}
	}
	return false;
}

bool BSTY::insertit(string x, string y){
	NodeT *n = new NodeT(x, y);
	NodeT *temp = root;
	while(1){
		if(temp == NULL){
			root = n;
			adjustHeights(n);
			return true;
		}
		else if(temp->data == x){
			return false;
		}
		else if(temp->data > x){
			if(temp->left != NULL){
				temp = temp->left;
			}
			else{
				temp->left = n;
				n->parent = temp;
				adjustHeights(n);
				return true;
			}
		}
		else if(temp->data < x){
			if(temp->right != NULL){
				temp = temp->right;
			}
			else{
				//*******last for Ibax
				temp->right = n;
				n->parent = temp;
				adjustHeights(n);
				return true;
			}
		}
	}
	return false;

}

void BSTY::doTheHeights(NodeT *temp){
		//adjust heights for not root
		if(temp->left != NULL && temp->right != NULL){
			if(temp->left->height > temp->right->height){
				temp->height =temp->left->height + 1;
			}
			else{
				temp->height = temp->right->height + 1;
			}
		}
		else if(temp->left == NULL && temp->right !=NULL){
			temp->height = temp->right->height + 1;
		}
		else if(temp->left !=NULL && temp->right == NULL)
		{
			temp->height = temp->left->height +1;
		}
		else{
			temp->height = 1;
		}
}

// the adjustHeights method updates the heights of every ancestor of the node n.
// This method will be massively useful with our next lab, so make sure you have
// this working now.  It should be called whenever you change the height of a
// a particular node.  So, for instance, when a new node is inserted as a leaf,
// its height is 1.  The adjustHeights method should then check the parent to see
// if the height of the parent changes (the height of each node is the maximum of
// the height of the left child and the height of the right child, plus 1).  If
// the parent's height changes, then the grandparent's height should be checked and,
// if necessary, adjusted.  If the grandparent's height is updated, then the great-
// grandparent's height should be adjusted, etc.  The checking stops when either
// the loop has worked its way up to the root, or until the currently being checked
// ancestor is not changed.
void BSTY::adjustHeights(NodeT *n) {
	NodeT *temp = n;
	do{
		while(temp != root){
			doTheHeights(temp);

			//find balance for not root
			if(findBalance(temp) > 1){
				if(findBalance(temp->left) >0){
					rotateRight(temp);
				}
				else{
					temp->left = rotateLeft(temp->left);
					temp = temp->left;
					doTheHeights(n);
				}
			}
			else if(findBalance(temp) < -1){
				if(findBalance(temp->right) <0){
					//ibex stuck in perm right left because thing says it has zero balance on right but -2 for main node
					rotateLeft(temp);
				}
				else{
					//this is the place
					//cout << findBalance(temp) << " temp" << endl;
					//cout << findBalance(temp->right)<<endl;
					  temp->right = rotateRight(temp->right);
					  temp=temp->right;
					  doTheHeights(n);
				}
			}

			doTheHeights(temp);
			temp = temp->parent;
		}

		doTheHeights(temp);

		//for root find Balance
		if(findBalance(temp) > 1){
			if(findBalance(temp->left) >0){
				root = rotateRight(temp);

			}
			else{
				temp->left = rotateLeft(temp->left);
				doTheHeights(n);
			}
		}
		else if(findBalance(temp) < -1){
			if(findBalance(temp->right) <0){
				root = rotateLeft(temp);
			}
			else{
				  temp->right = rotateRight(temp->right);
				  doTheHeights(n);
			}
		}

		doTheHeights(temp);
	}while((findBalance(root) > 1) || (findBalance(root) < -1));
}

void BSTY::printTreeIO() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		printTreeIO(root);
	}
}

// Print the tree in order (left child, then parent, then right child).
// Use the slides, but make sure you can understand how the tree is 
// traversed in order
void BSTY::printTreeIO(NodeT *n) {
	if (n == NULL) {
		return;
	}
	else {
		printTreeIO(n->left);
		n->printNode();
		printTreeIO(n->right);
	}

	/*
	if(temp.left != NULL){
		temp = temp.left;
		count_of_unprint_p++;
	}
	else if(!node_done){
		cout << temp.data << ", ";
		node_done = true;
	}
	else if(node_done){
		if(temp.right != NULL){

		}
		else{

		}
	}My sadness*/

}

void BSTY::printTreePre() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		printTreePre(root);
	}
}

// Prints the tree using pre-order traversal (parent, then left child, then right
// child.  Use the slides, but make sure you understand how a tree is traversed in
// pre-order
void BSTY::printTreePre(NodeT *n) {

	if (n == NULL) {
		return;
	}
	else {
		n->printNode();
		printTreePre(n->left);
		printTreePre(n->right);
	}


}

void BSTY::printTreePost() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		printTreePost(root);
		cout << endl;
	}
}

// Prints the tree using pre-order traversal (left child, then right, then parent)
// Use the slides, but make sure you understand how a tree is traversed in
// post-order
void BSTY::printTreePost(NodeT *n) {
	if (n == NULL) {
		return;
	}
	else {
		printTreePost(n->left);
		printTreePost(n->right);
		n->printNode();
	}
}

void BSTY::myPrint() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		myPrint(root);
		cout << endl;
	}
}
void BSTY::myPrint(NodeT *n) {
	if (n == NULL) {
		return;
	}
	else {
		myPrint(n->left);
		cout << n->data.length()-1;
		if (mine) {
			cout <<".";
			mine = false;
		}
		myPrint(n->right);
	}
}

// the find method takes as input a string, and finds whether that string is already
// in the tree or not.  If it is in the tree, that node is returned from the tree.
// If it isn't, NULL is returned.  
// NOTE: If the node can't be found, this method prints out that x can't be found.
// if it is found, the printNode method is called for the node.  
NodeT *BSTY::find(string x) {
	NodeT *n = root;
	int count = 1;
	while(n != NULL){
		if(n->data == x){
			n->printNode();
			cout<< count << endl;
			return n;
		}
		else if(n->data > x){
			n = n->left;
		}
		else{
			n = n->right;
		}
		count++;
	}
	return NULL;

}

int BSTY::findBalance(NodeT *n){
	if(n != NULL){
		if(n->left !=NULL && n->right != NULL){
			return n->left->height - n->right->height;
		}
		else if(n->left != NULL && n->right == NULL){
			return n->left->height;
		}
		else if(n->left == NULL && n->right != NULL){
			return (-1) * n->right->height;
		}
		else
		{
			return 0;
		}
	}
	else{
		return 0;
	}
}

NodeT *BSTY::rotateRight(NodeT *n){
	NodeT *x = n->left;
	if(n != root){
		///which child of n's parent's children does x become?
		if(n->parent->left == NULL){
			n->parent->right = x;
		}
		else if(n->parent->right == NULL){
			n->parent->left = x;
		}
		else
		{
			if(n == n->parent->left){
				n->parent->left = x;
			}
			else{
				n->parent->right = x;
			}
		}
		x->parent = n->parent;
		n->parent = x;

		//if right is not null make right the left of thing
		if(x->right != NULL){
			NodeT *tmp = x->right;
			x->right = n;
			n->left = tmp;
			tmp->parent = n;
		}
		else{
			x->right = n;
			n->left = NULL;
		}
	}
	else{
		//x=root;
		x->parent = NULL;
		n->parent = x;
		if(x->right != NULL){
			NodeT *tmp = x->right;
			x->right = n;
			n->left = tmp;
			tmp->parent = n;
		}
		else{
			x->right = n;
			n->left = NULL;
		}
	}
	doTheHeights(n);
	doTheHeights(x);
	//adjustHeights(n);
	return x;
}

NodeT *BSTY::rotateLeft(NodeT *n){
	NodeT *x = n->right;

	if(n != root){
		//which child of n's parent's children does x become?
		if(n->parent->left == NULL){
			n->parent->right = x;
		}
		else if(n->parent->right == NULL){
			n->parent->left = x;
		}
		else
		{
			if(n->parent->left == n){
				n->parent->left = x;
			}
			else{
				n->parent->right = x;
			}
		}
		x->parent = n->parent;
		n->parent = x;

		if(x->left != NULL){
			NodeT *tmp = x->left;
			x->left = n;
			n->right = tmp;
			tmp->parent = n;
		}
		else{
			x->left = n;
			n->right = NULL;
		}
	}
	else{
		//root = x;
		n->parent = x;
		x->parent = NULL;

		if(x->left != NULL){
			NodeT *tmp = x->left;
			x->left = n;
			n->right = tmp;
			tmp->parent = n;
		}
		else{
			x->left = n;
			n->right = NULL;
		}
	}
	doTheHeights(n);
	doTheHeights(x);
	//adjustHeights(n);
	return x;
}


/*************************************************************************************/
/* Extra Credit Methods                                                              */
/* Challenging: worth 35 EC pts to go towards labs                                   */
/* NOTE: IF YOU CHOOSE NOT TO IMPLEMENT THESE METHODS, YOU ARE STILL RESPONSIBLE FOR */
/* UNDERSTANDING HOW THEY WORK!!                                                     */
/*************************************************************************************/
/* When removing a node from a binary search tree, the resulting tree MUST BE a binary
/* search tree.  
/*
/* When removing a node, there are 3 conditions:
/* 1: when the node being removed has no children, in which case the node is deleted,
/* the node's parent is set to NULL, and the node's parent's height is adjusted (if
/* necessary) and heights on up are adjusted.
/* 2: when the node being removed has one child, in which case the node's parent points
/* to the node's child, and the node's child points to the node's parent, and the node
/* is deleted (and the height of the parent on up as necessary is adjusted)
/* 3: when the node has 2 children, in which case the left-most child of the node's 
/* right child replaces the node.  
/* A couple of notes about this one: you are replacing a node with a node that is lower
/* down in the tree.  That means that you are, in essence, removing the node from that
/* lower position and moving it up to the old node's location.  Thus the replacing node
/* must be removed using 1 or 2 above (why not 3?).  The heights must be adjusted after 
/* the replacing node is removed from its old location but before it is inserted into its 
/* new location.  Equally, the replacing node's height must be adjusted to be the larger of
/* its two children's heights before you adjust heights above that.  
/*****************************************************************************************/
/* remove(): takes as input a string, uses the find method to find the node in the tree that
/* holds that string, and then calls replace1, replace2, or replace3 depending on what type
/* of replacing should be done.  It adjusts the heights, deletes teh node, and returns 
/* true if the removal was successful.
*/
bool BSTY::remove(string s) {

	NodeT *n = find(s);
	NodeT *temp = n->parent;

	if(n == NULL){
		return false;
	}
	else if(n->left == NULL && n->right == NULL){
		remove1(n);
		if(n != root){
			adjustHeights(temp);
		}
		return true;
	}
	else if(((n->left == NULL) xor (n->right == NULL))){
		remove2(n);
		if(n != root){
			adjustHeights(temp);
		}
		return true;
	}
	else if(n->left != NULL)
	{
		remove3(n);
		if(n != root){
			adjustHeights(temp);
		}
		return true;
	}
	/*
	NodeT *temp = root;
	while(1){
		if(temp->data == s){
			if(temp->left == NULL && temp->right == NULL){
				remove1(temp);
				return true;
			}
			else if((temp->left != NULL) xor (temp->right != NULL)){
				remove2(temp);
				return true;
			}
			else if(temp->left != NULL && temp->right != NULL){
				remove3(temp);
				return true;
			}
		}
		else if(temp->data > s){
			if(temp->left == NULL){
				return false;
			}
			else{
				temp = temp->left;
			}
		}
		else if(temp->data < s){
			if(temp->right == NULL){
				return false;
			}
			else{
				temp = temp->right;
			}
		}
	}
*/

}

/* remove1(): called when the node to be removed has no children. Takes as input the 
/* node to be removed, and sets the parent of the node to point to NULL.
/* helpful hint: if (n->parent->left == n) is true, then n is its parent's left child.
/* Make sure you check to whether n is the root or not.
*/
void BSTY::remove1(NodeT *n) {
	if(n == root){
		n = NULL;
	}
	else
	{
		if(n->parent->left == n){
			n->parent->left = NULL;
		}
		else{
			n->parent->right = NULL;
		}
		n = NULL;
	}

}

/* remove2(): called when the node to be removed has 1 child only.  Takes as input
/* the node to be removed and bypasses it by making the parent point to the node's
/* one child, and makes the node's one child point to the node's parent.  
/* This one needs a bunch of checking - you need to see if the node is the parent's
/* left or right child, and you need to see if the node's child is its left or its
/* right child.
/* Also, make sure you check that if the node to be removed is the root, then the 
/* one child becomes the root.
*/ 
void BSTY::remove2(NodeT *n) {
	NodeT *p = new NodeT("s");
	if(n == root){
		if(n->left != NULL){
			root = n->left;
		}
		else{
			root = n->right;
		}
	}
	else{
		if(n->parent->left == n){
			if(n->left != NULL){
				n->parent->left = n->left;
				n->left->parent = n->parent;
				p= n->parent;
			}
			else
			{
				n->parent->left = n->right;
				n->right->parent = n->parent;
				p= n->parent;
			}
		}
		else{
			if(n->left != NULL){
				n->parent->right = n->left;
				n->left->parent = n->parent;
				p= n->parent;
			}
			else
			{
				n->parent->right = n->right;
				n->right->parent = n->parent;
				p= n->parent;
			}
		}
	}
	n = NULL;
	adjustHeights(p);

}

/* remove3(): called when the node to be removed has 2 children.  Takes as input the
/* node to be removed.  The node to replace the node to be removed should be the 
/* left-most descendent of the node's right child.  That way the binary search tree
/* properties are guaranteed to be maintained.
/* When replacing the node to be removed with the replacing node, the replacing node
/* is, in essence, being removed from its place in the tree, and thus replace1 or 
/* replace2 methods should be used.
/* The new node's parent must be set to the removed node's parent, the removed node's
/* parent must point to the new node, the new node's left child must point to the 
/* removed node's left child (and the child must point to the new node as a parent), 
/* and the same for teh right child.
/* Remember to take into account that the node being removed might be the root.
*/
void BSTY::remove3(NodeT *n) {
	NodeT *min = findMin(n);
	NodeT *p = new NodeT("s");
	if(n != root){
		p = min->parent;
		min->parent->left = min->right;
		min->parent = n->parent;
		min->right = n->right;
		min->left = n->left;
		if(n->parent->left == n){
			n->parent->left = min;
		}
		else{
			n->parent->right = min;
		}
	}
	else
	{
		p = min->parent;
		min->parent->left = min->right;
		min = root;
		min->right = n->right;
		min->left = n->left;
	}
	n = NULL;
	adjustHeights(p);
}

/* findMin(): takes as input a node, and finds the left-most descendant of its 
/* right child.  The left-most descendent is returned.
*/
NodeT *BSTY::findMin(NodeT *n) {
	NodeT *temp = n->right;
	while(1){
		if(temp->left == NULL){
			return temp;
		}
		else{
			temp = temp->left;
		}
	}
}

void BSTY::myPrintEC() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		myPrintEC(root);
		cout << endl;
	}
}
void BSTY::myPrintEC(NodeT *n) {
	if (n == NULL) {
		return;
	}
	else {
		myPrintEC(n->left);
		cout << alpha[n->data.length()-2];
		myPrintEC(n->right);
	}
}


/************************************************************************/

