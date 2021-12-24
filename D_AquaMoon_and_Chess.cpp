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
const ll mod = 998244353;
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
int gcdExt(ll a, ll b, ll *x, ll *y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    ll x1, y1;
    ll gcd = gcdExt(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

ll modInv(ll b, ll tmp)
{
    ll x, y;
    ll g = gcdExt(b, tmp, &x, &y);
    if (g != 1)
        return -1;
    return (x % tmp + tmp) % tmp;
}

ll modDivide(ll a, ll b, ll tmp)
{
    a = a % tmp;
    ll inv = modInv(b, tmp);
    ll c = (inv * a) % tmp;
    return c;
}

ll fact(ll n)
{
    ll ans = 1;
    for (ll i = 1; i <= n; i++)
        ans = (ans * i) % mod;

    return ans;
}

void solve()
{
    int n;
    string s;
    cin >> n >> s;

    ll cnt1 = 0, cnt0 = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '0')
        {
            ++cnt0;
        }
        else if (s[i] == '1' && i + 1 < n && s[i + 1] == '1')
        {
            cnt1++, ++i;
        }
    }
    ll a = fact(cnt1 + cnt0);
    ll b = fact(cnt1);
    ll c = fact(cnt0);

    // ll ans =;
    cout << modDivide(a, (b * c) % mod, mod);
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