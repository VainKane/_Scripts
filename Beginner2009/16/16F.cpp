#include <bits/stdc++.h>

using namespace std;

#define bit(i, x) (((x) >> (i)) & 1)

int const N = 1e6;
int const maxLog = 20;

struct Node
{
    char ch;
    int depth = 0;
};

Node node[N];

int pos[N];
int par[N];
int up[N][maxLog];
int cnt = 0;
int ind = 0;
int cntP = 0;

int n;

void Type(char &ch)
{
    pos[ind] = ind;
    node[pos[ind]].ch = ch;
    par[ind] = pos[ind - 1];
    node[ind].depth = node[par[ind]].depth + 1;

    up[ind][0] = par[ind];
    for (int v = 1; (1 << v) <= n; v++)
    {
        up[ind][v] = up[up[ind][v - 1]][v - 1];
    }
}

void Undo(char &k)
{
    k -= '0';
    pos[ind] = pos[ind - 1 - k];
}

char Get(char x, int ind)
{
    ind = pos[ind];

    int u = node[ind].depth;
    int k = node[ind].depth - (x - '0') - 1;

    for (int i = 0; i <= maxLog; i++)
    {
        if (bit(i, k))
        {
            ind = up[ind][i];
        }
    }

    return node[ind].ch;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char type, x;
        cin >> type >> x;

        up[i][0] = par[i];

        ind++;

        if (type == 'T') Type(x);
        else if (type == 'U') Undo(x);
        else
        {
            ind--;
            cntP++;
            cout << Get(x, i - cntP) << '\n';
        }
        
    }

    // for (int i = 1; i <= n; i++) 
    // {
    //     cout << i << ' ' << pos[i] << '\n';
    // }

    return 0;
}