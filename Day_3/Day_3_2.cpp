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
    //GO_FAST
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
    string s;
    map<char,lli> lower_p;
    map<char,lli> upper_p;
    lli ans=0;
    lli j=1;
    for(char i='a';i<='z';i++)
        lower_p[i] = j++;

    for(char i='A';i<='Z';i++)
        upper_p[i] = j++;

    int c=0;
    vector<string> v;
    while(getline(cin,s))
    {
        cout<<s<<"\n";
        v.push_back(s);
        c = (c+1)%3;
        if(c == 0)
        {
            char badge;
            for(char i='a';i<='z';i++)
            {
                bool found=1;
                for(int j=0;j<3;j++)
                {
                    if((v[j].find(i) == string::npos))
                    {
                        found=0;
                        break;
                    }
                }

                if(found)
                {
                    badge = i;
                    break;
                }
            }

            for(char i = 'A';i<='Z';i++)
            {
                bool found=1;
                for(int j=0;j<3;j++)
                {
                    if((v[j].find(i) == string::npos))
                    {
                        found=0;
                        break;
                    }
                }

                if(found)
                {
                    badge = i;
                    break;
                }
            }
            cout<<"found = "<<badge<<"\n";
            ans += lower_p[badge] + upper_p[badge];
            v.clear();
        }

    }

    cout<<ans<<"\n";
    return 0;
}

