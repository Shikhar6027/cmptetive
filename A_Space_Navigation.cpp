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
    int x, y, cntu = 0, cntr = 0, cntd = 0, cntl = 0;
    cin >> x >> y;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'U')
            cntu++;
        if (s[i] == 'R')
            cntr++;

        if (s[i] == 'D')
            cntd++;

        if (s[i] == 'L')
            cntl++;
    }
    int ans = 0;
    if (x > 0)
    {
        if (cntr >= x)
        {
            ans++;
        }
    }
    else if (x <= 0)
    {
        if (cntl >= abs(x))
        {
            ans++;
        }
    }

    if (y > 0)
    {
        if (cntu >= y)
        {
            ans++;
        }
    }
    else if (y <= 0)
    {
        if (cntd >= abs(y))
        {
            ans++;
        }
    }
    if (ans >= 2)
    {
        cout << "YES";
    }
    else
        cout << "NO";
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