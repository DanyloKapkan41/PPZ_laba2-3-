#include <iostream>
using namespace std;
void filling(int*& nums, int i, int n, bool mode)
{
	if (mode) {
		if (i < n) {
			nums[i] = rand() % 20001 - 10000;
			i++;
			filling(nums, i, n, mode);
		}
	}
	else {
		if (i < n) {
			do { cin >> nums[i]; } while (nums[i] < -10000 || nums[i]>10000);
			cout << " writed...\n";
			i++;
			filling(nums, i, n, mode);
		}
	}
}
void extract(int* nums, int i, int n)
{
	if (i < n) {
		cout << nums[i] << ' ';
		i++;
		extract(nums, i, n);
	}
}
void sorting(int*& numb, int n)
{
	int i, j, k, x;
	for (i = 0; i < n; i++) {
		k = i;
		x = numb[i];
		for (j = i + 1; j < n; j++) {
			if (numb[j] < x) {
				k = j;
				x = numb[j];
			}
		}
		numb[k] = numb[i];
		numb[i] = x;
	}
}
void square(int*& numb, int n)
{
	for (int i = 0; i < n; i++)
	{
		numb[i] = pow(numb[i], 2);
	}
}
int main()
{
	int n, modeint;
	bool mode;
	do {
		cout << "Enter array size(1 - 10000): ";
		cin >> n;
	} while (n <= 0 || n >= 10000);
	int* nums = new int[n];
	srand(time(NULL));
	do {
		cout << "Choose mode (1 - autoentering, 0 - enterig by yourself): ";
		cin >> modeint;
	} while (modeint < 0 || modeint > 1);
	mode = modeint;
	filling(nums, 0, n, mode);
	sorting(nums, n);
	extract(nums, 0, n);
	cout << "\n";
	square(nums, n);
	sorting(nums, n);
	extract(nums, 0, n);
}