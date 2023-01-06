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


int main()
{
    GO_FAST
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
    string s;
    map<char,lli> lower_p;
    map<char,lli> upper_p;

    lli j=1;
    for(char i='a';i<='z';i++)
        lower_p[i] = j++;

    for(char i='A';i<='Z';i++)
        upper_p[i] = j++;

    lli ans=0;
    while(getline(cin,s))
    {
        set<char> fh;
        set<char> sh;
        int i=0;
        while(i<s.length()/2)
            fh.insert(s[i++]);
        while(i<s.length())
            sh.insert(s[i++]);

        for(auto i:fh)
            ans += (sh.count(i)) ? (lower_p[i] + upper_p[i]): 0;
    }
    cout<<ans<<"\n";
    return 0;
}
