#include <bits/stdc++.h>
using namespace std;

void sort(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int t = arr[i];
		int j = i - 1;
		while (j >= 0 && t < arr[j])
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = t;
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