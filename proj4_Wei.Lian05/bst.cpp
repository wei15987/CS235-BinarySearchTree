/******************************************************************************
  Title          : bst.cpp
  Author         : Wei Lian
  Created on     : December  5, 2017
  Description    : Inplementation for the binary search tree template class
  Purpose        : The binary search tree template provides methods to organize data.
  Modifications  : 

  Notes:
  This header file provides the interface to the Binary search tree class, it will save data as 
  binary tree. Also it provides inorder traversal, so the datas will be sorted in order.
 
******************************************************************************/
#include "bst.h"

using namespace std;

template<class T>
BST<T>::BST()
{
	root=NULL;
	size=0;
	time=0;
}
template<class T>
BST<T>::BST(const BST & tree)
{
	copy_tree(tree.root,root);
}
template<class T>
BST<T>::~BST()
{
	clear(root);
}
template<class T>
void BST<T>::copy_tree(tree_node<T> * tree_ptr, tree_node<T> *& new_ptr)const
{
	//pre order traversal
	if(tree_ptr!=NULL)
	{
		//copy node
		new_ptr=new tree_node<T>;
		new_ptr->data=tree_ptr->data;
		new_ptr->left=NULL;
		new_ptr->right=NULL;
		copy_tree(tree_ptr->left,new_ptr->left);
		copy_tree(tree_ptr->right,new_ptr->right);
	}
	else
		new_ptr=NULL;//copy empty tree
}
//find the specific data
template<class T>
int BST<T>::retrieve (T& element)
{
	return find(root,element);
	
}
template<class T>
int BST<T>::find(tree_node<T> * & current,T& element)
{
	if(NULL==current)
	{
		//current node is empty
		return 0;
	}
	else
	{
		if(element<current->data)
		{
			find(current->left,element);
		}
		else if(current->data<element)
		{
			find(current->right,element);
		}
		else//element==current->data(found it)
		{
			element=current->data;//assign current->data to element
			return 1;//success
		}
	}
	return 0;
}
//get the data from the vector with provided index number
template<class T>
void BST<T>::get(int num,T &element)
{
	if(htlist.size()>num)
	{
		element=htlist[num];
	}
}
//use recursion to save all nodes inorder to vector.
template<class T>
void BST<T>::get_data()
{
	get_data(root);
}
template<class T>
void BST<T>::get_data(tree_node<T> *current)
{
	if(current!=NULL)
	{
		if(current->left!=NULL)
			get_data(current->left);
		htlist.push_back(current->data);
		if(current->right!=NULL)
			get_data(current->right);
		
	}
}
//find the smallest item
template<class T>
T BST<T>::findMin(tree_node<T> * & current)
{
	T temp;//empty object;
	if(NULL==current)
		return temp;
	if(current->left==NULL)
		return current->data;

	return findMin(current->left);

}
//in-order traversal
template<class T>
int BST<T>::inorder(tree_node<T> *t,ostream &os)
{
	if(t!=NULL)
	{
		if(t->left!=NULL)
		{
			inorder(t->left,os);
		}
		//time counts how many time it prints
		t->data.print(os);
		time++;
		if(t->right!=NULL)
		{
			inorder(t->right,os);
		}
	}
	return time;
}
template<class T>
int BST<T>::print (ostream & out)
{
	//use the inorder recursion
	return inorder(root,out);
}
//make the tree empty, this function is a recursion helper
template<class T>
int BST<T>::clear()
{
	return clear(root);
}
template<class T>
int BST<T>::clear(tree_node<T> * & current)
{
	//postorder traversal
	if(current!=NULL)
	{
		//use recursion to delete all nodes
		clear(current->left);
		clear(current->right);
		delete current;
		--size;
		time++;
		current=NULL;
	}
	return time;
}
template<class T>
int BST<T>::insert (const T& element)
{
	return insert(root,element);
}
template<class T>
int BST<T>::insert (tree_node<T> * & current,const T& element)
{
	//if the list is empty, let the new item be the first node
	if(current==NULL)
	{
		current=new tree_node<T>;
		current->data=element;
		current->left=NULL;
		current->right=NULL;
		size++;
		return 1;
	}
	else if(element<current->data)
	{
		insert(current->left,element);
	}
	else if(current->data<element)
	{
		insert(current->right,element);
	}
	else
		return 0;//the new element is on the list
		
}
template<class T>
int BST<T>::remove (const T& element)
{
	return remove(root,element);
}
template<class T>
int BST<T>::remove (tree_node<T> * & current,const T& element)
{
	if(current==NULL)
		return 0;//empty
	else if(element<current->data)
	{
		remove(current->left,element);
	}
	else if(current->data<element)
	{
		remove(current->right,element);
	}
	else
	{
		//element is equal to the data in the node
		//check how many sub-tree the node has
		if(current->left!=NULL&&current->right!=NULL)
		{
			//the function findmin will find the smallest item in the tree
			//copy the item to current node
			current->data=findMin(current->right);
			//recursively call delete to delete the item that was just copied
			remove(current->right,current->data);
		}
		//the current node has at most one child, copy the value of current temporarily
		else
		{
			tree_node<T> * temp;
			temp=current;
			//if the left subtree is not empty,then make the left subtree the subtree of the root of current. By assigning to current
			//else if the left subtree is empty, then either the right is empty or it is not, in either case we can set current to point to its right subtree
			if(current->left!=NULL)
			{
				current=current->left;
			}
			else
			{
				current=current->right;
			}
			delete temp;
			--size;
			return 1;
		}
	}
	return 0;
}
//get the size of vector
template<class T>
int BST<T>::get_vector_size()
{
	return htlist.size();
}
//get the size of the tree
template<class T>
int BST<T>::get_size()
{
	return size;
}

template<class T>
void BST<T>::find_distance(double latitude,double longitude,double distance,ostream &os)
{
	find_distance_helper(root,latitude,longitude,distance,os);
}
template<class T>
void BST<T>::find_distance_helper(tree_node<T> *current,double latitude,double longitude,double distance,ostream &os)
{
	int temp_ObjectID;
	string temp_Boro;
	string temp_Type;
	string temp_Provider;
	string temp_Name;
	string temp_Location;
	double temp_Latitude;
	double temp_Longitude;
	string temp_SSID;
	//inorder traversal
	//search the whole tree, if it finds the data that qualifies the conditions, it prints out the Id numbers.
	//since it is inorder traversal, the order will be sorted.
	if(current!=NULL)
	{
		if(current->left!=NULL)
		{
			find_distance_helper(current->left,latitude,longitude,distance,os);
		}
		current->data.get(temp_ObjectID,temp_Boro,temp_Type,temp_Provider,temp_Name,temp_Location,temp_Latitude,temp_Longitude,temp_SSID);
		if(current->data.haversine(temp_Latitude,temp_Longitude,latitude,longitude)<=distance)
		{
			current->data.print_obejctid(os);
		}
		if(current->right!=NULL)
		{
			find_distance_helper(current->right,latitude,longitude,distance,os);
		}
	}
}
template<class T>
void BST<T>::find_borocode(string borocode,ostream &os)
{
	find_borocode_helper(root,borocode,os);
}
//inorder traversal
//search the whole tree, if it finds the data that qualifies the conditions, it prints out the Id numbers.
//since it is inorder traversal, the order will be sorted.
template<class T>
void BST<T>::find_borocode_helper(tree_node<T> *current,string borocode,ostream &os)
{
	int temp_ObjectID;
	string temp_Boro;
	string temp_Type;
	string temp_Provider;
	string temp_Name;
	string temp_Location;
	double temp_Latitude;
	double temp_Longitude;
	string temp_SSID;
	if(current!=NULL)
	{
		if(current->left!=NULL)
		{
			find_borocode_helper(current->left,borocode,os);
		}
		current->data.get(temp_ObjectID,temp_Boro,temp_Type,temp_Provider,temp_Name,temp_Location,temp_Latitude,temp_Longitude,temp_SSID);
		if(temp_Boro==borocode)
		{
			current->data.print_obejctid(os);
		}
		if(current->right!=NULL)
		{
			find_borocode_helper(current->right,borocode,os);
		}
	}
}
