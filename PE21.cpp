#include <bits/stdc++.h>
#define lli long long int
#define ii pair<lli, lli>
#define mxN (lli)(5e3 + 5)
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define accDeci    \
    cout << fixed; \
    cout << setprecision(15);
#define pb push_back
#define INF (lli)1e18
#define mod 998244353
#define X first
#define Y second
using namespace std;

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

void solve()
{
    // brute-force takes O(maxN) time, fast enough to not wait for 2 hours
    lli maxN = 30000;        // a[10k] ~25k, so 30k is a safe bound
    vector<lli> a(maxN + 1); // records sum of proper divisors

    for (int i = 1; i <= maxN; i++)
    {
        vector<lli> fact; // factors
        for (int j = 1; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                fact.pb(j);
                if (i / j != j)
                    fact.pb(i / j);
            }
        }

        sort(fact.begin(), fact.end());
        lli sum = 0;
        for (auto ele : fact)
            sum += ele;
        sum -= i;
        a[i] = sum;
    }

    lli ans = 0;

    for (int i = 1; i < 10000; i++)
    {
        if (i == a[a[i]] && i != a[i]) // exclude cases like i=a[i]=a[a[i]]=28
            ans += i;
    }

    cout << ans << "\n";
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