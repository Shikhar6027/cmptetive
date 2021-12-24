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
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        c[i] = a[i] - b[i];
        if (abs(a[i] - b[i]))
            cnt += abs(a[i] - b[i]);
    }
    cout << cnt / 2 << "\n";
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[c[i]] = i;
    }
    for (auto i : m)
    {
        int k = i.first;
        if (m.find(-k) == m.end())
        {
            cout << "-1";
            return;
        }
        else
        {
            k = abs(k);
            while (k--)
            {
                cout << i.second << " " << m[-k] << "\n";
            }
            m.erase(k);
            m.erase(-k);
        }
    }
    // int n;
    // cin >> n;
    // vector<int> a(n), b(n);

    // for (int &t : a)
    //     cin >> t;
    // for (int &t : b)
    //     cin >> t;

    // int check = 0;
    // for (int i = 0; i < n; ++i)
    //     check += a[i] - b[i];

    // if (check)
    // {
    //     cout << "-1\n";
    //     return;
    // }

    // int i = 0, j = 0;
    // vector<pair<int, int>> ans;
    // while (i < n && j < n)
    // {
    //     if (a[i] <= b[i])
    //         ++i;
    //     else if (a[j] >= b[j])
    //         ++j;
    //     else
    //     {
    //         ans.push_back({i + 1, j + 1});
    //         a[i]--;
    //         a[j]++;
    //     }
    // }

    // cout << ans.size() << "\n";
    // for (auto ele : ans)
    //     cout << ele.first << " " << ele.second << "\n";
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
        //   cout<<"\n";
    }
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}