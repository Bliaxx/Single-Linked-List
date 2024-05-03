#include <iostream>
#include "LinkedList.h"

int main()
{
    // Cr�ation de la liste cha�n�e
    LinkedList<int> myLinkedList;

    // Insertion d'�l�ments
    myLinkedList.InsertAtEnd(10);
    myLinkedList.InsertAtEnd(20);
    myLinkedList.InsertAtEnd(30);
    myLinkedList.InsertAtEnd(40);
    myLinkedList.InsertAtFront(0);
    myLinkedList.InsertAtIndex(25, 3); // Ins�re 25 � l'index 3

    // Affichage de la liste
    std::cout << "LinkedList apr�s insertions: ";
    for (int value : myLinkedList) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Recherche d'un �l�ment
    Node<int>* foundNode = myLinkedList.Find(25);
    if (foundNode != nullptr) {
        std::cout << "�l�ment trouv�: " << foundNode->GetData() << std::endl;
    }
    else {
        std::cout << "�l�ment non trouv�." << std::endl;
    }

    // Suppression d'�l�ments
    myLinkedList.DeleteAtFront(); // Supprime 0
    myLinkedList.DeleteAtEnd();   // Supprime 40
    myLinkedList.DeleteAtIndex(2); // Supprime 25

    // Affichage de la liste apr�s suppressions
    std::cout << "LinkedList apr�s suppressions: ";
    for (int value : myLinkedList) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Utilisation de l'op�rateur ==
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

    // D�monstration de Clear
    myLinkedList.Clear();
    std::cout << "LinkedList apr�s clear: ";
    for (int value : myLinkedList) {
        std::cout << value << " ";
    }
    std::cout << "(La liste devrait �tre vide maintenant)" << std::endl;

    return 0;
}