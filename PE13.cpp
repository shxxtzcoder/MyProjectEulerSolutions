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
    lli n=100; // number of numbers
    lli d=50; //number of digits in each number, if unequal take max and pad others with leading zeroes
    // simulate kindergarten addition
    // read string data from a file
    ifstream iFile; // Input file
    iFile.open("PE13_data.txt");

    string line;

    vector<string> s;

    while(getline(iFile,line))  s.pb(line);

    vector<vector<lli>> a(n);
    for(int i=0;i<n;i++)
        for(int j=d-1;j>=0;j--) a[i].pb(s[i][j]-'0');

    vector<lli> ans;

    //read number stored at each index from R to L, that's the MSB to LSB order for this implementation

    lli rem=0;

    for(int i=0;i<d;i++)
    {
        for(int j=0;j<n;j++) rem+=a[j][i];

        ans.pb(rem%10);
        rem/=10;
    }

    while(rem!=0) ans.pb(rem%10),rem/=10;

    reverse(ans.begin(),ans.end());

    for(auto ele:ans) cout<<ele;

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