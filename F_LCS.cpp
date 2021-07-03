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
int n, m;
vector<vector<int>> dp;
int lcs(int i, int j, string &s, string &t)
{
    if (i >= n || j >= m)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == t[j])
    {
        return dp[i][j] = 1 + lcs(i + 1, j + 1, s, t);
    }
    else
    {
        int ans1 = lcs(i + 1, j, s, t);
        int ans2 = lcs(i, j + 1, s, t);
        return dp[i][j] = max(ans1, ans2);
    }
}
void solve()
{

    string s, t;
    cin >> s >> t;
    string str = "";
    n = s.length();
    m = t.length();
    dp = vector<vector<int>>(n, vector<int>(m, -1));
    lcs(0, 0, s, t);
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (s[i] == t[j])
        {
            str += s[i];
            i++;
            j++;
        }
        else
        {
            if (i < n - 1 && j < m - 1)
            {
                if (dp[i + 1][j] > dp[i][j + 1])
                    i++;
                else
                {
                    j++;
                }
            }
            else if (i < n - 1)
            {
                i++;
            }
            else if (j < m - 1)
            {
                j++;
            }
            else
                i++, j++;
        }
    }
    cout << str;
}

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    // int t;
    // scanf("%d", &t);
    // while (t--)
    // {
    solve();
    //     cout << "\n";
    // }
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}