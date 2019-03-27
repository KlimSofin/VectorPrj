#include"Vector.h"
#include<iostream>
#include<vector>
using namespace std;

void output(int* ar, int n);
void insertion_sort(int* ar, int l, int r);
void selection_sort(int* ar, int l, int r);
void common_insertion_sort(int* ar, int l, int r);
void bubble(int* ar, int l, int r);

int main()
{
	/*const int N = 10;
	int mass[N] = { 9,8,7,6,5,4,3,2,1,0 };
	insertion_sort(mass, 0, N - 1);
	output(mass,N);*/
	Vector_1 one(-1);
	Vector_2 two(-4, 2);
	Vector_3 three(-5, -8, 9);
	VectorList list;
	list.add(&one);
	list.add(&two);
	list.add(&three);
	list.print();
}