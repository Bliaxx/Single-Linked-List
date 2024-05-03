#include <iostream>
#include "LinkedList.h"

int main()
{
    // Création de la liste chaînée
    LinkedList<int> myLinkedList;

    // Insertion d'éléments
    myLinkedList.InsertAtEnd(10);
    myLinkedList.InsertAtEnd(20);
    myLinkedList.InsertAtEnd(30);
    myLinkedList.InsertAtEnd(40);
    myLinkedList.InsertAtFront(0);
    myLinkedList.InsertAtIndex(25, 3); // Insère 25 à l'index 3

    // Affichage de la liste
    std::cout << "LinkedList après insertions: ";
    for (int value : myLinkedList) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Recherche d'un élément
    Node<int>* foundNode = myLinkedList.Find(25);
    if (foundNode != nullptr) {
        std::cout << "Élément trouvé: " << foundNode->GetData() << std::endl;
    }
    else {
        std::cout << "Élément non trouvé." << std::endl;
    }

    // Suppression d'éléments
    myLinkedList.DeleteAtFront(); // Supprime 0
    myLinkedList.DeleteAtEnd();   // Supprime 40
    myLinkedList.DeleteAtIndex(2); // Supprime 25

    // Affichage de la liste après suppressions
    std::cout << "LinkedList après suppressions: ";
    for (int value : myLinkedList) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Utilisation de l'opérateur ==
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

    // Démonstration de Clear
    myLinkedList.Clear();
    std::cout << "LinkedList après clear: ";
    for (int value : myLinkedList) {
        std::cout << value << " ";
    }
    std::cout << "(La liste devrait être vide maintenant)" << std::endl;

    return 0;
}