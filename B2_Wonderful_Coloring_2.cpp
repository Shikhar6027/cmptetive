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
bool cmp(const pair<int, vector<int>> &a,
         const pair<int, vector<int>> &b)
{

    return (a.second.size() > b.second.size());
}
void solve()
{
    int n, k;
    cin >> n >> k;
    // map<int, vector<int>> m;
    // for (int i = 0; i < n; i++)
    // {
    //     int h;
    //     cin >> h;
    //     m[h].push_back(i);
    // }
    // vector<int> ans(n, 0);
    // vector<int> col(k + 1, 0);
    // int mx = 0;
    // int fl = 1, tmp = 0;
    // vector<pair<int, vector<int>>> pr;
    // for (auto i : m)
    // {
    //     pr.push_back({i.first, i.second});
    // }
    // sort(pr.begin(), pr.end(), cmp);
    // int tmp = 0,pp=0;
    // for (auto i : pr)
    // {

    //     for (auto j : i.second)
    //     {
    //         tmp = fl;
    //         if (fl <= k)
    //         {
    //             // if (col[fl] <= mx)
    //             // {
    //             ans[j] = fl;
    //             //col[fl]++;
    //             // mx = max(mx, col[fl]);
    //             //fl = fl++;
    //             //}
    //         }
    //         else
    //         {
    //             if()
    //             // fl = 1;
    //             // tmp = 1;
    //             break;
    //         }
    //         fl++;
    //     }
    //     if (fl > k)
    //         fl = 1;
    // }
    // for (auto i : ans)
    //     cout << i << " ";
    vector<int> a(n);

    map<int, vector<int>> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        m[a[i]].push_back(i);
    }

    int stop = 0;
    vector<int> ans(n, 0), df;
    for (auto &e : m)
    {
        if (e.second.size() >= k)
        {
            int cp = k;
            for (int i = 0; i < e.second.size() and cp; ++i)
                ans[e.second[i]] = cp, --cp;
        }
        else
            df.push_back(e.first);
    }

    vector<int> f;
    for (int j = 0; j < df.size(); ++j)
    {
        vector<int> v = m[df[j]], idx;
        for (int i = 0; i < v.size(); ++i)
        {
            f.push_back(v[i]);
        }
    }

    int fs = f.size(), end = fs / k, init = k;
    for (int i = 0; i < end * k; ++i)
    {
        ans[f[i]] = init;
        --init;
        if (init == 0)
            init = k;
    }

    for (int i = 0; i < n; ++i)
        cout << ans[i] << ' ';
    //cout << nline;
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