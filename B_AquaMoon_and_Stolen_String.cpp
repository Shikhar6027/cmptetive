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
#define fo(i, x, y) for (__typeof(x) i = x; i < y; ++i)
#define fr(i, x, y) for (__typeof(x) i = x; i >= y; i--)
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
    // int n, m;
    // cin >> n >> m;
    // map<char, int> m1, m2;
    // vector<string> v(n);
    // for (int i = 0; i < n; i++)
    // {
    //     string s;
    //     cin >> s;
    //     v[i] = s;
    //     m1[s[0]] = i;
    // }
    // for (int i = 0; i < n - 1; i++)
    // {
    //     string s;
    //     cin >> s;

    //     m2[s[0]] = i;
    // }
    // for (auto i : m1)
    // {
    //     if (m2.find(i.first) == m2.end())
    //     {
    //         cout << v[i.second];
    //         cout<<flush;
    //         return;
    //     }
    // }
    ll n, m;
    cin >> n >> m;
    map<ll, ll> ans[400];
    vector<string> s(2 * n - 1);
    fo(i, 0, 2 * n - 1)
    {
        cin >> s[i];
    }
    fo(i, 0, 2 * n - 1)
    {
        fo(j, 0, m)
        {
            ans[s[i][j]][j]++;
        }
    }
    fo(i, 0, 2 * n - 1)
    {
        bool f = 1;
        fo(j, 0, m)
        {
            f &= ((ans[s[i][j]][j] & 1) == 1);
        }
        if (f == 1)
        {
            cout << s[i] << endl;
            break;
        }
    }
    fo(i, 0, 2 * n - 1)
    {
        s[i] = "";
    }
    cout.flush();
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