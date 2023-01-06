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

map<stack<string>,vector<pair<string,string>>> dir; //path , {size,name} or {dir,name}


map<stack<string>,lli> dp;


lli size_calc(stack<string> refrence)
{
    if(dp.count(refrence))
        return dp[refrence];

    lli sz = 0;
    for(auto i:dir[refrence])
    {
        if(i.first == "dir")
        {
            stack<string> cur_path = refrence;
            cur_path.push(i.second);
            sz += size_calc(cur_path);
        }
        else
            sz += (lli)stoi(i.first);
    }
     dp[refrence] = sz;
    return sz;
}

void stack_printer(stack<string> st)
{
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}

int main()
{
    GO_FAST
    freopen("input.txt", "r", stdin);
    freopen("myout.txt", "w", stdout);
    string s;
    stack<string> cur_dir;
    map<stack<string>,lli> sizes;
    vector<lli> siz;
    while(getline(cin,s))
    {
        vector<string> z = split(s,' ');
        if(z[0] == "$")
        {
            if(z[1] == "cd")
            {
                if(z[2] == "..")
                    cur_dir.pop();
                else
                    cur_dir.push(z[2]);
            }
        }
        else
            dir[cur_dir].push_back({z[0],z[1]}); //size , name OR //dir , name
    }

    for(auto i:dir)
    {
        cout<<"{ ";
        stack_printer(i.first);
        cout<<"} -> ";
        for(auto j:i.second)
            cout<<"{"<<j.first<<" "<<j.second<<"} ";
        cout<<"\n";
    }


    lli sum=0;

    for(auto i:dir)
    {
        lli sz = size_calc(i.first);
        cout<<"size of {";
        stack_printer(i.first);
        cout<<" } = "<<sz<<"\n";
        sizes[i.first] = sz;
        siz.push_back(sz);
        if(sz <= 100000)
            sum += sz;
    }
    sort(siz.begin(),siz.end());
    stack<string> temp;
    temp.push("/");
    cout<<"Total = "<<sizes[temp]<<"\n";
    cout<<"Unused = "<<70000000 - sizes[temp]<<"\n";
    lli req = 30000000 - (70000000 - sizes[temp]);
    cout<<"req space = "<<req<<"\n";

    auto ptr = lower_bound(siz.begin(),siz.end(),req);

    line_printer(20);
    for(auto i:siz)
        cout<<i<<" ";
    cout<<"\n";

    cout<<"smallest to delete = "<<(*ptr)<<"\n";


    cout<<sum<<"\n";
    return 0;
}


