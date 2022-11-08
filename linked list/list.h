#ifndef list_h
#define list_h
#include <iostream>
#include "node.h"

template <class T>
class List {
private:
	Node<T>* dummyHead;

public:
	List();

	List(const List& rhs);

	~List();

	List& operator=(const List& rhs);

	bool isEmpty();

	bool isEmpty() const ;

	Node<T>* first();
	Node<T>* zeroth();

	Node<T>* find(const T& data);

	Node<T>* findPrevious(const T& data);

	void remove(const T& data);

	void print() const;

	void makeEmpty();

	void insert(const T& data, Node<T>* p);

	Node<T>* first() const;

	void reverse();

	int countElements();

	void printOdd();

	void printEven();

	void merge(List L2);

	void Split(List<T> L1, List<T> L2);
};

#endif