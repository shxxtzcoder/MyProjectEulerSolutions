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
    //easy brute force
    lli maxN=(lli)1e6;

    lli hi=0,num=0;

    for(lli i=1;i<=maxN;i++)
    {
        lli n=i,cnt=1;
        while(n!=1)
        {
            if(n%2) n*=3,n++;
            else n/=2;
            cnt++;
        }

        if(cnt>hi) hi=cnt,num=i;
    }

    cout<<num<<"\n";
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