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
    int n, m, l, r, res;
    string s;
    cin >> n >> m >> s;

    vector<vector<int>> T(6, vector<int>(n + 1));
    vector<string> tmp = {"bca", "acb", "bac", "cab", "cba", "abc"};
    char chart;

    for (int i = 0; i < 6; ++i)
    {
        chart = 0;
        for (int j = 0; j < n; ++j)
        {
            if (s[j] != tmp[i][chart])
            {
                T[i][j + 1] = 1 + T[i][j];
            }
            else
            {
                T[i][j + 1] = T[i][j];
            }

            chart = (chart + 1) % 3;
        }
    }

    while (m--)
    {
        cin >> l >> r;
        res = INT_MAX;
        for (int i = 0; i < 6; ++i)
        {
            res = min(res, T[i][r] - T[i][l - 1]);
        }
        cout << res << "\n";
    }
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