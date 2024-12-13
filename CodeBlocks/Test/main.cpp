#include <iostream>

using namespace std;

int a[1000];
int n;
int target;

bool Search(int a[], int n, int target)
{
    int start = 0;
    int end = n - 1;

    int mid = n / 2;

    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (target == a[mid])
        {
            return true;
        }
        else if (target < a[mid])
        {
            end = mid - 1;
        }
        else if (target > a[mid])
        {
            start = mid + 1;
        }
    }

    return false;
}

int main()
{
    cin >> n >> target;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j + 1 < n - i; j++)
    //     {
    //         if (a[j] > a[j + 1])
    //         {
    //             int temp = a[j];
    //             a[j] = a[j + 1];
    //             a[j + 1] = temp;
    //         }
    //     }
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << a[i] << ' ';
    // }

    cout << Search(a, n, target);
}


