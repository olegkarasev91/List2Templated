#pragma once
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
template<typename T>
#define tab "\t"
//#define DEBUG
class List
{

	class Element
	{
		T Data;
		Element* pNext;
		Element* pPrev;
	public:
		Element(T Data, Element* pNext = nullptr, Element* pPrev = nullptr);
		~Element();
		friend class List;
	}*Head, * Tail;
	size_t size; // ������ ������
	class BaseIterator
	{
	protected:
		Element* Temp;
	public:
		BaseIterator(Element* Temp);
		~BaseIterator();
		bool operator==(const BaseIterator& other)const;
		bool operator!=(const BaseIterator& other)const;
		const int& operator*()const;
	};
public:
	class ConstIterator :public BaseIterator
	{
	public:
		ConstIterator(Element* Temp);
		~ConstIterator();
		ConstIterator& operator++();
		ConstIterator operator++(int);
		ConstIterator& operator--();
		ConstIterator operator--(int);
	};
	class Iterator :public ConstIterator
	{
	public:
		Iterator(Element* Temp);
		~Iterator();
		T& operator*();
	};
	class ConstReverseIterator :public BaseIterator
	{
	public:
		ConstReverseIterator(Element* Temp);
		~ConstReverseIterator();
		ConstReverseIterator& operator++();
		ConstReverseIterator operator++(int);
		ConstReverseIterator& operator--();
		ConstReverseIterator operator--(int);
	};
	class ReverseIterator : public ConstReverseIterator
	{
	public:
		ReverseIterator(Element* Temp);
		~ReverseIterator();
		T& operator*();
	};
	Iterator begin();
	Iterator end();
	ConstIterator cbegin()const;
	ConstIterator cend()const;
	ReverseIterator rbegin();
	ReverseIterator rend();
	ConstReverseIterator crbegin()const;
	ConstReverseIterator crend()const;
	List();
	List(const std::initializer_list<T>& il);
	List(const List<T>& other);
	~List();
	//Operators:
	List<T>& operator=(const List<T>& other);
	// Adding elements:
	void push_front(T Data);
	void push_back(T Data);
	void insert(T Data, int Index);
	// Removing elements:
	void pop_front();
	void pop_back();
	// Methods:
	void print()const;
	void print_reverse()const;
};