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
ll m = 0;
void solve()
{
    ll n, c, i, j;
    cin >> n >> c;
    if (c < (n - 1) || (c >= (n * (n + 1)) / 2))
    {
        m++;
        //cout << "Case #" << m << ": ";
        cout << "IMPOSSIBLE";
        return;
    }
    vector<ll> v;
    for (i = 0; i < n; i++)
    {
        v.push_back(i + 1);
    }
    c -= (n - 1);
    for (i = 0; i + 1 < n; i++)
    {
        if (c == 0)
            break;
        // cout<<c<<tab<<n-(i+1)<<endl;
        if (c <= (n - (i + 1)))
        {
            int fr[n + 5] = {0};
            for (ll j = 0; j < n; j++)
            {
                fr[v[j]] = j;
            }

            ll mi = min(fr[i + 1], fr[n]);
            reverse(v.begin() + mi, v.begin() + mi + c + 1);
            break;
        }
        else
        {

            int fr[n + 5] = {0};
            for (ll j = 0; j < n; j++)
            {
                fr[v[j]] = j;
            }
            //cout<<fr[i+1]<<tab<<fr[n]<<tab<<i<<endl;
            ll mi = min(fr[i + 1], fr[n]);
            ll mx = max(fr[i + 1], fr[n]);
            reverse(v.begin() + mi, v.begin() + mx + 1);
            c -= (n - (i + 1));
        }
        // cout<<c<<endl;
        // for(auto x:v)
        // cout<<x<<tab;
        // cout<<endl;
    }
    m++;
    //  cout << "Case #" << m << ": ";
    //cout << m;
    for (auto x : v)
        cout << x << " ";
    //  cout << endl;
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