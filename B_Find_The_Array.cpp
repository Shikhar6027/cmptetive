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
    ll n;
    cin >> n;
    vector<ll> a(n), ans1(n), ans2(n);
    ll res = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        res += a[i];
    }
    ans1 = a;
    ans2 = a;
    for (ll i = 0; i < n; i += 2)
    {
        ans1[i] = 1;
    }
    for (ll i = 1; i < n; i += 2)
    {
        ans2[i] = 1;
    }
    ll sum1 = 0, sum2 = 0;
    for (ll i = 0; i < n; i++)
    {
        sum1 += abs(a[i] - ans1[i]);
        sum2 += abs(a[i] - ans2[i]);
    }
    if (2 * sum1 <= res)
    {
        for (auto i : ans1)
        {
            cout << i << " ";
        }
    }
    else
    {
        for (auto i : ans2)
        {
            cout << i << " ";
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