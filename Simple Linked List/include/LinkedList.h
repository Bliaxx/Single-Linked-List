#pragma once

#include "Node.h"

template<typename T>
class LinkedList
{
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	size_t length = 0;

public:
	LinkedList() = default;
	~LinkedList()
	{
		Node<T>* _currentNode = head;
		while (_currentNode != nullptr)
		{
			Node<T>* _tempNodeToDelete = _currentNode;
			_currentNode = _currentNode->GetNextNode();
			delete _tempNodeToDelete;
		}
		length = 0;
	}

public:
	void InsertAtFront(const T& _value)
	{
		InsertAtIndex(_value, 0);
	}
	
	void InsertAtEnd(const T& _value)
	{
		InsertAtIndex(_value, length);
	}

	void InsertAtIndex(const T& _value, const size_t _index)
	{
		if (_index > length) {
			throw std::out_of_range("Index is out of range.");
		}

		if (_index == 0) {
			Node<T>* newNode = new Node<T>(_value);
			newNode->SetNextNode(head);
			head = newNode;
			if (length == 0) {
				tail = newNode;
			}
		}
		else {
			Node<T>* currentNode = head;
			for (size_t i = 0; i < _index - 1; ++i) {
				currentNode = currentNode->GetNextNode();
			}
			Node<T>* newNode = new Node<T>(_value);
			newNode->SetNextNode(currentNode->GetNextNode());
			currentNode->SetNextNode(newNode);
			if (_index == length) {
				tail = newNode;
			}
		}
		++length;
	}

	friend std::ostream& operator<<(std::ostream& _os, const LinkedList<T>& _list)
	{
		Node<T>* _currentNode = _list.head;
		while (_currentNode != nullptr)
		{
			_os << _currentNode->GetData() << "->";
			_currentNode = _currentNode->GetNextNode();
		}
		_os << "nullptr";
		return _os;
	}
};

