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
    //take i/p and tokenize wrt ","
    ifstream iFile; // Input file
    iFile.open("PE22_data.txt");

    //Read the contents of the file
    string input;
    getline(iFile,input);
    iFile.close();

    //Create a string stream from the input string
    stringstream ss(input);
    string item;
    vector<string> s;

    while(getline(ss,item,','))
    {
        // Remove any extra whitespace from the item
        item.erase(0, item.find_first_not_of(' ')); // Trim leading spaces
        item.erase(item.find_last_not_of(' ') + 1); // Trim trailing spaces
        s.push_back(item);
    } 

    lli n=s.size();
    lli ans=0;

    sort(s.begin(),s.end());

    for(int i=0;i<n;i++)
    {
        lli val=0;
        for(auto& ele:s[i]) 
        if(ele!='\"') val+=(ele-'A'+1);
        ans+=((i+1)*val);
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