#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <ctype.h>
#include  <math.h>
#include <limits>
using namespace std;

void printArray(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << " -- " << a[i] << "-- " << endl;
	}
}

void swap(int* x, int*y)
{
	*x ^= *y;
	*y ^= *x;
	*x ^= *y;
}

void sort(int a[], int size)
{
	bool bswapped;
	for (int i = 0; i < size; i++)
	{
		bswapped = false;
		for (int j = 0; j < (size - i - 1); j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(&a[j], &a[j + 1]);
					bswapped = true;
			}
		}

		if (bswapped == false)
			break;
	}
}
void merge(int a[], int b[], int a_size, int b_size)
{	
	int* m = new int[a_size + b_size];
	memset(m, 0, a_size + b_size);

	int i = 0, j = 0, k = 0;	
	while (true)
	{
		if (i < a_size)
		{
			m[k++] = a[i++];
		}
		else 
		{
			if (j < b_size)			
			{
				m[k++] = b[j++];
			}
			else if (j >= b_size)
			{
				break;
			}
		}
	}

	sort(m, k);

	i = j = 0;
	for (i = 0; i < k - 1; i++)
		if (m[i] != m[i + 1])
			m[j++] = m[i];

	m[j++] = m[k - 1];

	printArray(m, j);

}


int main()
{
	
	int a[] = { 1, 2, 3, 4 };
	int b[] = { 5, 4, 7, 3, 9 };


	merge(a, b, 4, 5);

	cin.get();
}
