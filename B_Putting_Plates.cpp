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
    int h, w;
    cin >> h >> w;
    // if(h&1==0)
    // {
    bool b = true;

    for (int j = 0; j < h; j++)
    {
        if (j == h - 2)
        {
            for (int i = 0; i < w; i++)
                cout << 0;
            cout << "\n";
        }
        else if ((j == 0 || j == h - 1))
        {
            // if (b)
            // {
            bool k = true;
            for (int i = 0; i < w; i++)
            {
                if (k)
                {
                    cout << 1;
                    k = !k;
                }
                else
                {
                    cout << 0;
                    k = !k;
                }
            }

            b = !b;
            // }
            // else
            // {
            //     for (int i = 0; i < w; i++)
            //     {
            //         cout << 0;
            //     }
            //     b = !b;
            // }
            cout << "\n";
        }

        else
        {
            if (b)
            {
                for (int i = 0; i < w; i++)
                {
                    if (i == 0 || i == w - 1)
                        cout << 1;
                    else
                        cout << 0;
                }
            }
            else
            {
                for (int i = 0; i < w; i++)
                {
                    cout << 0;
                }
                b = !b;
            }
            cout << "\n";
        }
    }
    //  }
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