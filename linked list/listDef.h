#ifndef listDef_h
#define listDef_h

#include "list.h"
#include <iostream>
#include "node.h"

using std::cout;
using std::endl;

template <class T>
List<T>::List() {
	dummyHead = new Node<T>(T(), NULL);
}

template <class T>
List<T>::List(const List& rhs) {
	dummyHead = new Node<T>(T(), NULL);
	*this = rhs;
}

template <class T>
List<T>::~List() {
	makeEmpty();
	delete dummyHead;
}

template<class T>
List<T>& List<T>::operator=(const List<T>& rhs) {
	if (this != &rhs) {
		makeEmpty();
		const Node<T>* r = rhs.first();
		Node<T>* p = zeroth();

		while (r) {
			insert(r->element, p);
			r = r->next;
			p = p->next;
		}
	}
	return *this;
}

template <class T>
bool List<T>::isEmpty() {
	return first() == NULL;
}

template <class T>
bool List<T>::isEmpty() const {
	first() == NULL;
}

template <class T>
Node<T>* List<T>::first() {
	return dummyHead->next;
}

template <class T>
Node<T>* List<T>::zeroth() {
	return dummyHead;
}

template <class T>
Node<T>* List<T>::find(const T& data) {
	Node<T>* p = first();

	while (p) {
		if (p->element == data)
			return p;
		p = p->next;
	}
	return NULL;
}

template <class T>
Node<T>* List<T>::findPrevious(const T& data) {
	Node<T>* p = zeroth();

	while (p->next) {
		if (p->next->element == data)
			return p;
		p = p->next;
	}
	return NULL;
}

template <class T>
void List<T>::remove(const T& data) {
	Node<T>* p = findPrevious(data);

	if (p) {
		Node<T>* tmp = p->next;
		p->next = tmp->next;
		delete tmp;
	}
}

template <class T>
void List<T>::print() const {
	const Node<T>* p = first();

	while (p) {
		cout << p->element << endl;
		p = p->next;
	}
}

template <class T>
void List<T>::makeEmpty() {
	while (!isEmpty()) {
		remove(first()->element);
	}
}

template <class T>
void List<T>::insert(const T& data, Node<T>* p) {
	Node<T>* newNode = new Node<T>(data, p->next);
	p->next = newNode;
}

template <class T>
Node<T>* List<T>::first() const {
	return dummyHead->next;
}

template <class T>
void List<T>::reverse() {
	Node<T>* current = first();
	Node<T>* previous = NULL;
	Node<T>* next = NULL;

	while (current != NULL) {
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	dummyHead->next = previous;
}

template <class T>
int List<T>::countElements() {
	int counter = 0;

	Node<T>* current = first();
	while (current != NULL) {
		counter++;
		current = current->next;
	}
	return counter;
}

template <class T>
void List<T>::printOdd() {
	Node<T>* current = first();
	while (current) {
		if (current->element % 2 != 0)
			cout << current->element << endl;
		current = current->next;
	}
}

template <class T>
void List<T>::printEven() {
	Node<T>* current = first();
	while (current) {
		if (current->element % 2 == 0)
			cout << current->element << endl;
		current = current->next;
	}
}

template <class T>
void List<T>::merge(List<T> L2) {
	Node<T>* p = first();
	while (p) {
		insert(L2.first()->element, p);
		L2.remove(L2.first()->element);
		p = p->next->next;
	}
}

template <class T>
void List<T>::Split(List<T> L1, List<T> L2) {
	Node<T>* p = first(), * A = L1.zeroth(), * B = L2.zeroth();
	while (p) {
		L1.insert(p->element, A);
		A = A->next;
		p = p->next;
		if (p) {
			L2.insert(p->element, B);
			B = B->next;
		}
	}
}

#endif
