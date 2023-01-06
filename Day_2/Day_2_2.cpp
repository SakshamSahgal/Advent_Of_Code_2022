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

vector<string> split(string &s)
{
    vector<string> v;
    string temp;
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == ' ')
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
    map<string,lli> points;
    map<string,string> loose;
    map<string,string> win;
    points["X"] = 1;
    points["Y"] = 2;
    points["Z"] = 3;
    loose["A"] = "Z";
    loose["B"] = "X";
    loose["C"] = "Y";
    win["A"] = "Y";
    win["B"] = "Z";
    win["C"] = "X";

    lli sum=0;
    string s;
    while(getline(cin,s))
    {
        vector<string> th = split(s);
        lli score = 0;
        string will_choose;
        if(th[1] == "X") //LOOSE
            score = points[loose[th[0]]];
        else if(th[1] == "Y") //draw
        {
            will_choose = ('X' + (th[0][0] - 'A'));
            score = 3 + points[will_choose];
        }
        else
            score = 6 + points[win[th[0]]];
        cout<<th[0]<<" "<<th[1]<<" "<<score<<"\n";
        sum += score;
    }
    cout<<sum<<"\n";
    return 0;
}

