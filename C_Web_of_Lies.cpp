#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define inf (long long)1e18
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define gcd(a, b) __gcd(a, b)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;
const int N = 1e9 + 7;
ll powm(ll u, ll y, ll p)
{
    ll res = 1;
    u = u % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * u) % p;
        y = y >> 1;
        u = (u * u) % p;
    }
    return res;
}

int pow(int u, int y)
{
    int res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = ((res) * (u));
        res %= N;
        y = y >> 1;
        u = ((u) * (u));
    }
    return res;
}

void swaps(char *u, char *y)
{
    char temp;
    temp = *u;
    *u = *y;
    *y = temp;
}

void swapi(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void solve()
{
    int n, m, val1, t2, query, u;
    cin >> n;
    cin >> m;

    set<int> res;

    for (int i = 1; i < n + 1; ++i)
    {
        res.insert(i);
    }

    //for (int i = m; i >= 0; i--)
    vector<set<int, greater<int>>> tmp(n + 1);
    int k = m;
    while (k > 0)
    {
        cin >> val1 >> t2;
        tmp[val1].insert(t2);
        tmp[t2].insert(val1);
        if (tmp[val1].size() && *(tmp[val1].begin()) > val1)
        {
            if (res.count(val1))
                res.erase(val1);
        }

        if (tmp[t2].size() && *(tmp[t2].begin()) > t2)
        {
            if (res.count(t2))
                res.erase(t2);
        }
        k--;
    }

    cin >> query;
    while (query--)
    {
        cin >> u;
        if (u == 1)
        {
            cin >> val1;
            cin >> t2;
            tmp[val1].insert(t2);
            tmp[t2].insert(val1);
            if (tmp[val1].size() && *(tmp[val1].begin()))
            {
                if (res.count(val1))
                    res.erase(val1);
            }

            if (tmp[t2].size() && *(tmp[t2].begin()) > t2)
            {
                if (res.count(t2))
                    res.erase(t2);
            }
        }
        else if (u == 2)
        {
            cin >> val1;
            cin >> t2;
            tmp[val1].erase(t2);
            tmp[t2].erase(val1);
            if (tmp[val1].empty() || *(tmp[val1].begin()) < val1)
            {
                res.insert(val1);
            }

            if (tmp[t2].empty() || *(tmp[t2].begin()) < t2)
            {
                res.insert(t2);
            }
        }
        else
        {
            cout << res.size() << endl;
        }
    }
}

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    // int t;
    // scanf("%d", &t);
    // while (t--)
    // {
    solve();
    //     cout << "\n";
    // }
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}