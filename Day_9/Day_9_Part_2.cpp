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



int main()
{
    //GO_FAST
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
    lli length = 10;
    vector<pll> rope(length, {0,0});
    set<pll> dist_pos;
    dist_pos.insert({0,0});
    string s;
    while(getline(cin,s))
    {
        vector<string> lines = split(s,' ');
        vector_printer(lines);
        lli times = stoi(lines[1]);
        cout<<"times = "<<times<<"\n";
        vector<string> moves(10);
        moves[length-1] = lines[0]; //head
        while(times--)
        {
            for(int i=length-2; i>=0; i--)
            {
                if(rope[i] == rope[i+1])
                    moves[i] = "NA";
                else
                {
                    if(moves[i+1] == "R")
                    {
                        if(move_it("R",rope[i]) == rope[i+1])
                            moves[i] = "R";
                        else if(move_it("DR",rope[i]) == rope[i+1])
                            moves[i] = "DR";
                        else if(move_it("UR",rope[i]) == rope[i+1])
                            moves[i] = "UR";
                    }
                    else if(moves[i+1] == "D")
                    {
                        if(move_it("D",rope[i]) == rope[i+1])
                            moves[i] = "D";
                        else if(move_it("DR",rope[i]) == rope[i+1])
                            moves[i] = "DR";
                        else if(move_it("DL",rope[i]) == rope[i+1])
                            moves[i] = "DL";
                    }
                    else if(moves[i+1] == "U")
                    {
                        if(move_it("U",rope[i]) == rope[i+1])
                            moves[i] = "U";
                        else if(move_it("UR",rope[i]) == rope[i+1])
                            moves[i] = "UR";
                        else if(move_it("UL",rope[i]) == rope[i+1])
                            moves[i] = "UL";
                    }
                    else if(moves[i+1] == "L")
                    {
                        if(move_it("L",rope[i]) == rope[i+1])
                            moves[i] = "L";
                        else if(move_it("DL",rope[i]) == rope[i+1])
                            moves[i] = "DL";
                        else if(move_it("UL",rope[i]) == rope[i+1])
                            moves[i] = "UL";
                    }
                    else if(moves[i+1] == "UR" || moves[i+1] == "RU")
                    {
                        if( move_it("R",rope[i]) == rope[i+1] || move_it("U",rope[i]) == rope[i+1] ||  move_it("UR",rope[i]) == rope[i+1] )
                            moves[i] = "UR";
                        else if(move_it("RD",rope[i]) == rope[i+1])
                            moves[i] = "R";
                        else if(move_it("LU",rope[i]) == rope[i+1])
                            moves[i] = "U";
                    }
                    else if(moves[i+1] == "LU" || moves[i+1] == "UL")
                    {
                        if( move_it("L",rope[i]) == rope[i+1] || move_it("U",rope[i]) == rope[i+1] ||  move_it("UL",rope[i]) == rope[i+1] )
                            moves[i] = "UL";
                        else if(move_it("UR",rope[i]) == rope[i+1])
                            moves[i] = "U";
                        else if(move_it("LD",rope[i]) == rope[i+1])
                            moves[i] = "L";
                    }
                    else if(moves[i+1] == "DR" || moves[i+1] == "RD")
                    {
                        if( move_it("D",rope[i]) == rope[i+1] || move_it("R",rope[i]) == rope[i+1] ||  move_it("DR",rope[i]) == rope[i+1] )
                            moves[i] = "DR";
                        else if(move_it("UR",rope[i]) == rope[i+1])
                            moves[i] = "R";
                        else if(move_it("LD",rope[i]) == rope[i+1])
                            moves[i] = "D";
                    }
                    else if(moves[i+1] == "DL" || moves[i+1] == "LD")
                    {
                        if( move_it("D",rope[i]) == rope[i+1] || move_it("L",rope[i]) == rope[i+1] ||  move_it("DL",rope[i]) == rope[i+1] )
                            moves[i] = "DL";
                        else if(move_it("DR",rope[i]) == rope[i+1])
                            moves[i] = "D";
                        else if(move_it("LU",rope[i]) == rope[i+1])
                            moves[i] = "L";
                    }
                    else
                        moves[i] = "NA";
                }
            }

            for(auto i:moves)
                cout<<i<<" ";
            cout<<"\n";
            for(int i=0; i<length; i++)
                rope[i] = move_it(moves[i],rope[i]);
            cout<<"tp now = {"<<rope[0].first<<" "<<rope[0].second<<"} hp = {"<<rope[length-1].first<<" "<<rope[length-1].second<<"} \n";
            dist_pos.insert({rope[0]});
        }
    }

    cout<<"no of distinct pos = "<<dist_pos.size()<<"\n";

    vector<vector<char>> vis(100,vector<char>(100,'.'));

    for(auto i:dist_pos)
        vis[i.first+30][i.second+30] = '#';

    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
            cout<<vis[i][j]<<" ";
        cout<<"\n";
    }


    return 0;
}

