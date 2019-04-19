#ifndef VECTOR_H_
#define VECTOR_H_

#include<cmath>
#include <iostream>
void swap(int& a, int &b);

template<typename Item>
void fixUp(Item a[], int k)
{
	while (k > 1 && a[k / 2] < a[k])
	{
		swap(a[k], a[k / 2]);
		k = k / 2;
	}
}

template<typename Item>
void fixDown(Item a[], int k, int N)
{
	while (2 * k <= N)
	{
		int j = 2 * k;
		if (j < N&&a[j] < a[j + 1]) j++;
		if (!(a[k] < a[j])) break;
		swap(a[k], a[j]);
		k = j;
	}
}

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

template<typename Item>
class PriorQue
{
private:
	Item *pq;
	int N;
public:
	PriorQue(int MaxN)
	{
		pq = new Item[MaxN + 1];
		N = 0;
	}
	bool empty()const
	{
		return N == 0;
	}
	void insert(Item item)
	{
		pq[++N] = item; fixUp(pq, N);
	}
	Item getmax()
	{
		swap(pq[1], pq[N]);
		fixDown(pq, 1, N - 1);
		return pq[N--];
	}
};

#endif // !VECTOR_H_
