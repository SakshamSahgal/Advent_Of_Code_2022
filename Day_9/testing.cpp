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


pll move_it(string dir,pll pos)
{
    if(dir.find("R") != string::npos)
        pos.first++;
    if(dir.find("L") != string::npos)
        pos.first--;
    if(dir.find("D") != string::npos)
        pos.second--;
    if((dir.find("U") != string::npos))
        pos.second++;
    return pos;
}

void print(pll x)
{
    cout<<"{"<<x.first<<" "<<x.second<<"}\n";
}

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    pll x = {0,0};
    x = move_it("NA",x);
    print(x);
    return 0;
}

