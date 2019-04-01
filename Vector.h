#ifndef VECTOR_H_
#define VECTOR_H_
#include<cmath>
#include <iostream>

class Vector_1
{
private:
	double x;
public:
	Vector_1(double cx = 0.0) :x(cx) { std::cout << "Create Vec1\n"; }
	virtual double length() { return ((x < 0) ? -x : x); }
	virtual ~Vector_1() {}
};

class Vector_2 :public Vector_1
{
private:
	double y;
public:
	Vector_2(double cx = 0.0, double cy = 0.0) :Vector_1(cx), y(cy) { std::cout << "Create Vec2\n"; }
	virtual double length() { return sqrt(Vector_1::length()*Vector_1::length() + y * y); }
	~Vector_2() {}
};

class Vector_3 : public Vector_2
{
private:
	double z;
public:
	Vector_3(double cx = 0.0, double cy = 0.0, double cz = 0.0) :Vector_2(cx, cy), z(cz) { std::cout << "Create Vec3\n"; }
	double length() { return sqrt(Vector_2::length()*Vector_2::length() + z * z); }
	~Vector_3() {}
};


class VectorList
{
private:

	struct node
	{
		node* next;
		Vector_1* vec;
		node() {}
		node(Vector_1* vc, node* lin) :vec(vc), next(lin) {}
	};
	typedef node* link;
	link head = nullptr;
	link last = nullptr;
public:
	VectorList() {}
	void add(Vector_1*vc);
	void Delete(int size);
	void print();
	~VectorList();

};


template<class Item>
class STACK
{
private:
	Item* item;
	int N;
public:
	STACK(int);
	bool empty() const;
	void push(int citem);
	Item pop();
};

template<class Item>
STACK< Item>::STACK(int n)
{
	item = new Item[n];
	N = 0;
}

template<class Item>
bool STACK< Item>::empty() const
{
	return N == 0;
}

template<class Item>
void STACK< Item>::push(int citem)
{
	item[N++] = citem;
}

template<class Item>
Item STACK<Item>::pop()
{

	return item[--N];
}
#endif // !VECTOR_H_
