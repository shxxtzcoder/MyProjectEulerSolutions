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
    // might have solved this question in less time had I not been so badly infatuated with a certain girl to read up articles on interfaith marriage :P
    // wish i could rant about the whole affair here

    // proved that x has to be odd, wrote a brute-force to get a sequence and found it on OEIS: https://oeis.org/A120893; got an AC while not being sure how it works
    // did some reading later after it got an AC : These values come from solving a Pell-type equation that emerges when enforcing the area to be an integer

    //Here's what this research led to:-
    //Problem essentially reduces to:
    // Solve for all integer x such that either:
    //    (1) 3x^2 + 2x - 1 = y^2    or
    //    (2) 3x^2 - 2x - 1 = y^2
    //
    // Both equations reduce to the same Pell-type equation (multiply by 3 and complete the square):
    //    U^2 - 3y^2 = 4
    //
    // Let U = 3x + 1 for Equation (1)     => x = (U - 1)/3
    // Let U = 3x - 1 for Equation (2)     => x = (U + 1)/3
    //
    // The fundamental unit of this Pell-type is (2 + √3)
    // All solutions are given by:
    //    U_n + y_n√3 = (2 + √3)^n        for n = 0, 1, 2, ...
    //
    // This gives U_n = (2 + √3)^n + (2 - √3)^n
    // From this, x is computed depending on U_n mod 3:
    //
    //    if U_n ≡ 1 mod 3:  x_n = (U_n - 1)/3    --> from Eq (1)
    //    if U_n ≡ -1 mod 3: x_n = (U_n + 1)/3    --> from Eq (2)
    //
    // This interleaves to a single sequence of x-values:
    //    a_0 = 1, a_1 = 1, a_2 = 5, a_3 = 17, a_4 = 65, ...
    //
    // Recurrence relation for x-values:
    //    a_n = 3*a_{n-1} + 3*a_{n-2} - a_{n-3}, for n >= 3
    //
    // Optional closed-form (Binet-like) expression:
    //    a_n = ((2 + √3)^n + (2 - √3)^n + (-1)^n) / 6

    //One can do some reading on https://en.wikipedia.org/wiki/Pell%27s_equation for the exact algorithm to solve this

    lli x = 1, y = 1, z = 5, peri = 16, ans = 0;
    bool flag = 1; // 0 -> first "branch"; 1 -> second "branch"

    lli MAX_PERI = 1e9;

    while (peri < MAX_PERI)
    {
        ans += peri;
        lli new_z = 3 * z + 3 * y - x;
        x = y, y = z, z = new_z;
        lli new_peri = -1;
        
        if(flag)
            new_peri = 3*z -1;
        else
            new_peri = 3*z + 1;
        
        // cout << z <<"\n";

        peri = new_peri;
            
        flag^=1;
    }

    cout << ans <<"\n";
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