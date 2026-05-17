#include<iostream>
using namespace std;

int max(int arr[], int size)
{
	if (size == 1)
	{
		return arr[0];
	}
	if (arr[size - 1] >= max(arr, size - 1))
	{
		return arr[size - 1];
	}
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
	cout << "Maximum of array :" << max(arr, size) << endl;
	
	delete[]arr;

	return 0;
}