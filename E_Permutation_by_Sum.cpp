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
    int n, l, r, s;
    cin >> n >> l >> r >> s;
    int cnt = r - l + 1;
    int sum1 = cnt * (cnt + 1) / 2;
    int sum2 = n * (n + 1) / 2 - (n - cnt) * (n - cnt + 1) / 2;
    if (sum1 <= s && s <= sum2)
    {

        vector<int> ans(cnt), v(n + 1);
        for (int i = 0; i < cnt; i++)
        {
            ans[i] = i + 1;
            v[i + 1]++;
        }
        int j = n, sum = sum1;
        int h = cnt, k = cnt - 1;
        while (sum != s)
        {
            if (sum - cnt + j > s)
            {
                j--;
            }
            else
            {
                sum -= cnt;
                v[cnt] = 0;
                cnt--;
                sum += j;
                ans[k] = j;
                k--;
                v[j] = 1;
                j--;
            }
        }
        int val = 1, tmp = 1;
        while (tmp < l)
        {
            if (v[val] == 0)
            {
                cout << val << " ";
                v[val] = 1;
                tmp++;
            }
            val++;
        }
        for (auto i : ans)
        {
            cout << i << " ";
            v[i] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            if (v[i] == 0)
                cout << i << " ";
        }
    }
    else
        cout << -1;
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