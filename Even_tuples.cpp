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
    // int n, q;
    // cin >> n >> q;
    // vector<int> a(n);
    // for (int i = 0; i < n;i++)
    //     cin >> a[i];
    // vector<int> pre(n, 0);
    // pre[0] = a[0];
    // for (int i = 1; i < n;i++)
    // {
    //     pre[i] = a[i] + pre[i - 1];
    // }

    // while(q--)
    // {
    //     int l, r;
    //     cin >> l >> r;

    // }
    int n, q, l, r;
    ll o, e, ans;
    cin >> n >> q;
    vector<int> tmp(n), prev(n), pre(n);
    for (int &t : tmp)
        cin >> t;

    (tmp[0] & 1) ? prev[0] = 1 : pre[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        pre[i] = pre[i - 1];
        prev[i] = prev[i - 1];
        (tmp[i] & 1) ? prev[i]++ : pre[i]++;
    }

    while (q--)
    {
        cin >> l >> r;
        --l, --r;
        o = prev[r] - (l ? prev[l - 1] : 0);
        e = pre[r] - (l ? pre[l - 1] : 0);
        ans = 0;
        if (e >= 3)
            ans += e * (e - 1) * (e - 2) / 6;
        if (e >= 1 && o >= 2)
            ans += e * o * (o - 1) / 2;
        cout << ans << endl;
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