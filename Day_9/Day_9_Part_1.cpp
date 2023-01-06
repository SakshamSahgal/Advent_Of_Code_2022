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
    for(int i=0; i<s.length(); i++)
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

pll new_coordinates(string dir,pll pos)
{
    if(dir == "R")
        pos.first++;
    else if(dir == "L")
        pos.first--;
    else if(dir == "D")
        pos.second--;
    else
        pos.second++;
    return pos;
}

int main()
{
    //GO_FAST
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
    pll tp = {0,0};
    pll hp = {0,0};
    set<pll> dist_pos;
    dist_pos.insert({0,0});
    string s;
    while(getline(cin,s))
    {
        vector<string> lines = split(s,' ');
        vector_printer(lines);
        lli times = stoi(lines[1]);
        cout<<"times = "<<times<<"\n";
        while(times--)
        {
            if(tp == hp)
                hp = new_coordinates(lines[0],hp);
            else
            {
                if(lines[0] == "R" && tp.first == hp.first - 1)
                    tp = hp;
                else if(lines[0] == "L" && tp.first == hp.first + 1)
                    tp = hp;
                else if(lines[0] == "D" && tp.second == hp.second + 1)
                    tp = hp;
                else if(lines[0] == "U" && tp.second == hp.second - 1)
                    tp = hp;
                hp = new_coordinates(lines[0],hp);
            }
            cout<<"tp now = {"<<tp.first<<" "<<tp.second<<"} hp = {"<<hp.first<<" "<<hp.second<<"} \n";
            dist_pos.insert(tp);
        }
    }

    cout<<"no of distinct pos = "<<dist_pos.size()<<"\n";
    return 0;
}

