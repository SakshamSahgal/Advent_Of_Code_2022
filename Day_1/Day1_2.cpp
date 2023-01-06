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
    //GO_FAST
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
    string s;
    lli sum=0;
    lli ans=0;
    priority_queue<lli> pq; //max heap
    while(getline(cin,s))
    {
        vector<string> thv = split(s);
        vector_printer(thv);
        if(s.length() == 0)
        {
            cout<<"sum = "<<sum<<"\n";
            pq.push(sum);
            sum = 0;
        }
        else
            sum += stoi(thv[0]);
    }
    cout<<"sum = "<<sum<<"\n";

    pq.push(sum);

    for(int i=0;i<3;i++)
    {
        ans += pq.top();
        cout<<"max "<<i+1<<" = "<<pq.top()<<"\n";
        pq.pop();
    }

    cout<<"sum of max three = "<<ans<<"\n";
    return 0;
}

