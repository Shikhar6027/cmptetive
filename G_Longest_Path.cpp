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

vector<vector<int>> adj;
vector<int> dp;
int longestPath(int i)
{
    if (dp[i] != -1)
        return dp[i];
    int l = 0;
    for (int j = 0; j < adj[i].size(); j++)
    {
        int k = longestPath(adj[i][j]);
        l = max(k, l);
    }
    return dp[i] = 1 + l;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    dp = vector<int>(n + 1, -1);
    adj = vector<vector<int>>(n + 1);
    for (int i = 0; i < m; i++)
    {
        int k, j;
        cin >> k >> j;
        adj[k].push_back(j);
    }

    int mx = 0;
    for (int i = 1; i < n + 1; i++)
    {
        int k = longestPath(i);
        mx = max(mx, k);
    }
    cout << mx - 1;
}

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif

    solve();

#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}