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
    ll ans = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            ans = (ans * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return ans;
}

int pow(int x, int y)
{
    int ans = 1;
    while (y > 0)
    {
        if (y & 1)
            ans = ((ans) * (x));
        ans %= N;
        y = y >> 1;
        x = ((x) * (x));
    }
    return ans;
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
    // int n;
    // ;
    // cin >> n;
    // vector<int> a(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    // }
    // int s = a[0];
    // int count = 0,h=s;
    // while (h != 0)
    // {
    //     h = h / 10;
    //     ++count;
    // }
    // int cnt = 0;
    // for (int i = 1; i < n; i++)
    // {
    //     int g = 1;
    //     if (a[i] <= s)
    //     {
    //         int l = a[i];
    //         int ct = 0;
    //         while (l != 0)
    //         {
    //             l = l / 10;
    //             ++ct;
    //         }

    //        // if(count==ct)
    //         int k = a[i] * 10;
    //         cnt++;
    //         a[i] = k;
    //         if(a[i]==s)
    //         {
    //             k += g;
    //             g++;
    //         }
    //         if(s/10)
    //         while (k <= s)
    //         {
    //             k = a[i] * 10;
    //             cnt++;
    //             a[i] = k;
    //         }
    //     }

    //     s = a[i];
    // }
    // cout << cnt;
    ll n, tet = 0;
    cin >> n;
    vector<string> x(n);
    vector<ll> v;
    for (auto &t : x)
    {
        cin >> t;
        v.push_back(stoll(t));
    }

    for (ll i = 1; i < n; ++i)
    {
        if (v[i] <= v[i - 1])
        {
            ll flag = 0;
            for (ll j = 0; j < x[i].length(); ++j)
            {
                if (x[i][j] < x[i - 1][j])
                {
                    flag = -1;
                    break;
                }
                else if (x[i][j] > x[i - 1][j])
                {
                    flag = 1;
                    break;
                }
            }
            ll d = x[i - 1].length() - x[i].length();
            if (flag == 0)
            {
                if (d > 0)
                {
                    string t = x[i - 1].substr(x[i].length());
                    string t1 = to_string(stoll(t) + 1);
                    if (t1.length() > t.length())
                    {
                        tet += d + 1;
                        while (d--)
                            x[i] += '0';
                        x[i] += '1';
                    }
                    else
                    {
                        x[i] += t1;
                        tet += d;
                    }
                }
                else
                {
                    x[i] += '0';
                    tet += 1;
                }
            }
            else if (flag == 1)
            {
                tet += d;
                while (d--)
                    x[i] += '0';
            }
            else
            {
                tet += d + 1;
                while (d--)
                    x[i] += '0';
                x[i] += '0';
            }
            v[i] = stoll(x[i]);
        }
    }
    cout << tet;
}

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    int t, k = 1;
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