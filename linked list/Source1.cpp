#include <iostream>
#include "list.h"
#include "listDef.h"
#include "node.h"
using std::cout;
using std::endl;

int main() {
	List<int> list;
	list.insert(0, list.zeroth());
	Node<int>* p = list.first();
	
	for (int i = 1; i <= 10; ++i)
	{
		list.insert(i, p);
		p = p->next;
	}

	cout << "Printing original list" << endl;
	list.print();

	cout << "The size of this list is: " << list.countElements() << endl;;
	
	List<int> testList = list;
	testList.reverse();
	cout << "Printing reversed list: " << endl;
	testList.print();
	
	//function remove
	for (int i = 0; i <= 10; ++i)
	{
		if (i % 2 == 0)
			list.remove(i);
	}

	cout << "Printing odd number list" << endl;
	list.print();

	List<int> list2 = list;
	cout << "Printing copy constructed list" << endl;
	list2.print();

	List<int> list3;
	list3 = list;
	cout << "Printing assigned list" << endl;
	list3.print();

	list.makeEmpty();
	cout << "Printing emptied list" << endl;
	list.print();

	//function find
	for (int i = 0; i <= 10; ++i) {
		if (i % 2 == 0) {
			if (list2.find(i) == NULL)
				cout << "Could not find element " << i << endl;
		}
		else {
			if (list2.find(i) != NULL)
				cout << "Found element " << i << endl;
		}
	}

	cout << "Printing odd elements: " << endl;
	testList.printOdd();
	
	cout << "Printing even elements: " << endl;
	testList.printEven();

	testList.merge(list);
	cout << "printing merged list: " << endl;
	testList.print();
	testList.print();
}