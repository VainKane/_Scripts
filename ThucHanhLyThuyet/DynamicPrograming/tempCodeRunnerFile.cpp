for (int i = 1; i < n; i++)
    {
        int x = Search(l, nums[i], 0, i - 1);
        cout << '\n' << x << '\n';
        // l[i] = l[x] + 1;

        // if (res < l[i])
        // {
        //     res = l[i];
        // }
    }

    cout << res;