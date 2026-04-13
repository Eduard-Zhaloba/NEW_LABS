#include <iostream>
#include <string>
#include <stdexcept>
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"

using namespace std;
int main()
{
    SinglyLinkedList<int> list(5);
	DoublyLinkedList<int> list2;
	//list2.push_front2(5);
	//list2.push_back2(10);
	list2.push_back2(12);
	list2.push_back2(4);
	list2.push_back2(25);
	list2.push_back2(12);
	list2.push_back2(34);
	list2.push_back2(20);
	list2.push_back2(18);
	list2.remove2(7);
	//list2.insert2(0, 99);
	//list2.get_value2(105);
	//list2.delete_back2();
	
	
	//list2.push_front2(5);
	//list.push_front(6);
	//list.push_front(10);
	//list.push_back(5);
	//list.push_back(2);
	//list.push_back(1);
	//list.remove(2);
	//list.insert(1,20);
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
	//cout<<list;
	cout << list2;
}
