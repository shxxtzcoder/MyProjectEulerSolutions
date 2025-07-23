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

int maxN=30000;
int is_prime[30001];
vector<lli> primes;


void sieve()
{

    for(int i=1;i<=maxN;i++)
    {
        is_prime[i]=1;
    }
    is_prime[0]=0;
    is_prime[1]=0;

    for(int i=2;i*i<=maxN;i++)
    {
        if(is_prime[i])
        {
            for(int j=i*i;j<=maxN;j+=i)
            {
                is_prime[j]=0;
            }
        }
    }
    
    for(int i = 2; i <= maxN; i++)
    if(is_prime[i])
    primes.pb(i);
}

bool isPrime(int x)
{
    if(binary_search(primes.begin(), primes.end(), x))
        return true;

    for(int i = 2; i * i <=x ; i++)
        if(x % i == 0)
            return false;

    return true;
}

void solve()
{
    //bs bruteforce - shittiest implementation based problem on this platform
    //i was lucky to get an answer <30k when restricting maxN to 30k else we couldn't have been sure of the ans- suppose ans was some large number let's say 69k or something - then changing maxN might have caused this code to find some tuple like {vs1, vs2, vs3, vs4, L} where vs1 + ... + vs4 + L < curr_ans and L > 30k and vs1...4 are "very small" nos.

    auto matches = [&](int i, int j) -> bool
    {
        string strI = to_string(i);
        string strJ = to_string(j);
        string strA = strI + strJ;
        string strB = strJ + strI;
        lli numA = atoll(strA.c_str());
        lli numB = atoll(strB.c_str());

        return (isPrime(numA) && isPrime(numB));
    };
    
    vector<int> a;
    set<int> primeSet;

    vector<int> possible;

    for(auto prime: primes)
    {
        primeSet.clear();

        for(auto i : primes)
        {
            if (i < prime)
                continue;

            if(primeSet.size() > 0)
            {
                bool matching = true;
                for(auto iter: primeSet)
                {
                    if(!matches(i, iter))
                    {
                        matching = false;
                        break;
                    }
                }
                if(matching)
                {
                    primeSet.insert(i);
                    if(primeSet.size() >= 5)
                        break;
                }
            }
            else
            {
                for(auto iter: primes)
                {
                    if(iter < i && matches(i, iter))
                    {
                        primeSet.insert(i);
                        primeSet.insert(iter);
                        break;
                    }
                }
            }
        }

        if(primeSet.size() == 5)
        {
            lli ans = 0;
            for(auto val : primeSet)
                ans+=val;
            
            possible.push_back(ans);
        }
    }
    sort(possible.begin(), possible.end());
    print(possible[0]);
}

int main(void)
{
    fastIO;
    accDeci;
    // pre(MOD);
    sieve();

    lli T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    };
    return 0;
}