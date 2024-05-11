#include <iostream>
#include "LinkedList.h"

int main()
{
    LinkedList<int> myLinkedList;

    myLinkedList.InsertAtEnd(10);
    myLinkedList.InsertAtEnd(20);
    myLinkedList.InsertAtEnd(30);
    myLinkedList.InsertAtEnd(40);
    myLinkedList.InsertAtFront(0);
    myLinkedList.InsertAtIndex(25, 3);

    std::cout << "LinkedList apr�s insertions: ";
    for (int value : myLinkedList) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    Node<int>* foundNode = myLinkedList.Find(25);
    if (foundNode != nullptr) {
        std::cout << "�l�ment trouv�: " << foundNode->GetData() << std::endl;
    }
    else {
        std::cout << "�l�ment non trouv�." << std::endl;
    }

    myLinkedList.DeleteAtFront();
    myLinkedList.DeleteAtEnd(); 
    myLinkedList.DeleteAtIndex(2); 

    std::cout << "LinkedList apr�s suppressions: ";
    for (int value : myLinkedList) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    LinkedList<int> anotherList;
    anotherList.InsertAtEnd(10);
    anotherList.InsertAtEnd(20);
    anotherList.InsertAtEnd(30);

    if (myLinkedList == anotherList) {
        std::cout << "Les deux listes sont identiques." << std::endl;
    }
    else {
        std::cout << "Les deux listes ne sont pas identiques." << std::endl;
    }

    myLinkedList.Clear();
    std::cout << "LinkedList apr�s clear: ";
    for (int value : myLinkedList) {
        std::cout << value << " ";
    }
    std::cout << "(La liste devrait �tre vide maintenant)" << std::endl;

    return 0;
}