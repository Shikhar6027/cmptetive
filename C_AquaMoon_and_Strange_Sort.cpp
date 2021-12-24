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
    int n;
    cin >> n;
    vector<pair<int, int>> a(n), b(n);
    // map<int, int> m1, m2;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        a[i] = {k, i};
    }

    sort(a.begin(), a.end());
    int k = 0;
    for (auto i : a)
    {
        b[k] = {i.first, k};
        k++;
    }
    for (int i = 0; i < n; i++)
    {
        if (abs(a[i].second - b[i].second) % 2 == 1)
        {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
    // ll n, i;
    // cin >> n;
    // vector<ll> v;
    // vector<pair<ll, ll>> v2;
    // for (i = 0; i < n; i++)
    // {
    //     ll te;
    //     cin >> te;
    //     v.push_back(te);
    //     v2.push_back({te, i});
    // }
    // vector<ll> v1 = v;
    // sort(v.begin(), v.end());
    // sort(v2.begin(), v2.end());
    // for (i = 0; i < n;)
    // {
    //     ll x = v[i], cnteve = 0, cnto = 0;
    //     while (i < n && x == v[i])
    //     {
    //         if ((v2[i].second) % 2 == 0)
    //         {
    //             cnteve++;
    //         }
    //         else
    //             cnto++;

    //         if (i % 2 == 0)
    //             cnteve--;
    //         else
    //             cnto--;

    //         i++;
    //     }
    //     if (cnteve == 0 && cnto == 0)
    //     {
    //     }
    //     else
    //     {
    //         cout << "NO"
    //              << "\n";
    //         return;
    //     }
    // }
    // cout << "YES"
    //      << "\n";
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