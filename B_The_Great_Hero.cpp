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
    ll a, b, n;
    cin >> a >> b >> n;
    vector<pair<ll, ll>> h(n);
    for (auto &x : h)
    {
        cin >> x.first;
    }
    for (auto &y : h)
    {
        cin >> y.second;
    }
     sort(h.begin(), h.end());
    for (auto &x : h)
    {
        if (b > 0 && x.second > 0)
        {
            ll t, p;
            t = (b / x.first) + (b % x.first != 0);
            p = (x.second / a) + (x.second % a != 0);
            b = b - x.first * min(t, p);
            x.second -= a * min(t, p);
        }
        // {
        //     b = b - x.first;
        //     x.second -= a;
        // }

        if (x.second <= 0)
        {
            continue;
        }
        if (b <= 0)
        {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
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