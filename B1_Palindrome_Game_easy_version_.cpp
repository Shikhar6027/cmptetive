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
    string s;
    cin >> s;
    bool b;

    // if (n == 1)
    // {
    //     if (s[0] == '0')
    //     {
    //         cout << "BOB";
    //         return;
    //     }
    //     else
    //     {
    //         cout << "ALICE";
    //         return;
    //     }
    // }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            cnt++;
    }
    if (cnt == 1)
    {
        cout << "BOB";
        return;
    }
    b = ((n & 1) && (s[n / 2] == '0'));
    if (b)
    {
        if (cnt == 1)
        {
            cout << "BOB";
        }
        else
        {
            cout << "ALICE";
        }
    }
    else
    {
        if (cnt == 0)
        {
            cout << "DRAW";
        }
        else
            cout << "BOB";
    }
    // cout << cnt;
    // if (n % 2 == 0)
    // {

    //     if (cnt % 4 == 0)
    //         cout << "DRAW";
    //     else
    //         cout << "BOB";
    // }
    // else
    // {
    //     if (s[n / 2] == '0')
    //     {
    //         cnt--;
    //         // cnt = cnt / 2;
    //         cout << cnt;
    //         if (cnt % 2 == 0 && cnt % 3 != 0)
    //         {
    //             cout << "ALICE";
    //         }
    //         else
    //         {
    //             cout << "BOB";
    //         }
    //     }
    //     else
    //     {
    //         if (cnt % 2 == 0 && cnt % 3 != 0)

    //         {
    //             cout << "DRAW";
    //         }
    //         else
    //         {
    //             cout << "BOB";
    //         }
    //     }
    // }
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