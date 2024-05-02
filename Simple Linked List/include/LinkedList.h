#pragma once

#include "Node.h"

template<typename T>
class LinkedList
{
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;

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
	}

public:
	void InsertAtFront(const T& _value)
	{
		Node<T>* _newNode = new Node<T>(_value);
		if (!head)
		{
			head = _newNode;
			tail = _newNode;
		}
		else
		{
			_newNode->SetNextNode(head);
			head = _newNode;
		}
	}
	
	void InsertAtEnd(const T& _value)
	{
		if (!tail)
		{
			InsertAtFront(_value);
		}
		else
		{
			Node<T>* _newNode = new Node<T>(_value);
			tail->SetNextNode(_newNode);
		}
	}

	void InsertAtIndex(const T& _value, const size_t _index)
	{

	}

	friend std::ostream& operator<<(std::ostream& _os, const LinkedList<T>& _list)
	{
		Node<T>* _currentNode = _list.head;
		while (_currentNode != nullptr)
		{
			_os << _currentNode->GetData() << "->";
			_currentNode = _currentNode->GetNextNode();
		}
		return _os;
	}
};

