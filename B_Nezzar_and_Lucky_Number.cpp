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
    ll q, d;
    cin >> q >> d;
    //int a[q];
    ll p, l = 0;
    while (q--)
    {
        ll k;
        cin >> k;
        ll i = 1;
        ll p = 10;
        ll sum = k;
        if (k < d * 10)
        {
            while (sum >= d)
            {
                if (sum % d == 0)
                {
                    cout << "YES\n";
                    l = 1;
                    break;
                }
                sum -= 10;
                // else
                // {
                //     sum = sum - 10;
                //     i++;
                // }
            }
            //if (l != 1)
            if (sum < d)
                cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
    // for (int u = 0; u < q; u++)
    // {
    //     int k;
    //     cin >> k;
    //     int g = 0;
    //     // a[i] = k;
    //     if (k % 10 >= d)
    //     {
    //         p = k - (k % 10 - d);
    //     }
    //     else
    //     {
    //         p = k + d - k % 10 - 10;
    //     }
    //     int h = d, j = 1, l = p;
    //     while (j <= k / 10)
    //     {
    //         int i = 1;
    //         while (p < k)
    //         {
    //             p += i * h;
    //             i++;
    //         }
    //         if (p == k)
    //         {
    //             cout << "YES\n";
    //             g = 1;
    //             // return;
    //             break;
    //         }
    //         p = l - j * 10;
    //         j++;
    //     }
    //     if (g == 0)
    //         cout << "NO\n";
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
        //cout << "\n";
    }
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}