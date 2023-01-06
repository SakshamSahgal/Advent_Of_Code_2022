#include<bits/stdc++.h>
#define lli long long int
#define ld long double
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;
typedef pair<lli,lli> pll;

vector<string> split(string &s,char with)
{
    vector<string> v;
    string temp;
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == with)
        {
            v.push_back(temp);
            temp = "";
        }
        else
            temp += s[i];
    }
    v.push_back(temp);
    return v;
}

void vector_printer( vector<string> v)
{
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n";
}

int main()
{
    GO_FAST
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
    string s;
    lli ans=0;
    while(getline(cin,s))
    {
        vector<string> z = split(s,',');
        vector<string> a = split(z[0],'-');
        vector<string> b = split(z[1],'-');
        for(auto i:a)
            cout<<i<<" ";
        for(auto i:b)
            cout<<i<<" ";

        lli l1 = stoi(a[0]);
        lli r1 = stoi(a[1]);
        lli l2 = stoi(b[0]);
        lli r2 = stoi(b[1]);
        if( (l1 <= l2 && r2 <= r1) || (l2 <= l1 && r1 <= r2) )
            ans++;
        cout<<"\n";
    }
    cout<<ans<<"\n";
    return 0;
}

