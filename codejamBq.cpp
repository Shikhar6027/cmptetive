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
    int x, y;
    cin >> x >> y;
    string s;
    cin >> s;
    int i = 0;
    while (s[i] == '?')
    {
        i++;
    }
    int l = s.length() - 1;
    while (s[l] == '?')
    {
        l--;
    }
    int sum = 0;
    while (i < l)
    {
        if (s[i] == 'C' && s[i + 1] == 'J')
        {
            sum += x;
            i++;
        }
        else if (s[i] == 'J' && s[i + 1] == 'C')
        {
            sum += y;
            i++;
        }
        else
        {
            char h = s[i];
            i = i + 1;
            while (s[i] == '?')
            {
                i++;
            }
            if (h != s[i])
            {
                if (h == 'C')
                    sum += x;
                else
                    sum += y;
            }
        }
    }
    cout << sum;
}

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    int t;
    int k = 1;
    scanf("%d", &t);
    while (t--)
    {
        cout << "Case #" << k << ": ";
        solve();
        k++;
        cout << "\n";
    }
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}