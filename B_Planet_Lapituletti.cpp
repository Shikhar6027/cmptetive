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

void swapi(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
boo isvalid(int i)
{
    if (i == 1 || i == 2 || i == 5 || i == 8)
    {
        return true;
    }
    else
        return false;
}
int next(int i)
{
    if (i == 3 || i == 4)
        return 5;
    else if (i == 6 || i == 7)
        return 8;
    else
        return 0;
}

void solve()
{
    int h, m;
    cin >> h >> m;
    string s;
    cin >> s;
    int h1 = s[0] - '0';
    int h2 = s[1] - '0';
    int m1 = s[3] - '0';
    int m2 = s[4] - '0';
    if (h1 == 2)
    {
        h1 = 5;
    }
    else if (h1 == 5)
    {
        h1 = 2;
    }
    if (h2 == 2)
    {
        h2 = 5;
    }
    else if (h2 == 5)
    {
        h2 = 2;
    }
    if (m1 == 2)
    {
        m1 = 5;
    }
    else if (m1 == 5)
    {
        m1 = 2;
    }
    if (m2 == 2)
    {
        m2 = 5;
    }
    else if (m2 == 5)
    {
        m2 = 2;
    }
    int k1 = m2 * 10 + m1;
    int k2 = h2 * 10 + h1;
    if (k1 >= h && k2 >= m)
    {
        cout << "00:00";
    }
    else
    {
        if (k1 < h && k2 < m)
        {
            if (!(isvalid(h1)))
            {
                h1 = next(h1);
            }
            if (!(isvalid(h2)))
            {
                h2 = next(h2);
            }

            if (!(isvalid(m1)))
            {
                m1 = next(m1);
            }
            if (!(isvalid(m2)))
            {
                m2 = next(m2);
            }
            int f1 = m2 * 10 + m1;
            int f2 = h2 * 10 + h1;
            if (f1)
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