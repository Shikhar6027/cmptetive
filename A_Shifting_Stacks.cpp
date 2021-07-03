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
    vector<ll> a(n);
    for (ll &x : a)
        cin >> x;

    ll t = a[0];
    for (ll i = 1; i < n; ++i)
    {
        if (a[i] < i)
        {
            if (t < i - a[i])
            {
                cout << "NO\n";
                return;
            }
            else
            {
                t -= i - a[i];
                a[i] = i;
            }
        }
        else
        {
            t += a[i] - i;
            a[i] = i;
        }
    }
    cout << "YES\n";
    // ll n;
    // cin >> n;
    // ll a[n];
    // ll cnt0 = 0, sum = 0;
    // for (ll i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    //     if (a[i] == 0)
    //     {
    //         cnt0++;
    //     }
    //     sum += a[i];
    // }
    // ll k = (n * (n + 1)) / 2;

    // if (n == 2)
    // {
    //     if (cnt0 == 1)
    //     {
    //         cout << "YES";
    //         return;
    //     }
    // }
    // if (n == 1)
    // {
    //     cout << "YES";
    //     return;
    // }
    // if (sum >= k)
    // {
    //     cout << "YES";
    // }
    // else
    //     cout << "NO";
    // // if (!(cnt0 > n - 1))
    // // {
    // //     cout << "YES";
    // // }
    // // else
    // //     cout << "NO";
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
        // cout << "\n";
    }
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}