#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList<int> myLinkedList;
	myLinkedList.InsertAtFront(10);
	myLinkedList.InsertAtFront(20);
	myLinkedList.InsertAtFront(30);
	std::cout << myLinkedList;
}

