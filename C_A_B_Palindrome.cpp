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
    int a, b, n;
    cin >> a >> b;
    string s;
    cin >> s;
    n = s.length();
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] == s[n - i - 1] && s[i] != '?')
        {
            if (s[i] == '0')
            {
                a = a - 2;
            }
            else
                b = b - 2;
        }

        else if (s[i] != s[n - i - 1] && s[i] != '?' && s[n - i - 1] != '?')
        {
            cout << "-1";
            return;
        }
        else
        {
            if (s[i] == '?' && s[n - i - 1] != '?')
            {
                if (s[n - i - 1] == '0')
                {
                    a--;
                    if (a > 0)
                    {
                        s[i] = '0';
                        a--;
                    }
                    else
                    {
                        cout << -1;
                        return;
                    }
                }
                else
                {
                    b--;
                    if (b > 0)
                    {
                        s[i] = '1';
                        b--;
                    }
                    else
                    {
                        cout << -1;
                        return;
                    }
                }
            }
            else if (s[i] != '?' && s[n - i - 1] == '?')
            {
                if (s[i] == '0')
                {
                    a--;
                    if (a > 0)
                    {
                        s[n - i - 1] = '0';
                        a--;
                    }
                    else
                    {
                        cout << -1;
                        return;
                    }
                }
                else
                {
                    b--;
                    if (b > 0)
                    {
                        s[n - i - 1] = '1';
                        b--;
                    }
                    else
                    {
                        cout << -1;
                        return;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n / 2; i++)

    {
        if (s[i] == '?')
        {
            if (a > 1)
            {
                s[i] = '0';
                s[n - i - 1] = '0';
                a = a - 2;
            }
            else if (b > 1)
            {
                s[i] = '1';
                s[n - i - 1] = '1';
                b = b - 2;
            }
            else
            {
                cout << -1;
                return;
            }
        }
    }

    if (n % 2 == 1)
    {

        // cout << 90;
        if (s[n / 2] == '0')
            a--;
        else if (s[n / 2] == '1')
        {
            b--;
        }
        else
        {
            if (a > 0)
            {
                //cout << 90 << " " << n;
                s[n / 2] = '0';
                a--;
            }
            else if (b > 0)
            {
                s[n / 2] = '1';
                b--;
            }
            else
            {
                cout << -1;
                return;
            }
        }
    }
    if (a != 0 || b != 0)
    {
        cout << -1;
        return;
    }
    cout << s;
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