#include <bits/stdc++.h>
// using namespace std;
// #define ll long long int
// #define max(a, b) ((a) > (b) ? (a) : (b))
// #define min(a, b) ((a) < (b) ? (a) : (b))
// #define gcd(a, b) __gcd(a, b)
// #define lcm(a, b) (a * b) / gcd(a, b)
// #define inf (long long)1e18
// #define lcm(a, b) (a * b) / gcd(a, b)
// #define GOLD ((1 + sqrt(5)) / 2)
// #define gcd(a, b) __gcd(a, b)
// const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;
// const int N = 1e9 + 7;
// ll powm(ll x, ll y, ll p)
// {
// ll res = 1;
// x = x % p;
// while (y > 0)
// {
// if (y & 1)
// res = (res * x) % p;
// y = y >> 1;
// x = (x * x) % p;
// }
// return res;
// }

// int pow(int x, int y)
// {
// int res = 1;
// while (y > 0)
// {
// if (y & 1)
// res = ((res) * (x));
// res %= N;
// y = y >> 1;
// x = ((x) * (x));
// }
// return res;
// }

// void swaps(char *x, char *y)
// {
//     char temp;
//     temp = *x;
//     *x = *y;
//     *y = temp;
// }

// void swapi(int *a, int *b)
// {
//     int temp;
//     temp = *a;
//     *a = *b;
//     *b = temp;
// }

// void solve()
// {
//     //Start programming here
// }

// int main()
// {
// #ifdef debug
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     freopen("log.txt", "w", stderr);
// #endif
//     int t;
//     scanf("%d", &t);
//     while (t--)
//     {
//         solve();
//         cout<<"\n";
//     }
// #ifdef debug
//     fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
// #endif
//     return 0;
// }
//#include <bits/stdc++.h>
using namespace std;
#define m1 1000000007
#define ll long long
#define vi vector<int>
#define mid(l, r) (l + (r - l) / 2)
#define loop(i, a, b) for (int i = (a); i <= (b); i++)
#define loopneg(i, a, b) for (int i = (a); i >= (b); i--)
#define arint(n) int ar[n]

const int MAX = 1000000;
int prefix[MAX + 1];

void sieve()
{
    bool pr[MAX + 1];
    memset(pr, true, sizeof(pr));

    for (int i = 2; i * i <= MAX; i++)
    {
        if (pr[i] == true)
        {
            for (int j = i * 2; j <= MAX; j += i)
            {
                pr[j] = false;
            }
        }
    }

    prefix[0] = prefix[1] = 0;
    for (int i = 2; i <= MAX; i++)
    {
        prefix[i] = prefix[i - 1];
        if (pr[i])
            prefix[i]++;
    }
}

int count_primes(int x)
{
    return prefix[x];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    sieve();
    ll t;
    cin >> t;
    while (t--)
    {
        ll x, y;
        cin >> x >> y;
        if (count_primes(x) > y)
            cout << "Divyam\n";
        //  << "\n";
        else
            cout << "Chef\n";
    }
    return 0;
}