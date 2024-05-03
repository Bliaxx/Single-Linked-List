#pragma once
#include <iostream>

template<typename T>
class Node
{
	T data;
	Node<T>* nextNode = nullptr;

public:
	Node(): data(T()) {}
	Node(const T& _value) : data(_value) {}

public:
	inline const T& GetData() const { return data; }
	inline T& GetData() { return data; }
	inline void SetData(const T& _value) { data = _value; }
	inline Node<T>* GetNextNode() const { return nextNode; }
	inline void SetNextNode(Node<T>* _nextNode) { nextNode = _nextNode; }

	inline bool operator==(const Node<T>& _otherNode) const { return data == _otherNode.data; }
	inline bool operator!=(const Node<T>& _otherNode) const { return data != _otherNode.data; }
	friend std::ostream& operator<<(std::ostream& _os, const Node<T>& _node)
	{
		if (!&_node)
		{
			_os << "Invalid Node.";
			return _os;
		}
		_os << "Node(data : " << _node.data << ")";
		return _os;
	}

};