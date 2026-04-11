#include <iostream>
#include "SinglyLinkedList.h"
using namespace std;
int main()
{
    SinglyLinkedList<int> list(5);
	list.push_front(10);
	list.push_front(15);
	list.print();
}

