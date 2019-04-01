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
void shell_sort(int* ar, int l, int r)
{

	int h;
	for (h = 1; h <= (r - l) / 9; h = 3 * h + 1);
	for (; h > 0; h /= 3)
	{
		cout << h << endl;
		for (int i = l + h; i <= r; i++)
		{
			int j = i;
			int v = ar[i];
			while ((j >= l + h) && (v < ar[j - h]))
			{
				ar[j] = ar[j - h];
				j -= h;
			}
			ar[j] = v;
			output(ar, 10);
			cout << " i " << i << endl;
		}
	}
}
int partition(int* ar, int l, int r)
{
	int i = l - 1, j = r;
	int v = ar[r];
	for (;;)
	{
		while (ar[++i] < v);
		while (v < ar[--j])
		{
			if (j == 1)
				break;
		}
		if (i >= j) break;
		swap(ar[i], ar[j]);
	}
	swap(ar[i], ar[r]);
	return i;
}
void quick_sort(int* ar, int l, int r)
{
	if (r <= l) return;
	int k = partition(ar, l, r);
	quick_sort(ar, l, k - 1);
	quick_sort(ar, k + 1, r);
}
inline void push2(STACK<int> &s, int A, int B)
{
	s.push(B);
	s.push(A);
}

void modr_quick_sort(int* ar, int l, int r)
{
	STACK<int> s(50);
	push2(s, l, r);
	while (!s.empty())
	{
		l = s.pop();
		r = s.pop();
		if (r <= l)continue;
		int i = partition(ar, l, r);
		if (i - 1 > r - i)
		{
			push2(s, l, i - 1);
			push2(s, i + 1, r);
		}
		else
		{
			push2(s, i + 1, r);
			push2(s, l, i - 1);
		}
	}
}
