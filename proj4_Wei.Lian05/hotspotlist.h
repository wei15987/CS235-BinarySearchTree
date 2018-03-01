/******************************************************************************
  Title          : hotspotlist.h
  Author         : Wei Lian
  Created on     : December  5, 2017
  Description    : Interface for the Hotspotlist class
  Purpose        : The Hotspotlist class will organize Hotspot objects as a list.
  Modifications  : 

  Notes:
  This header file provides the interface to the Hotspotlist class, it will save all 
  Hotspot objects into a list, so we are able to modifile the list.
 
******************************************************************************/
#ifndef __HOTSPOTLIST_H__
#define __HOTSPOTLIST_H__


#include "hotspot.h"
#include "bst.h"
#include <string>
#include <iostream>
using namespace std;

class Hotspotlist
{
public:
	Hotspotlist();//default constructor
	
	int write(ostream & os);//print function

	int insert(const Hotspot & Hspot);//insert function

	int insert(Hotspotlist &hlist);//insert a hotspot list

	int remove(int ObjectId);//delete function

	int vector_size();//give the vector size of the hotspotlist.

	int size();//to get the size

	int find(int ObjectId,Hotspot &Hspot);//to find a function with given id, copy whole data to Hspot.

	int make_empty();//to make it empty

	void save_to_vector();//save all datas into a vector.

	void get(int num,Hotspot &Hspot);//get data from vector with num as index.

	void save_to_tree(string line);//save the record into linked list

	void find_write(int ObjectId, ostream & os);//find specific object id, and print it out

	void getid_distance(double latitude,double longitude,double distance,ostream &os);//get Object Ids which qualifies distance range.

	void getid_borocode(string borocode,ostream &os);//get Object IDs which qualifies specific borocode.


private:
	BST<Hotspot> hotspotlist;//by declare it with template, it has access to template class
};







#endif /*__HOTSPOTLIST_H__*/