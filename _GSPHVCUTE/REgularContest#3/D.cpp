#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define name "dimghinh"

struct Point
{
    double x, y;

    bool operator == (Point const other)
    {
        return (x == other.x && y == other.y);
    }
};

int n;
Point a[4], b[4];

long long Dist(Point A, Point B)
{
    double x = B.x - A.x;
    double y = B.y - A.y;    
    return sqrtl(x * x + y * y);
}

void Eql(Point A, Point B, double &a, double &b, double &c)
{
    a = A.y - B.y;
    b = B.x - A.x;
    c = -a * A.x - b * A.y;
}

Point InterPoint(Point A, Point B, Point C, Point D) 
{
    double a1, b1, c1;
    double a2, b2, c2;

    Eql(A, B, a1, b1, c1);
    Eql(C, D, a2, b2, c2);

    double tmp = b2 - a2 * b1;
    if (!tmp || !a1) return Point {0, 0};

    double y = (a2 * c1 - c2 * a1) / tmp;
    double x = (-c1 - b1 * y) / a1;

    bool check1 = x <= A.x;
    bool check2 = x <= B.x;
    bool check3 = y <= A.y;
    bool check4 = y <= B.y;

    if ((check1 ^ check2) == 0) return Point {0, 0};
    if ((check3 ^ check4) == 0) return Point {0, 0};

    return Point {x, y};
}

void InterRec()
{
    vector<Point> v;

    bool used1[4], used2[4];
    memset(used1, false, sizeof used1);
    memset(used2, false, sizeof used2);

    REP(i, 4) REP(j, 4)
    {
        Point I = InterPoint(a[i], a[(i + 1) % 4], b[j], b[(j + 1) % 4]);
        if (I == Point {0, 0}) continue;

        v.push_back(I);
        used1[i] = used2[j] = true;
        used1[(i + 1) % 4] = used2[(j + 1) % 4] = true;
    }

    if (v.size() == 2)
    {
        REP(k, 4)
        {
            if (!used1[k]) v.push_back(a[k]);
            if (!used2[k]) v.push_back(b[k]);
        }
    }

    if (v.size() != 4) 
    {
        cout << 0;
        exit(0);
    }

    REP(i, 4) b[i] = v[i];
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    FOR(i, 1, n)
    {
        if (i == 1) REP(j, 4) cin >> b[j].x >> b[j].y;
        else
        {
            REP(j, 4) cin >> a[j].x >> a[j].y;
            InterRec();
        }

        if (i == 2) REP(j, 4) cout << b[j].x << ' ' << b[j].y << '\n';
    }

    // REP(i, 4) cout << b[i].x << ' ' << b[i].y << '\n';
    cout << Dist(b[0], b[1]) * Dist(b[1], b[2]);

    return 0;
}