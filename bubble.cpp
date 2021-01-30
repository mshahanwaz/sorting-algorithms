#include <bits/stdc++.h>
using namespace std;

void sort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
				swap(arr[i], arr[j]);
		}
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

	sort(arr, n);
	print(arr, n);

	return 0;
}