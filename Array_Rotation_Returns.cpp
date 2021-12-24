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
vector<ll> fun(vector<ll> &v1, vector<ll> &v2, ll idx)
{
    ll n = v1.size();
    vector<ll> res(n);
    for (ll i = 0; i < n; ++i)
        res[i] = (v1[i] + v2[(i + idx) % n]) % n;
    return res;
}
void solve()
{
  
    ll n;
    cin >> n;
    vector<ll> a(n), b(n), res(n, INT_MAX);

    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] %= n;
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
        b[i] %= n;
    }

    ll mn = INT_MAX;
    for (ll j : b)
    {
        if ((a[0] + j) % n < mn)
            mn = (a[0] + j) % n;
    }

    for (ll i = 0; i < n; ++i)
    {
        if ((b[i] + a[0]) % n == mn)
        {
            vector<ll> tmp = fun(a, b, i);
            if (tmp < res)
                res = tmp;
        }
    }

    for (ll i = 0; i < n; i++)
        cout << res[i] << " ";

    //cout << ix << " ";
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