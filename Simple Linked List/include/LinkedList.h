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
	LinkedList(const LinkedList<T>& _other)
	{
		Node<T>* _currentNode = _other.head;
		while (_currentNode != nullptr)
		{
			InsertAtEnd(_currentNode->GetData());
			_currentNode = _currentNode->GetNextNode();
		}
	}
	~LinkedList() { Clear(); }

public:
	class Iterator
	{
		Node<T>* currentNode = nullptr;

	public:
		Iterator(Node<T>* _node) : currentNode(_node) {}

	public:
		T& operator*() const { return currentNode->GetData(); }
		Iterator& operator++()
		{
			currentNode = currentNode->GetNextNode();
			return *this;
		}
		bool operator==(const Iterator& _other) const { return currentNode == _other.currentNode; }
		bool operator!=(const Iterator& _other) const { return currentNode != _other.currentNode; }
	};
	inline const T& Front() const { return head->GetData(); }
	inline const T& Back() const { return tail->GetData(); }

	const size_t GetSize() const { return length; }

	inline bool IsEmpty() const { return GetSize() == 0; }

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

	void DeleteAtIndex(const size_t _index)
	{
		if (_index >= length) {
			throw std::out_of_range("Index is out of range.");
		}

		Node<T>* currentNode = head;
		if (_index == 0) {
			head = head->GetNextNode();
			delete currentNode;
			if (length == 1)
			{
				tail = nullptr;
			}
		}
		else {
			Node<T>* prevNode = nullptr;
			for (size_t i = 0; i < _index; ++i) {
				prevNode = currentNode;
				currentNode = currentNode->GetNextNode();
			}
			prevNode->SetNextNode(currentNode->GetNextNode());
			if (_index == length - 1)
			{
				tail = prevNode;
			}
			delete currentNode;
		}
		--length;
	}

	void DeleteAtFront()
	{
		if (length == 0) {
			throw std::out_of_range("List is empty.");
		}
		DeleteAtIndex(0);
	}

	void DeleteAtEnd()
	{
		if (length == 0) {
			throw std::out_of_range("List is empty.");
		}
		DeleteAtIndex(length - 1);
	}

	void Clear()
	{
		Node<T>* _currentNode = head;
		while (_currentNode != nullptr)
		{
			Node<T>* _tempNodeToDelete = _currentNode;
			_currentNode = _currentNode->GetNextNode();
			delete _tempNodeToDelete;
		}
		head = nullptr;
		tail = nullptr;
		length = 0;
	}

	LinkedList& operator=(const LinkedList<T>& _other)
	{
		if (this != &_other)
		{
			Clear();

			Node<T>* _currentNode = _other.head;
			while (_currentNode != nullptr) {
				InsertAtEnd(_currentNode->GetData());
				_currentNode = _currentNode->GetNextNode();
			}
		}
		return *this;
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

	Iterator begin() const { return Iterator(head); }
	Iterator end() const { return Iterator(nullptr); }
};

