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

void swapi(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

ll dp[101][100001];

ll fun(ll i, ll vm, vector<ll> &v, vector<ll> &wt)
{
    if (vm < 0)
    {
        return 1e13;
    }
    if (vm == 0)
    {
        return 0;
    }
    if (i >= v.size())
    {
        return 1e13;
    }

    if (dp[i][vm] != -1)
        return dp[i][vm];
    // ll ans1 = 0;
    if (v[i] <= vm)
    {
        ll t1 = wt[i] + fun(i + 1, vm - v[i], v, wt);
        ll t2 = fun(i + 1, vm, v, wt);
        return dp[i][vm] = min(t1, t2);
    }
    else
    {
        return dp[i][vm] = fun(i + 1, vm, v, wt);
    }
}
void solve()
{
    memset(dp, -1, sizeof(dp));
    ll n, w;
    cin >> n >> w;
    vector<ll> v(n), wt(n);
    ll vmax = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> wt[i];
        cin >> v[i];
        vmax += v[i];
    }
    ll wgt = 0;
    ll j;
    for (j = vmax; j >= 1; j--)
    {
        wgt = fun(0, j, v, wt);
        if (wgt <= w)
            break;
    }
    cout << j;
    //  ll ans = fun(n, w, v, wt);
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
    //     cout<<"\n";
    // }
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}