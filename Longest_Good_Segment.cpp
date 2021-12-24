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
    ll n, k, s, res = 0, ptr, flag = 0, po;
    cin >> n >> k >> s;

    //ptr = k;
    for (ptr = k; ptr > 0; ptr = ptr / 2)
    {
        flag++;
    }
    

    vector<ll> tmp(n + 1);
    vector<vector<ll>> binary_dp(n + 1, vector<ll>(flag + 1));
    for (int i = 1; i <= n; ++i)
    {
        cin >> tmp[i];
        tmp[i] += tmp[i - 1];
        auto iterat = lower_bound(tmp.begin(), tmp.begin() + i, tmp[i] - s);
        if (iterat != tmp.end())
        {
            int indx = iterat - tmp.begin();
            binary_dp[i][0] = indx;
            for (int j = 1; j <= flag; ++j)
            {
                binary_dp[i][j] = binary_dp[binary_dp[i][j - 1]][j - 1];
            }

            indx = i, ptr = k, po = 0;
            for (ptr = k; ptr > 0; ptr = ptr / 2)
            {
                if (ptr % 2 == 1)
                    indx = binary_dp[indx][po];
                ++po;
            }
            res = max(res, i - indx);
        }
        else
        {
            for (int j = 0; j <= flag; ++j)
                binary_dp[i][j] = i;
        }
    }

    cout << res;
}

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    int ptr;
    scanf("%d", &ptr);
    while (ptr--)
    {
        solve();
        cout << "\n";
    }
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}