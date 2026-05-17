#include <iostream>
using namespace std;

int maxNo(int arr[], int n, int i, int maxIdx)
{
    if (i == n)
    {
        return maxIdx;
    }
    if (arr[i] != -1 && (maxIdx == -1 || arr[i] > arr[maxIdx]))
    {
        maxIdx = i;
    }
    return maxNo(arr, n, i + 1, maxIdx);
}
bool sum(int arr[], int n, int i, int target)
{
    if (target == 0)
    {
        return true;
    }
    if (i == n)
    {
        return false;
    }
    if (arr[i] != -1 && arr[i] <= target)
    {
        if (sum(arr, n, i + 1, target - arr[i]))
        {
            return true;
        }
    }
    return sum(arr, n, i + 1, target);
}
int magicNo(int arr[], int n, int remaining)
{
    if (remaining == 0)
    {
        return -1;
    }
    int idx = maxNo(arr, n, 0, -1);
    if (idx == -1)
    {
        return -1;
    }
    int value = arr[idx];
    arr[idx] = -1;
    if (sum(arr, n, 0, value))
    {
        return value;
    }
    return magicNo(arr, n, remaining - 1);
}

int main()
{
    int n;
    cout << "Enter Size:";
    cin >> n;
    int *arr=new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter no: ";
        cin >> arr[i];
    }
    cout<<"Magic No :"<< magicNo(arr, n, n);
    delete[] arr;

    return 0;
}