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

bool there(map<int, int> &m, int x)
{
    int cnt = 0;
    for (auto i : m)
    {
        if (i.first < x && i.second < m[x])
        {
            cnt++;
        }
    }
    return cnt == x - 1;
}

void solve()
{
    int n;
    cin >> n;
    // int w[n], l[n],a[n];
    // for (int i = 0; i < n;i++)
    // {
    //     cin >> w[i];
    //     a[i] = w[i];
    // }
    // for (int i = 0; i < n;i++)
    // {
    //     cin >> l[i];
    // }
    // sort(a, a + n);

    // int cnt = 0;
    vector<int> w, l;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        w.push_back(k);
    }

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        l.push_back(k);
    }

    map<int, int> m1, m2;
    for (int i = 0; i < w.size(); i++)
    {
        m1[w[i]] = i;
        m2[w[i]] = l[i];
    }
    int cnt = 0;
    sort(w.begin(), w.end());
    for (int i = 1; i < w.size(); i++)
    {
        while (!there(m1, w[i]))
        {
            cnt++;
            m1[w[i]] += m2[w[i]];
        }
    }
    cout << cnt;
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