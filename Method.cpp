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
void VectorList::Delete(int size)
{
	if (size <= 0)
	{
		std::cout << "Wrong input\n";
		return;
	}
	if (head == nullptr)
	{
		std::cout << "List is clear\n";
		return;
	}
	link pre_del = head;
	link del = head;
	if (size == 1)
	{
		head = head->next;
		delete del;
		return;
	}
	int count = 0;
	while (count != size - 1)
	{
		pre_del = del;
		del = del->next;
		count++;
	}
	pre_del->next = pre_del->next->next;
	delete del;

}

void VectorList::add(Vector_1*vc)
{
	link tmp = last;
	last = new node(vc, nullptr);
	if (head == nullptr)
		head = last;
	else
		tmp->next = last;
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

//STACK


