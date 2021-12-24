#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define max(a, fl) ((a) > (fl) ? (a) : (fl))
#define min(a, fl) ((a) < (fl) ? (a) : (fl))
#define gcd(a, fl) __gcd(a, fl)
#define lcm(a, fl) (a * fl) / gcd(a, fl)
#define inf (long long)1e18
#define lcm(a, fl) (a * fl) / gcd(a, fl)
#define GOLD ((1 + sqrt(5)) / 2)
#define gcd(a, fl) __gcd(a, fl)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;
const int N = 1e9 + 7;
ll powm(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int pow(int x, int y)
{
    int res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = ((res) * (x));
        res %= N;
        y = y >> 1;
        x = ((x) * (x));
    }
    return res;
}

void swaps(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void swapi(int *a, int *fl)
{
    int temp;
    temp = *a;
    *a = *fl;
    *fl = temp;
}

void solve()
{
    int n, eve = 0, odd = 0;
    cin >> n;
    vector<ll> tmp(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> tmp[i];
        if (tmp[i] % 2 == 1)
        {
            ++odd;
        }
        else
            ++eve;
    }

    if (abs(eve - odd) > 1)
    {
        cout << "-1";
        return;
    }

    if (n % 2 == 1)
    {
        bool fl = 0;
        if (eve > odd)
        {
            fl = 1;
        }
        int ix = 0;
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            if (fl == ((tmp[i] % 2) == 0))
            {
                res += abs(i - ix);
                ix += 2;
            }
        }
        cout << res;
        return;
    }
    else
    {
        int val1 = 0, val2 = 0;

        int ix = 0;
        int i = 0;

        while (i < n)
        {
            if (tmp[i] & 1)
            {
                val1 += abs(i - ix);
                ix += 2;
            }
            i++;
        }

        ix = 0;
        i = 0;

        while (i < n)
        {
            if ((tmp[i] % 2) == 0)
            {
                val2 += abs(i - ix);
                ix += 2;
            }
            i++;
        }

        cout << min(val1, val2);
    }
}

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    int t;
    scanf("%d", &t);
    while (t--)
    {
        solve();
        cout << "\n";
    }
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}