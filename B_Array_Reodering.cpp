// #include <bits/stdc++.h>
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
//     int n;
//     cin >> n;
//     vector<int> v(n),a,b,c(n);
//     for (int i = 0; i < n;i++)
//     {
//         cin >> v[i];
//         if(v[i]%2==0)
//             a.push_back(v[i]);
//             else
//                 a.push_back(v[i]);
//     }
//     int sz = a.size(), sz2 = b.size();
//     int i = 0;
//     while (sz--)
//     {
//         c.push_back(a[i]);
//         i++;
//         }
//         i = 0;
//         while(sz1--)
//         {
//             c.push_back(b[i]);
//         }

//         int t = n - 1;
//         int j = 0;
//         for (j = 0; j < n;j++)
//         [
//             if(c[i]%2==0)
//             {

//             }
//         ]
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
#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

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

void compute()
{
    int n, odd = 0, even = 0, ans = 0, t;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        (t & 1) ? ++odd : ++even;
        if (t & 1)
            v.push_back(t);
    }
    ans = (n * (n - 1) / 2) - (odd * (odd - 1) / 2);

    n = v.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (gcd(v[i], v[j]) > 1)
                ++ans;
        }
    }
    cout << ans << "\n";
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
        compute();
    }
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}