#include <bits/stdc++.h>
using namespace std;
#define ll long long int
//#define max(a, b) ((a) > (b) ? (a) : (b))
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
ll dp[101][100001];

ll fun(ll n, ll w, vector<ll> v, vector<ll> wt)
{
    if (n <= 0 || w <= 0)
    {
        return 0;
    }
    if (dp[n][w] != -1)
        return dp[n][w];
    // ll ans1 = 0;
    if (wt[n - 1] <= w)
    {
        ll t1 = v[n - 1] + fun(n - 1, w - wt[n - 1], v, wt);
        ll t2 = fun(n - 1, w, v, wt);
        return dp[n][w] = max(t1, t2);
    }
    else
    {
        return dp[n][w] = fun(n - 1, w, v, wt);
    }
}
void solve()
{
    memset(dp, -1, sizeof(dp));
    ll n, w;
    cin >> n >> w;
    vector<ll> v(n), wt(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> wt[i];
        cin >> v[i];
    }

    ll ans = fun(n, w, v, wt);

    cout << ans;
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