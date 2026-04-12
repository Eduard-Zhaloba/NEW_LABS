#include <iostream>
#include <string>
#include <stdexcept>
#include "SinglyLinkedList.h"

using namespace std;
int main()
{
    SinglyLinkedList<int> list;
	list.push_front(6);
	list.push_front(10);
	list.push_back(5);
	list.push_back(2);
	list.push_back(1);
	list.remove(2);
	//list.insert(0,20);
	//list.delete_back();
	//list.delete_back();
	//list.delete_back();
	//list.delete_back();
	
		
	
	//list.push_back(71);
	//list.delete_back();
	//list.delete_back();
	//list.delete_back();
  
	//list.get_value(100);
	
	//list.find(7);
	cout<<list;
}
