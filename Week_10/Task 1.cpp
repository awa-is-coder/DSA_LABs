#include<iostream>
using namespace std;

int sum(int arr[], int size)
{
	if (size == 0)
	{
		return 0;
	}
	return arr[size - 1] + sum(arr, size - 1);
}
int main()
{
	int size;
	cout << "Enter size :";
	cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		cout << "Enter no :";
		cin >> arr[i];
	}
	cout << "\nSum of array :" << sum(arr, size) << endl;
	delete[]arr;

	return 0;
}