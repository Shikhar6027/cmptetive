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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll cnt0 = 0, cntp = 0, sum = 0, seg = 0;
    for (auto &i : a)
    {
        cin >> i;
        
    }
    ll ans = 0;
    vector<ll> vl(n, 10000000000), vr(n, 10000000000);
    for (ll i = 1; i < 2 * n; i++)
    {
        vl[i % n] = min(vl[i % n], vl[(i - 1) % n] + 1);
        if (a[i % n] > 0)
        {
            vl[i % n] = 0;
        }
    }
    for (ll i = 2 * n - 2; i >= 0; i--)
    {
        vr[i % n] = min(vr[i % n], vr[(i + 1) % n] + 1);
        if (a[i % n] > 0)
        {
            vr[i % n] = 0;
        }
    }
    for (ll i = 0; i < n; i++)
    {
        ans += max(2 * (k - min(vl[i], vr[i])), 0);
    }
   
    cout << sum + ans;
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