#include<iostream>
#include"Vector.h"

VectorList::~VectorList()
{
	link tmp = head;
	while (tmp != nullptr)
	{
		tmp = tmp->next;
		delete head;
		head = tmp;
	}
}

void VectorList::add(Vector_1*vc)
{
	link tmp = current;
	current = new node(vc, nullptr);
	if (head == nullptr)
		head = current;
	else
		tmp->next = current;
}

void VectorList::print()
{
	link tmp = head;
	while (tmp != nullptr)
	{
		std::cout << tmp->vec->length() << std::endl;
		tmp = tmp->next;
	}
}

