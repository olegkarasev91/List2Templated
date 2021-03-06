#include "List.h"

template<typename T>
List<T>::Element::Element(T Data, Element* pNext, Element* pPrev) :
	Data(Data), pNext(pNext), pPrev(pPrev)
{
	cout << "EConstructor:\t" << this << endl;
}
template<typename T>
List<T>::Element::~Element()
{
	cout << "EDestructor:\t" << this << endl;
}
////////////////////////////////////////////////////////////////////////////

template<typename T>
List<T>::BaseIterator::BaseIterator(Element* Temp) :Temp(Temp)
{
#ifdef DEBUG
	cout << "IConstructor:\t" << this << endl;
#endif // DEBUG

}
template<typename T>
List<T>::BaseIterator::~BaseIterator()
{
#ifdef DEBUG
	cout << "IDestructor:\t" << this << endl;
#endif // DEBUG

}
template<typename T>
bool List<T>::BaseIterator::operator==(const BaseIterator& other)const
{
	return this->Temp == other.Temp;
}
template<typename T>
bool List<T>::BaseIterator::operator!=(const BaseIterator& other)const
{
	return this->Temp != other.Temp;
}
template<typename T>
const int& List<T>::BaseIterator::operator*()const
{
	return Temp->Data;
}
///////////////////////////////////////////////////////////////////////////
template<typename T>
List<T>::ConstIterator::ConstIterator(Element* Temp) :BaseIterator(Temp)
{
#ifdef DEBUG
	cout << "IConstructor:\t" << this << endl;
#endif // DEBUG
}
template<typename T>
List<T>::ConstIterator::~ConstIterator()
{
#ifdef DEBUG
	cout << "IDestructor:\t" << this << endl;
#endif // DEBUG

}
template<typename T>
typename List<T>::ConstIterator& List<T>::ConstIterator::operator++()
{
	BaseIterator::Temp = BaseIterator::Temp->pNext;
	return *this;
}
template<typename T>
typename List<T>::ConstIterator List<T>::ConstIterator::operator++(int)
{
	ConstIterator old = *this;
	BaseIterator::Temp = BaseIterator::Temp->pNext;
	return old;
}
template<typename T>
typename List<T>::ConstIterator& List<T>::ConstIterator::operator--()
{
	BaseIterator::Temp = BaseIterator::Temp->pPrev;
	return *this;
}
template<typename T>
typename List<T>::ConstIterator List<T>::ConstIterator::operator--(int)
{
	ConstIterator old = *this;
	BaseIterator::Temp = BaseIterator::Temp->pPrev;
	return old;
}
///////////////////////////////////////////////////////////////////////////
template<typename T>
List<T>::Iterator::Iterator(Element* Temp) :ConstIterator(Temp)
{

}
template<typename T>
List<T>::Iterator::~Iterator()
{

}
template<typename T>
T& List<T>::Iterator::operator*()
{
	return BaseIterator::Temp->Data;
}
///////////////////////////////////////////////////////////////////////////
template<typename T>
List<T>::ConstReverseIterator::ConstReverseIterator(Element* Temp) :BaseIterator(Temp)
{
#ifdef DEBUG
	cout << "RItConstructor:\t" << this << endl;
#endif // DEBUG
}
template<typename T>
List<T>::ConstReverseIterator::~ConstReverseIterator()
{
#ifdef DEBUG

	cout << "RItDestructor:\t" << this << endl;
#endif // DEBUG
}
template<typename T>
typename List<T>::ConstReverseIterator& List<T>::ConstReverseIterator::operator++()
{
	BaseIterator::Temp = BaseIterator::Temp->pPrev;
	return *this;
}
template<typename T>
typename List<T>::ConstReverseIterator List<T>::ConstReverseIterator::operator++(int)
{
	ConstReverseIterator old = *this;
	BaseIterator::Temp = BaseIterator::Temp->pPrev;
	return old;
}
template<typename T>
typename List<T>::ConstReverseIterator& List<T>::ConstReverseIterator::operator--()
{
	BaseIterator::Temp = BaseIterator::Temp->pNext;
	return *this;
}
template<typename T>
typename List<T>::ConstReverseIterator List<T>::ConstReverseIterator::operator--(int)
{
	ConstReverseIterator old = *this;
	BaseIterator::Temp = BaseIterator::Temp->pNext;
	return old;
}
////////////////////////////////////////////////////////////////////////////
template<typename T>
List<T>::ReverseIterator::ReverseIterator(Element* Temp) :ConstReverseIterator(Temp) {}
template<typename T>
List<T>::ReverseIterator::~ReverseIterator() {}
template<typename T>
T& List<T>::ReverseIterator::operator*()
{
	return BaseIterator::Temp->Data;
}
///////////////////////////////////////////////////////////////////////////

template<typename T>
void print_list(const List<T>& list)
{
	for (typename List<T>::ConstIterator it = list.cbegin(); it != list.cend(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
}
template<typename T>
void reverse_print_list(const List<T>& list)
{
	for (typename List<T>::ConstReverseIterator rit = list.crbegin(); rit != list.crend(); ++rit)
	{
		cout << *rit << tab;
	}
	cout << endl;
}
//#define BASE_CHECK

template <typename T>
typename List<T>::Iterator List<T>::begin()
{
	return Head;
}
template <typename T>
typename List<T>::Iterator List<T>::end()
{
	return nullptr;
}
template <typename T>
typename List<T>::ConstIterator List<T>::cbegin()const
{
	return Head;
}
template <typename T>
typename List<T>::ConstIterator List<T>::cend()const
{
	return nullptr;
}
template <typename T>
typename List<T>::ReverseIterator List<T>::rbegin()
{
	return Tail;
}
template <typename T>
typename List<T>::ReverseIterator List<T>::rend()
{
	return nullptr;
}
template <typename T>
typename List<T>::ConstReverseIterator List<T>::crbegin()const
{
	return Tail;
}
template <typename T>
typename List<T>::ConstReverseIterator List<T>::crend()const
{
	return nullptr;
}
template <typename T>
List<T>::List()
{
	Head = Tail = nullptr;// ???? ?????? ????
	size = 0;
	cout << "LConstructor:\t" << this << endl;
}
template <typename T>
List<T>::List(const std::initializer_list<T>& il) :List()
{
	cout << typeid(il.begin()).name() << endl;
	for (int const* it = il.begin(); it != il.end(); it++)
	{
		push_back(*it);
	}
}
template <typename T>
List<T>::List(const List<T>& other) :List()
{
	/*for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)this->push_back(Temp->Data);
	*/
	*this = other;// ?? ???????????? ??????????? ???????? ???????? ????????????
	cout << "LCopyConstructor:\t" << this << endl;
}
template <typename T>
List<T>::~List()
{
	while (Head)pop_front();
	cout << "LDestructor:\t" << this << endl;
	cout << "\n--------------------------------------\n";
}
//Operators:
template <typename T>
List<T>& List<T>::operator=(const List<T>& other)
{
	if (this == &other)return *this;
	while (Head)pop_front();
	for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)this->push_back(Temp->Data);
	cout << "LCopyAssignment:\t" << this << endl;
	return *this;
}
// Adding elements:
template <typename T>
void List<T>::push_front(T Data)
{
	if (Head == nullptr && Tail == nullptr)
	{
		//????? ? ?????? ?????????? ?????? ???????
		//?? ???????????? ???????? ? ??????? ? ???????
		Head = Tail = new Element(Data);
		return;
	}
	Head = Head->pPrev = new Element(Data, Head);
	size++;
}
template <typename T>
void List<T>::push_back(T Data)
{
	if (Head == nullptr && Tail == nullptr)return push_front(Data);
	Tail = Tail->pNext = new Element(Data, nullptr, Tail);
	size++;
}
template <typename T>
void List<T>::insert(T Data, int Index)
{
	if (Index > size) {
		cout << "Error: ????? ?? ??????? ??????!" << endl;
		return;
	}
	Element* Temp;
	if (Index < size / 2)
	{
		Temp = Head;
		for (int i = 0; i < Index; i++) Temp = Temp->pNext;
	}
	else
	{
		Temp = Tail;
		for (int i = 0; i < size - Index - 1; i++) Temp = Temp->pPrev;

	}
	Element* New = new Element(Data);
	New->pNext = Temp;
	New->pPrev = Temp->pPrev;
	Temp->pPrev->pNext = New;
	Temp->pPrev = New;
	size++;

}
// Removing elements:
template <typename T>
void List<T>::pop_front()
{
	if (Head == nullptr && Tail == nullptr)return;
	if (Head == Tail)
	{
		delete Head;
		Head = Tail = nullptr;
		size--;
		return;
	}
	Head = Head->pNext;
	delete Head->pPrev;
	Head->pPrev = nullptr;
	size--;
}
template <typename T>
void List<T>::pop_back()
{
	if (Head == Tail)return pop_front();
	Tail = Tail->pPrev;
	delete Tail->pNext;
	Tail->pNext = nullptr;
	size--;
}
// Methods:
template <typename T>
void List<T>::print()const
{
	cout << "Head:\t" << Head << endl;
	for (Element* Temp = Head; Temp; Temp = Temp->pNext)
		cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
	cout << "Tail:\t" << Tail << endl;
	cout << " ?????????? ????????? ??????: " << size << endl;
}
template<typename T>
void List<T>::print_reverse()const
{
	cout << "Tail:\t" << Tail << endl;
	for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
		cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
	cout << "Head:\t" << Head << endl;
}