/******************************************************************************
  Title          : bst.h
  Author         : Wei Lian
  Created on     : December  5, 2017
  Description    : Interface for the binary search tree template class
  Purpose        : The binary search tree template provides methods to organize data.
  Modifications  : 

  Notes:
  This header file provides the interface to the Binary search tree class, it will save data as 
  binary tree. Also it provides inorder traversal, so the datas will be sorted in order.
 
******************************************************************************/
#ifndef __BST_H__
#define __BST_H__

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<class T>
struct tree_node
{
	T data;
	tree_node * left;
	tree_node * right;
};

template<class T>
class BST
{
public:
	BST();//default constructor
	BST(const BST & tree);//copy constructor
	~BST();//destructor
	
	//copy method
	void copy_tree(tree_node<T> * tree_ptr, tree_node<T> *& new_ptr)const;
	
	//search methods
	//take a T type parameter, it will search the whole tree, and find if there is a node that is same to the parameter,if so it copys it.
	int retrieve(T& element);//helper for function to use recursion
	int find (tree_node<T> * & current,T& element);
	//methods to insert a whole list
	//get function takes two parameter, and it will pass the corresponding number in the vector, copy the data to the parameter.
	void get(int num,T & element);
	//get_data function to store all nodes of the tree into a vector in order
	void get_data();
	void get_data(tree_node<T> *current);
	//method to find the smallest node
	T findMin(tree_node<T> * & current);

	//Displaying the tree contents
	int print (ostream & out);
	//Displaying method
	int inorder(tree_node<T> *t,ostream &os);

	//tree modifiers
	int clear();//function to use recursion
	int clear(tree_node<T> * & current);//make it empty

	int insert(const T& element);//function to use recursion
	int insert (tree_node<T> * & current,const T& element);//insert

	int remove(const T& element);//function to use recursion
	int remove (tree_node<T> * & current,const T& element);//delete

	//give the size of the tree
	int get_size();
	int get_vector_size();//for inserting a list
	//to find the distance
	void find_distance(double latitude,double longitude,double distance,ostream &os);
	void find_distance_helper(tree_node<T> *current,double latitude,double longitude,double distance,ostream &os);
	//to find the borocode
	void find_borocode(string borocode,ostream &os);
	void find_borocode_helper(tree_node<T> *current,string borocode,ostream &os);
private:
	tree_node<T> * root;
	vector<T>htlist;
	int size;
	int time;

};



#include "bst.cpp"
#endif /*__BST_H__*/