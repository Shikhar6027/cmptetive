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

void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1;
        return;
    }
    if (n == 2)
    {
        cout << -1;
        return;
    }
    if (n % 2 == 0)
    {
        int t = 1, t2 = 4;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i % 2 == 0)
                {
                    if (t % (n * n) == 0)
                    {
                        cout << n * n << " ";
                    }
                    else
                        cout << (t % (n * n)) << " ";
                    t = t + 2;
                }
                else
                {
                    if (t2 % (n * n) == 0)
                    {
                        cout << n * n << " ";
                    }
                    else
                        cout << t2 % (n * n) << " ";
                    t2 = t2 + 2;
                }
            }
            cout << "\n";
        }
    }
    else
    {
        int t = 1, t2 = n + 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i % 2 == 0)
                {
                    if (t % (n * n) == 0)
                    {
                        cout << n * n << " ";
                    }
                    else
                        cout << (t % (n * n)) << " ";
                    t = t + 2;
                }
                else
                {
                    if (t2 % (n * n) == 0)
                    {
                        cout << n * n << " ";
                    }
                    else
                        cout << t2 % (n * n) << " ";
                    t2 = t2 + 2;
                }
            }
            cout << "\n";
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