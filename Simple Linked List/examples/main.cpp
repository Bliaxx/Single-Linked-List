#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList<int> myLinkedList;
	myLinkedList.InsertAtIndex(10, 0);
	myLinkedList.InsertAtIndex(20, 1);
	myLinkedList.InsertAtIndex(40, 2);
	myLinkedList.InsertAtIndex(60, 3);
	myLinkedList.InsertAtFront(5);
	myLinkedList.InsertAtEnd(70);
	myLinkedList.InsertAtIndex(30, 2);
	std::cout << myLinkedList << std::endl;
	myLinkedList.DeleteAtFront();
	myLinkedList.DeleteAtEnd();
	myLinkedList.DeleteAtIndex(2);
	std::cout << myLinkedList << std::endl;
	std::cout << "Front : " << myLinkedList.Front() << std::endl;
	std::cout << "Back : " << myLinkedList.Back() << std::endl;
}

