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
    string s;
    cin >> s;
    int n = s.length();
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                dp[i][j] = 1;
            // if (j == i + 1)
            // {
            //     if (s[j] != s[i + 1] || s[j] == '?' && s[i + 1] == '?')
            //         dp[i][j] = 2;
            // }
        }
    }
    int end;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= n - i; j++)
        {
            end = j + i - 1;
            dp[j][end] = ((s[end] != s[end - 1]) || (s[end] == '?' && s[end - 1] == '?')) ? (dp[j][end - 1] + 1) : dp[j][end - 1];
            //dp[j][end]=(dp[j][end-1] && dp[j+1][end])?dp[]
        }
    }
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        mx += dp[i][n - 1];
    }
    cout << mx;
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