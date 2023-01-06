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
    vector<string> v;
    while(getline(cin,s))
        v.push_back(s);

    lli n = v.size();
    lli m = v[0].size();
    vector<vector<lli>> z(n,vector<lli>(m,0));

    for(int i=0; i<n; i++) //left
    {
        z[i][0] += 1;
        char maxx = v[i][0];
        for(int j=1; j<m; j++)
        {
            if(maxx < v[i][j])
                z[i][j] += 1;
            maxx = max(maxx,v[i][j]);
        }
    }

    for(int j=0; j<m; j++) //top
    {
        z[0][j] += 1;
        char maxx = v[0][j];
        for(int i=1; i<n; i++)
        {
            if(maxx < v[i][j])
                z[i][j] += 1;
            maxx = max(maxx,v[i][j]);
        }
    }

    for(int i=0; i<n; i++) //right
    {
        z[i][m-1]+=1;
        char maxx = v[i][m-1];
        for(int j=m-2; j>=0; j--)
        {
            if(v[i][j] > maxx)
                z[i][j] += 1;
            maxx = max(maxx,v[i][j]);
        }
    }

    for(int j=0; j<m; j++) //Down
    {
        z[n-1][j] += 1;
        char maxx = v[n-1][j];
        for(int i=n-2; i>=0; i--)
        {
            if(v[i][j] > maxx)
                z[i][j] += 1;
            maxx = max(maxx,v[i][j]);
        }
    }
    lli number_of_trees=0;
    for(auto i:z)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
            number_of_trees += (j != 0);
        }
        cout<<"\n";
    }
    cout<<number_of_trees<<"\n";
    return 0;
}
