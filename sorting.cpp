#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r)
{
	int x = a[l];
	int j = l;
	for (int i = l + 1; i <= r; i++)
	{
		if (a[i] <= x)
		{
			j++;
			swap(a[i], a[j]);
		}
	}
	swap(a[l], a[j]);
	return j;
}

void partition3(vector<int> &a, int l, int r, int temp[])
{
	int x = a[l];
	temp[0] = l;
	temp[1] = l;

	for (int i = l + 1; i <= r; i++)
	{
		if (a[i] < x)
		{
			temp[0]++;
			temp[1]++;
			swap(a[temp[0]], a[temp[1]]);
			if (temp[1] != i)
			{
				swap(a[temp[0]], a[i]);
			}
		} else if (a[i] == x)
		{
			temp[1]++;
			swap(a[temp[1]], a[i]);
		}
	}
	swap(a[l], a[temp[0]]);
}

void randomized_quick_sort(vector<int> &a, int l, int r)
{
	if (l >= r)
	{
		return;
	}

	int k = l + rand() % (r - l + 1);
	swap(a[l], a[k]);
	int m[2] = { 0 };
	partition3(a, l, r, m);
	randomized_quick_sort(a, l, m[0] - 1);
	randomized_quick_sort(a, m[1] + 1, r);
}
void randomized_quick_sort2(vector<int> &a, int l, int r)
{
	if (l >= r)
	{
		return;
	}

	int k = l + rand() % (r - l + 1);
	swap(a[l], a[k]);
	int m = partition2(a, l, r);
	randomized_quick_sort2(a, l, m - 1);
	randomized_quick_sort2(a, m + 1, r);
}

int main()
{
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); ++i) {
		std::cin >> a[i];
	}
	randomized_quick_sort(a, 0, a.size() - 1);
	for (size_t i = 0; i < a.size(); ++i) {
		std::cout << a[i] << ' ';
	}

	// The following code is sample test used to perform the stress test to ensure the validity of the algorithm
	/*int n = 15;

	bool flag = true;
	while (flag)
	{
		vector<int> a(n);
		vector<int> b(n);
		vector<int> c(n);
		for (int i = 0; i < n; i++)
		{
			a[i] = rand() % 100 + 1;
			b[i] = a[i];
			c[i] = a[i];
			std::cout<<c[i]<<' ';
		}
		std::cout<<std::endl;
		randomized_quick_sort3(a, 0, a.size() - 1);
		randomized_quick_sort2(b, 0, b.size() - 1);
		for (int i = 0; i < n; i++)
		{
			if (a[i] != b[i])
			{
				std::cout << "Error " << std::endl;
				for (int j = 0; j < n; j++)
				{
					std::cout << c[j] << ' ';
				}
				std::cout << std::endl;
				for (int j = 0; j < n; j++)
				{
					std::cout << a[j] << ' ';
				}
				std::cout << std::endl;
				for (int j = 0; j < n; j++)
				{
					std::cout << b[j] << ' ';
				}
				std::cout << std::endl;
				flag = false;
				break;
			}
		}
	}*/

}
