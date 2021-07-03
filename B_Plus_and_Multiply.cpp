#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define endl "\n"
#define test                 \
    ios::sync_with_stdio(0); \
    cin.tie(NULL);           \
    std::cout.tie(NULL);
#define endl "\n"
#define vst vector<char>
#define vll vector<ll>
#define fo(i, x, y) for (__typeof(x) i = x; i <= y; ++i)
#define fr(i, x, y) for (__typeof(x) i = x; i >= y; i--)
#define all(x) x.begin(), x.end()
#define vpr vector<pair<ll, ll>>
#define gcd(a, b) __gcd(a, b)
#define ans   \
    ll t;     \
    cin >> t; \
    while (t--)
#define F first
#define S second
const ll N = 1e9 + 7;
const ll MAX = 1e5;
ll n, a, b;
int main()
{
    test;
    ans
    {

               cin >> n >> a >> b;
        ll f = 0;

        for (int i = 0; i < 1000; i++)
        {

            ll po = pow(a, i);
            if (po > n)
                break;
            ll val = n - po;
            if (val % b == 0)
            {
                f = 1;
                break;
            }
        }
        if (f == 1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}