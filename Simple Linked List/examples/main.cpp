#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList<int> myLinkedList;
	myLinkedList.InsertAtEnd(50);
	myLinkedList.InsertAtEnd(60);
	myLinkedList.InsertAtFront(10);
	std::cout << myLinkedList;
}

