#include <iostream>
#include<string>
using namespace std;

template <typename T>
void printArray(T arr[],int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

template <typename T>
void selectionSort(T arr[], int size) {
	for (int i = 0; i < size-1; i++) {
		int smallN0 = i;
		for (int j = i+1; j < size; j++) {
			if (arr[j] < arr[smallN0]) {
				smallN0 = j;
			}
		
		}
		T temp = arr[i];
		arr[i] = arr[smallN0];
		arr[smallN0] = temp;
	}
}

int main() {

	int intArray[5] = {7, 5, 9, 2, 4}; cout << "Original integer array: "; 
	printArray(intArray,5); 
	selectionSort(intArray,5);
	cout << "Sorted integer array: "; printArray(intArray,5);

	string stringArray[4] = { "apple", "banana", "banana", "grape" }; 
	cout << "\nOriginal string array: ";
	printArray(stringArray, 4);

	selectionSort(stringArray, 4);
	cout << "Sorted string array: "; 
	printArray(stringArray,4);

	return 0;
}
