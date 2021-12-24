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
    vector<string> v;
    for (int i = 0; i < n; i++)
    {
        string k;
        cin >> k;
        v.push_back(k);
        //cout << k << "\n";
    }
    int cnt = 0, x1, x2, y1, y2;
    for (int i = 0; i < n; i++)
    {
        string s = v[i];
        for (int j = 0; j < v[i].length(); j++)
        {
            if (s[j] == '*' && cnt == 0)
            {
                x1 = i;
                y1 = j;
                cnt++;
            }
            else if (s[j] == '*' && cnt > 0)
            {
                x2 = i;
                y2 = j;
                cnt++;
                break;
            }
        }
    }
    if (x1 != x2 && y1 != y2)
    {
        for (int i = 0; i < n; i++)
        {
            if (i == x1)
            {
                string s = v[i];
                s[y2] = '*';
                v[i] = s;
            }
            if (i == x2)
            {
                string s = v[i];
                s[y1] = '*';
                v[i] = s;
            }
        }
    }
    else
    {
        if (x1 == x2)
        {
            string t;
            int k = x1 + 1;

            if (k < n)
            {
                t = v[k];
                t[y1] = '*';
                t[y2] = '*';
                v[k] = t;
            }
            else
            {
                k = k - 2;
                t = v[k];
                t[y1] = '*';
                t[y2] = '*';
                v[k] = t;
            }
        }
        else if (y1 == y2)
        {
            int k = y1 + 1;
            string t;
            if (k < n)
            {
                t = v[x1];
                t[k] = '*';
                v[x1] = t;
                t = v[x2];
                t[k] = '*';
                v[x2] = t;
            }
            else
            {
                k = k - 2;
                t = v[x1];
                t[k] = '*';
                v[x1] = t;
                t = v[x2];
                t[k] = '*';
                v[x2] = t;
            }

            
        }
    }
    // cout << x1 << " " << y1 << " " << x2 << " " << y2;

    for (int i = 0; i < n; i++)
    {
        // string k;
        // cin >> k;
        // v.push_back(k);
        cout << v[i] << "\n";
    }
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