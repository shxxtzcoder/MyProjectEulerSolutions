#include <bits/stdc++.h>
// #include <atcoder/modint>
// #include <atcoder/fenwicktree>
#define lli long long int
#define ii pair<lli, lli>
#define mxN (lli)(1e5 + 5)
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define accDeci    \
    cout << fixed; \
    cout << setprecision(15);
#define pb push_back
#define INF (lli)1e18
#define X first
#define Y second
#define countSetBits(x) __builtin_popcount(x)
#define countSetBitsLL(x) __builtin_popcountll(x)
#define firstSetLSB(x) (__builtin_ffs(x) - 1)
#define firstSetMSB(x) (__lg(x))
#define countLeadingZeroes(x) __builtin_clz(x)
#define countTrailingZeroes(x) __builtin_ctz(x)
#define MOD 1000000007
#define mod 998244353

using namespace std;
#define inf INF

//(raise(a,b) = a^b)
long long raise(long long a, long long b)
{
    long long res = 1;
    for (int i = 0; i < b; i++)
    {
        if (inf / res < a)
            return 0;
        res *= a;
    }
    return res;
}

bool check_Pal(string s)
{
    string r=s;
    reverse(r.begin(),r.end());
    return (s==r);
}

void solve()
{
    //loop and check ~1e6 operations won't take that much

    lli ans=0;

    for(lli i=1;i<=(lli)(1e6);i++)
    {
        string s=to_string(i);

        std::string binary = std::bitset<60>(i).to_string();
        reverse(binary.begin(),binary.end());
        while((*binary.rbegin())=='0')
            binary.pop_back();
        reverse(binary.begin(),binary.end());

        if(check_Pal(binary) && check_Pal(s))
            ans+=i;
    }

    cout<<ans<<"\n";
}

int main(void)
{
    fastIO;
    accDeci;
    lli T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    };
    return 0;
}