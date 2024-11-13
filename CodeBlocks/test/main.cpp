#include <bits/stdc++.h>

std::string n;
int nums[6];

int main()
{
    std::cin >> n;

    for (int i = 0; i < n.length(); i++)
    {
        nums[i] = (int)n[i] - (int)'0'; // lay so dau tien cua n

        for(int j = i + 1; j < n.length(); j++) // lay cac chu so sau i
        {
            nums[i] *= 10;
            nums[i] += (int)n[j] - (int)'0';
        }

        for (int j = 0; j < i; j++) // lay cac chu so truoc i
        {
            nums[i] *= 10;
            nums[i] += (int)n[j] - (int)'0';
        }
    }

    for (int item : nums)
    {
        std::cout << item << '\n';
    }


}


