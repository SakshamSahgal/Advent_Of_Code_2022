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
    freopen("input1.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
    string s;
    map<lli,stack<char>> crates;
    vector<string> stacks;
    stacks.push_back("QFMRLWCV");
    stacks.push_back("DQL");
    stacks.push_back("PSRGWCNB");
    stacks.push_back("LCDHBQG");
    stacks.push_back("VGLFZS");
    stacks.push_back("DGNP");
    stacks.push_back("DZPVFCW");
    stacks.push_back("CPDMS");
    stacks.push_back("ZNWTVMPC");

    for(int i=0;i<stacks.size();i++)
    {
        for(auto j:stacks[i])
            crates[i+1].push(j);
    }

    while(getline(cin,s))
    {
        if(s[0] == 'm')
        {
            vector<string> cmd = split(s,' ');
            lli no = stoi(cmd[1]);
            lli from = stoi(cmd[3]);
            lli to = stoi(cmd[5]);
            stack<char> z;
            while(no--)
            {
                z.push(crates[from].top());
                crates[from].pop();
            }
            while(!z.empty())
            {
                crates[to].push(z.top());
                z.pop();
            }
        }
    }

    for(auto i:crates)
        cout<<i.second.top();

    return 0;
}


