#include <iostream>
using namespace std;

bool isPalindrome(char str[], int left, int right)
{
    if (left >= right)
    {
        return true;
    }
    if (str[left] != str[right])
    {
        return false;
    }
    return isPalindrome(str, left + 1, right - 1);
}
int main()
{
    char str[100];
    cout << "Enter string:";
    cin >> str;
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    if (isPalindrome(str, 0, len - 1))
    {
        cout << "Palindrome";
    }
    else
    {
        cout << "Not Palindrome";
    }

    return 0;
}