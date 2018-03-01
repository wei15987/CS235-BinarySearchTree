/*******************************************************************************
  Title          : hotspotlist.cpp
  Author         : Wei Lian
  Created on     : December 5, 2017
  Description    : Implementation to the hotspotlist class
  Purpose        : The Hotspotlist class will organize Hotspot objects as a list.
  Usage          : 
  Build with     : 
  Modifications  : 

*******************************************************************************/
#include "hotspotlist.h"

using namespace std;

Hotspotlist::Hotspotlist()
{
	//default constructor
}

int Hotspotlist:: write(ostream & os)
{
	//it has access to the template class, so call the function from the template class, it is print function
	return hotspotlist.print(os);
}

int Hotspotlist:: insert(const Hotspot & Hspot)
{
	//call the insert function from the template class
	return hotspotlist.insert(Hspot);
}
//insert a whole hotspotlist
int Hotspotlist::insert(Hotspotlist &hlist)
{
	int size=0;
	int cter=0;
	//create a temporary hotspot object
	Hotspot temp;
	//let the list that we wanted to copy save it's nodes into vector
	hlist.save_to_vector();
	//while we still in the size of the vector
	while(cter<hlist.vector_size())
	{
		//use the get methods to get the data, and the temp will be copied with valid parameter.
		hlist.get(cter,temp);
		//if it successfully insert, size+1 which counts how many items we successfully inserted.
		if(insert(temp)==1)
		{
			size++;
			cter++;
		}
		else
			//if the item is already exist in our list, we don't increase the size
			cter++;
	}
	return size;

}

//call the delete function
int Hotspotlist::remove(int ObjectId)
{
	//create a temporary hotspot object
	Hotspot temp;
	//retrieve the data with specific object id
	find(ObjectId,temp);
	return hotspotlist.remove(temp);
}

int Hotspotlist::vector_size()
{
	return hotspotlist.get_vector_size();
}

int Hotspotlist::size()
{
	//get size
	return hotspotlist.get_size();
}
int Hotspotlist::find(int ObjectId,Hotspot &Hspot)
{
	//retrieve function 
	Hspot.set(ObjectId,"","","","","",0,0,"");
	return hotspotlist.retrieve(Hspot);
}
int Hotspotlist::make_empty()
{
	//make the list empty
	return hotspotlist.clear();
}

void Hotspotlist::save_to_vector()
{
	//save the hotspotlist into a vector which sorted order
	hotspotlist.get_data();
}
void Hotspotlist::get(int num,Hotspot &Hspot)
{
	//get specific data from the vector, which specific index
	hotspotlist.get(num,Hspot);
}
//get ids with specific distance range
void Hotspotlist::getid_distance(double latitude,double longitude,double distance,ostream &os)
{
	hotspotlist.find_distance(latitude,longitude,distance,os);

}
//get ids with specifc borocode
void Hotspotlist::getid_borocode(string borocode,ostream &os)
{
	hotspotlist.find_borocode(borocode,os);
}
void Hotspotlist::find_write(int ObjectId,ostream &os)
{
	//to find the specifc objectid,and print it out
	Hotspot temp;
	find(ObjectId,temp);
	temp.print(os);
}
void Hotspotlist::save_to_tree(string line)
{
	//save the data into hotspotlist.
	Hotspot temp(line);
	insert(temp);

}