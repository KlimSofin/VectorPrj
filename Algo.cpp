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
void lip(int *ar, int size)
{
	int* d = new int[size];
	int* p = new int[size];
	for (int i = 0; i < size; ++i)
	{

		d[i] = 1;
		p[i] = -1;
		for (int k = 0; k <= i; k++)
			cout << d[k] << " ";
		cout << endl;
		for (int j = 0; j < i; ++j)
			if (ar[j] < ar[i])
			{
				d[i] = std::fmax(d[i], 1 + d[j]);

			}
	}
	int ans = d[0];
	for (int i = 0; i < size; i++)
		ans = fmax(ans, d[i]);
	cout << ans << endl;

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
	return;
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
	if (r - l <= 5) {
		insertion_sort(ar, l, r);
		return;
	}
	swap(ar[(l + r) / 2], ar[r - 1]);
	comparison(ar[l], ar[r - 1]);
	comparison(ar[l], ar[r]);
	comparison(ar[r - 1], ar[r]);
	int i = partition(ar, l, r);
	quick_sort(ar, l, i - 1);
	quick_sort(ar, i + 1, r);

}
void mergeAB(int* ar, int *br, int* cr, int N, int M)
{
	for (int i = 0, j = 0, k = 0; k < N + M; k++)
	{
		if (i == N)
		{
			cr[k] = br[j++];
			continue;
		}
		if (j == M)
		{
			cr[k] = ar[i++];
			continue;
		}
		cr[k] = (ar[i] < br[j])
	}
}
/*int rands(int *ar, int l, int r)
{
	int i = rand() % 10 + 0;
	swap(ar[r], ar[i]);
	return partition(ar, l, r);
}*/
/*void hybridsort(int* ar, int l, int r)
{

	quick_sort(ar, l, r);

	insertion_sort(ar, l, r);
}*/
/*inline void push2(STACK<int> &s, int A, int B)
{
	s.push(B);
	s.push(A);
}
void non_rec_quick_sort(int* ar, int l, int r)
{
	STACK<int> s(50);
	push2(s, l, r);
	while (!s.empty())
	{
		l = s.pop();
		r = s.pop();
		if (r <= l)continue;
		int i = partition(ar, l, r);
		if(i - 1 > r - i)
		{
			push2(s, l, i - 1);
			push2(s, i+1, r);
		}
		else
		{
			push2(s, i+1, r);
			push2(s, l, i - 1);
		}
	}
}*/


