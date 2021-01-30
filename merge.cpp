#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
	int n1 = m - l + 1, n2 = r - m;
	int L[n1], R[n2];

	for (int i = 0; i < n1; i++)
	{
		L[i] = arr[i + l];
	}
	for (int i = 0; i < n2; i++)
	{
		R[i] = arr[i + m + 1];
	}

	int i = 0, j = 0, k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] < R[j])
		{
			arr[k++] = L[i++];
		}
		else
		{
			arr[k++] = R[j++];
		}
	}
	while (i < n1)
	{
		arr[k++] = L[i++];
	}
	while (j < n2)
	{
		arr[k++] = R[j++];
	}
}

void sort(int arr[], int l, int r)
{
	if (l < r)
	{
		int mid = (l + r) / 2;
		sort(arr, l, mid);
		sort(arr, mid + 1, r);
		merge(arr, l, mid, r);
	}
}

void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
}

int main()
{
	int arr[] = {9, 7, 4, 8, 1, 0, 2, 3, 6, 5};
	int n = sizeof(arr) / sizeof(arr[0]);

	sort(arr, 0, n - 1);
	print(arr, n);

	return 0;
}