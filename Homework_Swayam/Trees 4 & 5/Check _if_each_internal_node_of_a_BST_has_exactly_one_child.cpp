#include <iostream>
using namespace std;
bool solve(int a[], int size)
{
    int firstDiff = 0;
    int lastDiff = 0;
    for (int i = 0; i < size - 1; i++)
    {
        firstDiff = a[i] - a[i + 1];
        lastDiff = a[i] - a[size - 1];
        if (firstDiff * lastDiff < 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int a[] = {20, 10, 11, 13, 12};
    int size = sizeof(a) / sizeof(a[0]);
    if (solve(a, size))
    {
        cout << "Valid" << endl;
    }
    else
    {
        cout << "Not valid" << endl;
    }
    return 0;
}