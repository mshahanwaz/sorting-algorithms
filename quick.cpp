#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

int partition(int arr[], int l, int r)
{
	int pivot = arr[r];
	int pindex = l - 1;

	for (int j = l; j < r; j++)
	{
		if (arr[j] < pivot)
		{
			pindex++;
			swap(arr[pindex], arr[j]);
		}
	}
	swap(arr[pindex + 1], arr[r]);
	return (pindex + 1);
}

void sort(int arr[], int l, int r)
{
	if (l < r)
	{
		int pivot = partition(arr, l, r);
		sort(arr, l, pivot - 1);
		sort(arr, pivot + 1, r);
	}
}

int main()
{
	srand(time(0));
	int n = 10000;
	int arr[n];

	// Best-case
	for (int i = 0; i < n; i++)
		arr[i] = int(rand() % 10000000);
	auto start = high_resolution_clock::now();
	sort(arr, 0, n - 1);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Best-case  \t:\t" << float(duration.count() / 1000000.0) << " sec" << endl;

	// Average-case
	for (int i = 0; i < n; i++)
	{
		if (i < n / 2)
			arr[i] = i;
		else
			arr[i] = 3 * n / 2 - i;
	}
	start = high_resolution_clock::now();
	sort(arr, 0, n - 1);
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Average-case \t:\t" << float(duration.count() / 1000000.0) << " sec" << endl;

	// Worst-case
	for(int i=0; i<n; i++) arr[i] = i;
	start = high_resolution_clock::now();
	sort(arr, 0, n - 1);
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop-start);
	cout << "Worst-case \t:\t" << float(duration.count()/1000000.0) << " sec" << endl;

	return 0;
}
