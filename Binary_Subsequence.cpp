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
    int n, cnt = 0, cnt1 = 0;
    cin >> n;
    string s;
    cin >> s;
    int i = 0, j = n - 1;
    while (s[i] == '0' && i < n)
    {
        i++;
    }
    while (s[j] == '1' && j >= 0)
    {
        j--;
    }
    while (i < j)
    {

        // if (i < j)
        // {
        cnt++;
        i++;
        while (s[i] == '0' && i < n)
        {
            i++;
        }

        if (i >= j)
        {
            break;
        }
        else
        {
            cnt++;
            j--;
            while (s[j] == '1' && j > 0)
            {
                j--;
            }
        }

        // }
        // else{
        //     while(s[i]==0)
        //     {
        //         i++;
        //     }
    }
    i = 0, j = n - 1;
    while (s[i] == '0' && i < n)
    {
        i++;
    }
    while (s[j] == '1' && j >= 0)
    {
        j--;
    }
    while (i < j)
    {

        // if (i < j)
        // {
        cnt1++;
        --j;
        while (s[i] == '1')
        {
            --j;
        }

        if (i >= j)
        {
            break;
        }
        else
        {
            cnt1++;
            i++;
            while (s[j] == '0')
            {
                i++;
            }
        }

        // }
        // else{
        //     while(s[i]==0)
        //     {
        //         i++;
        //     }
    }
    cout << max(cnt, cnt1);

    // ll n, sum = 0;
    // cin >> n;
    // ll a[n];
    // for (ll i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    //     if (a[i] % 2 == 1)
    //         sum++;
    // }
    // if (sum % 2 == 0)
    // {
    //     cout << "1";
    // }
    // else
    //     cout << "2";
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