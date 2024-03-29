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
#define vll vector<ll>
#define ff first
#define ss second
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
    // int n, k;
    // cin >> n >> k;
    // vector<int> a(n,0),bk(k);
    // for (int i = 0; i < k;i++)
    // {
    //     cin>>bk[i];
    // }
    // for (int i = 0; i < k;i++)
    // {
    //     int tmp;
    //     cin >> tmp;
    //     a[bk[i]] = tmp;
    // }
    ll n, k;

    cin >> n >> k;

    vector<pair<ll, ll>> dp(k + 1, {0, 0});
    vll mp(n + 1, 0);

    for (ll i = 1; i <= k; i++)
    {
        cin >> dp[i].ff;
    }
    for (ll i = 1; i <= k; i++)
    {
        cin >> dp[i].ss;
        mp[dp[i].ff] = dp[i].ss;
    }

    multiset<ll> st;
    multiset<ll> lt;

    for (ll i = 1; i <= n; i++)
    {
        if (mp[i] != 0)
            lt.insert(i + mp[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if ((st.size()) > 0 && (lt.size()) > 0)
        {
            cout << min((*lt.begin()) - i, (*st.begin()) + i) << " ";
        }

        else if ((st.size()) > 0)
        {
            cout << (*st.begin()) + i << " ";
        }

        else
        {
            cout << (*lt.begin()) - i << " ";
        }

        if (mp[i] != 0)
        {
            lt.erase(lt.find(mp[i] + i));
            st.insert(mp[i] - i);
        }
    }
    cout << endl;
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