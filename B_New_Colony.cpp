// // #include <bits/stdc++.h>
// // using namespace std;
// // #define ll long long int
// // #define max(a, b) ((a) > (b) ? (a) : (b))
// // #define min(a, b) ((a) < (b) ? (a) : (b))
// // #define gcd(a, b) __gcd(a, b)
// // #define lcm(a, b) (a * b) / gcd(a, b)
// // #define inf (long long)1e18
// // #define lcm(a, b) (a * b) / gcd(a, b)
// // #define GOLD ((1 + sqrt(5)) / 2)
// // #define gcd(a, b) __gcd(a, b)
// // const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;
// // const int N = 1e9 + 7;
// // ll powm(ll x, ll y, ll p)
// // {
// //     ll res = 1;
// //     x = x % p;
// //     while (y > 0)
// //     {
// //         if (y & 1)
// //             res = (res * x) % p;
// //         y = y >> 1;
// //         x = (x * x) % p;
// //     }
// //     return res;
// // }

// // int pow(int x, int y)
// // {
// //     int res = 1;
// //     while (y > 0)
// //     {
// //         if (y & 1)
// //             res = ((res) * (x));
// //         res %= N;
// //         y = y >> 1;
// //         x = ((x) * (x));
// //     }
// //     return res;
// // }

// // void swaps(char *x, char *y)
// // {
// //     char temp;
// //     temp = *x;
// //     *x = *y;
// //     *y = temp;
// // }

// // void swapi(int *a, int *b)
// // {
// //     int temp;
// //     temp = *a;
// //     *a = *b;
// //     *b = temp;
// // }

// // void solve()
// // {
// //     // int n, k;
// //     // cin >> n >> k;
// //     // int h[n],a[n];
// //     // int mx = 0;
// //     // for (int i = 0; i < n; i++)
// //     // {
// //     //     cin >> h[i];
// //     //     a[i] = h[i];
// //     // }
// //     // sort(a, a + n);

// // }

// // int main()
// // {
// // #ifdef debug
// //     freopen("input.txt", "r", stdin);
// //     freopen("output.txt", "w", stdout);
// //     freopen("log.txt", "w", stderr);
// // #endif
// //     int t;
// //     scanf("%d", &t);
// //     while (t--)
// //     {
// //         solve();
// //         cout << "\n";
// //     }
// // #ifdef debug
// //     fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
// // #endif
// //     return 0;
// // }
// #include <bits/stdc++.h>
// using namespace std;
// #define max(a, b) ((a) > (b) ? (a) : (b))
// #define min(a, b) ((a) < (b) ? (a) : (b))
// #define gcd(a, b) __gcd(a, b)
// #define lcm(a, b) (a * b) / gcd(a, b)
// #define GOLD ((1 + sqrt(5)) / 2)
// const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

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

// void compute()
// {
//     int n, k, ans = -1;
//     cin >> n >> k;
//     vector<int> h(n);
//     for (int &x : h)
//         cin >> x;
//     h.push_back(0);

//     for (int i = 0; i < n; ++i)
//     {
//         if (h[i] < h[i + 1])
//         {
//             int t = i;
//             while (t - 1 > 0 && h[t - 1] == h[i])
//                 --t;
//             k -= (i - t + 1) * (h[i + 1] - h[i]);
//             if (k <= 0)
//             {
//                 k += (i - t + 1) * (h[i + 1] - h[i]);
//                 ans = k % (i - t + 1);
//                 ans = ans ? (i - ans) : t;
//                 cout << ans + 1 << "\n";
//                 return;
//             }
//             while (t <= i)
//                 h[t++] = h[i + 1];
//         }
//     }
//     cout << "-1\n";
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
//         compute();
//     }
// #ifdef debug
//     fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
// #endif
//     return 0;
// }
