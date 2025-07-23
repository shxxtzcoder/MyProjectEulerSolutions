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
#define INF (lli)(1e18)
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
// using namespace atcoder;
// using modint = atcoder::static_modint<998244353>;

/*
Debugging Printers:
*/

void print(int t) { cout << t; }
void print(string t) { cout << t; }
void print(char t) { cout << t; }
void print(double t) { cout << t; }
void print(lli t) { cout << t; }
template <class T, class V>
void print(pair<T, V> p);
template <class T>
void print(vector<T> v);
template <class T>
void print(set<T> v);
template <class T, class V>
void print(map<T, V> v);
template <class T>
void print(multiset<T> v);
template <class T, class V>
void print(pair<T, V> p)
{
    cout << "{";
    print(p.first);
    cout << ",";
    print(p.second);
    cout << "}";
}
template <class T>
void print(vector<T> v)
{
    cout << "[ ";
    for (T i : v)
    {
        print(i);
        cout << " ";
    }
    cout << "]\n";
}
template <class T>
void print(set<T> v)
{
    cout << "[ ";
    for (T i : v)
    {
        print(i);
        cout << " ";
    }
    cout << "]\n";
}
template <class T>
void print(multiset<T> v)
{
    cout << "[ ";
    for (T i : v)
    {
        print(i);
        cout << " ";
    }
    cout << "]\n";
}
template <class T, class V>
void print(map<T, V> v)
{
    cout << "[ ";
    for (auto i : v)
    {
        print(i);
        cout << " ";
    }
    cout << "]\n";
}
/* ////////*/

// DSU dsu(n+1);
class DSU
{
public:
    int n;
    // p is parents vector, sz is size vector
    vector<int> p, sz;

    // constructor initializing DSU object with given number of elements '_n'
    DSU(int _n) : n(_n)
    {
        p.resize(n);
        iota(p.begin(), p.end(), 0); // p vector is now: 0 1 2 3 4 ... n-1
        // so effectively intializing each element as its own parent
        sz.resize(n, 1);
    }

    int find(int x)
    {
        if (x == p[x])
            return x;
        return p[x] = find(p[x]);
    }

    bool merge(int a, int b)
    { // returns false if a cycle will get created; returns true if normal merge took place.
        int c = find(a);
        int d = find(b);
        if (d != c)
        {
            if (sz[c] < sz[d])
                swap(c, d);

            p[d] = c;
            sz[c] += sz[d];
            return true;
        }
        else
        {
            // you made a cycle by including this edge a-b.
            return false;
        }
    }

    bool same(int x, int y)
    {
        return find(x) == find(y);
    }

    int size(int x)
    {
        return sz[find(x)];
    }

    vector<vector<int>> groups()
    {
        int n = p.size();
        vector<vector<int>> group(n);
        for (int i = 0; i < n; ++i)
        {
            group[find(i)].push_back(i);
        }
        group.erase(remove_if(group.begin(), group.end(), [](const vector<int> &g)
                              { return g.empty(); }),
                    group.end());
        return group;
    }
};

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

lli ceil(lli a, lli b)
{
    return (a + b - 1) / b;
}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

long long sqroot(long long a)
{
    long long b = (long long)sqrtl(a);
    if ((b + 1) * (b + 1) == a)
    {
        b++;
    }
    return b;
}

lli binExp(lli a, lli b, lli p)
{
    a %= p;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = res * a % p;
        }
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

lli fact[mxN], inv[mxN];

void pre(lli p)
{
    fact[0] = 1;
    inv[0] = 1;
    for (int i = 1; i < mxN; i++)
        fact[i] = (i * fact[i - 1]) % p;
    for (int i = 1; i < mxN; i++)
        inv[i] = binExp(fact[i], p - 2, p);
}

lli nCr(lli n, lli r, lli p)
{
    if (r > n || r < 0)
        return 0;
    if (n == r)
        return 1;
    if (r == 0)
        return 1;
    return (((fact[n] * inv[r]) % p) * inv[n - r]) % p;
}

void solve()
{
    // was doing it by hand then got lazy; CONSTRAINTS ARE SMALL ENOUGH FOR BRUTEFORCE IG

    //check if power of 10
    auto isPow10 = [&](lli num) -> bool
    {
        while(num >= 10)
        {
            if(num % 10 != 0)
                return false;
            num/=10;
        }

        return num == 1;
    };

    int cnt = 0, curr = 0;
    while(cnt <= 1e6)
    {
        curr ++;
        string s = to_string(curr);
        for(int i = 0; i < s.size(); i++)
        {
            cnt++;
            if(isPow10(cnt))
                cout << s[i] <<"\n";
        }
    }
}

int main(void)
{
    fastIO;
    accDeci;
    // pre(MOD);

    lli T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    };
    return 0;
}