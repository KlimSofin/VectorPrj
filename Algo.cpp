#include"Vector.h"
#include<vector>
#include<iostream>

using std::vector;
using std::cout;
using std::endl;

void swap(int& a, int &b)
{
	int t = a;
	a = b;
	b = t;

}
void comparison(int& a, int& b)
{
	if (b < a)
		swap(a, b);
}
void output(int* ar, int n)
{
	for (int i = 0; i < n; i++)
		cout << ar[i] << " ";
}
void insertion_sort(int* ar, int l, int r) // Сортировка вставками N^2/4
{

	for (int i = r; i > l; i--)comparison(ar[i - 1], ar[i]);
	for (int i = l + 2; i <= r; i++)
	{
		int j = i;
		int it = ar[j];
		while (it < ar[j - 1])
		{
			ar[j] = ar[j - 1];
			j--;
		}
		ar[j] = it;
	}
}
void common_insertion_sort(int* ar, int l, int r)
{
	for (int i = l + 1; i <= r; i++)
	{
		for (int j = i; j > l; j--)
			comparison(ar[j - 1], ar[j]);
	}

}

void selection_sort(int* ar, int l, int r)
{
	for (int i = l; i < r; i++)
	{
		int min = i;
		for (int j = i + 1; j <= r; j++)
			if (ar[j] < ar[min])min = j;
		swap(ar[i], ar[min]);
	}
}

void bubble(int* ar, int l, int r)
{
	for (int i = l; i < r; i++)
	{
		for (int j = r; j > i; j--)
			comparison(ar[j - 1], ar[j]);
	}


}