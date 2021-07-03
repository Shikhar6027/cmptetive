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
    ll n, ans;
    cin >> n;
    vector<ll> v(n);
    for (ll &t : v)
        cin >> t;

    if (n <= 3)
    {
        cout << n;
        return;
    }

    ans = 3;
    map<ll, vector<pair<ll, ll>>> mat;
    ll curr, last;
    ll start = 0, end = 1;

    last = v[1] - v[0];
    for (ll i = 2; i < n; ++i)
    {
        curr = v[i] - v[i - 1];
        if (curr == last)
            end++;
        else
        {
            mat[last].push_back({start, end});
            start = i - 1;
            end = i;
            last = curr;
        }
    }
    mat[last].push_back({start, end});
    if (end - start + 1 == n)
    {
        cout << n;
        return;
    }

    for (auto tmp : mat)
    {
        ll diff = tmp.first;
        auto ve = tmp.second;
        for (ll i = 1; i < ve.size(); ++i)
        {
            if ((ve[i].first - ve[i - 1].second == 2) && ((v[ve[i - 1].second] + 2 * diff) == v[ve[i].first]))
            {
                ans = max(ans, ve[i].second - ve[i - 1].first + 1);
            }
        }
        for (auto t : ve)
        {
            if ((t.first > 1) && ((v[t.first] - 2 * diff) == v[t.first - 2]))
                ans = max(ans, t.second - t.first + 3);
            else if ((t.second < n - 2) && ((v[t.second] + 2 * diff) == v[t.second + 2]))
                ans = max(ans, t.second - t.first + 3);
            else if ((t.first > 0) || (t.second < n - 1))
                ans = max(ans, t.second - t.first + 2);
        }
    }
    cout << ans;
}

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    int t, k = 1;
    scanf("%d", &t);
    while (t--)
    {
        cout << "Case #" << k << ": ";
        solve();
        k++;
        cout << "\n";
    }
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}