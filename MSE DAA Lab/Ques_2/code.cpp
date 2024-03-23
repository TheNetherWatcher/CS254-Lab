/*



⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣴⣶⣿⣿⣷⣶⣄⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣾⣿⣿⡿⢿⣿⣿⣿⣿⣿⣿⣿⣷⣦⡀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢀⣾⣿⣿⡟⠁⣰⣿⣿⣿⡿⠿⠻⠿⣿⣿⣿⣿⣧⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⠏⠀⣴⣿⣿⣿⠉⠀⠀⠀⠀⠀⠈⢻⣿⣿⣇⠀⠀⠀
⠀⠀⠀⠀⢀⣠⣼⣿⣿⡏⠀⢠⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀⠈⣿⣿⣿⡀⠀⠀
⠀⠀⠀⣰⣿⣿⣿⣿⣿⡇⠀⢸⣿⣿⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⡇⠀⠀
⠀⠀⢰⣿⣿⡿⣿⣿⣿⡇⠀⠘⣿⣿⣿⣧⠀⠀⠀⠀⠀⠀⢀⣸⣿⣿⣿⠁⠀⠀
⠀⠀⣿⣿⣿⠁⣿⣿⣿⡇⠀⠀⠻⣿⣿⣿⣷⣶⣶⣶⣶⣶⣿⣿⣿⣿⠃⠀⠀⠀
⠀⢰⣿⣿⡇⠀⣿⣿⣿⠀⠀⠀⠀⠈⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠁⠀⠀⠀⠀
⠀⢸⣿⣿⡇⠀⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠉⠛⠛⠛⠉⢉⣿⣿⠀⠀⠀⠀⠀⠀
⠀⢸⣿⣿⣇⠀⣿⣿⣿⠀⠀⠀⠀⠀⢀⣤⣤⣤⡀⠀⠀⢸⣿⣿⣿⣷⣦⠀⠀⠀
⠀⠀⢻⣿⣿⣶⣿⣿⣿⠀⠀⠀⠀⠀⠈⠻⣿⣿⣿⣦⡀⠀⠉⠉⠻⣿⣿⡇⠀⠀
⠀⠀⠀⠛⠿⣿⣿⣿⣿⣷⣤⡀⠀⠀⠀⠀⠈⠹⣿⣿⣇⣀⠀⣠⣾⣿⣿⡇⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⣿⣿⣦⣤⣤⣤⣤⣾⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀ 
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠻⢿⣿⣿⣿⣿⣿⣿⠿⠋⠉⠛⠋⠉⠉⠁⠀⠀



*/


#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define ll long long
#define ulli unsigned long long int
#define ull unsigned long long
#define rp(a, b, c) for(long long a = b; i < b + c; a++)
#define out(a) cout<<a<<endl
#define in(a) cin>>a
#define all(x) (x).begin(), (x).end()
#define fr(a, b) for(long long i = a; i < b; i++)
#define mod 1000000007
#define pb push_back 
// const ll long long inf=9223372036854775807;
#define mxe(v)  *max_element(v.begin(),v.end())     // find max element in vector
#define mne(v)  *min_element(v.begin(),v.end())     // find min element in vector
#define vi vector<long long>
#define sva(v) sort(all(v))
#define sz(x) long long((x).size())
const lli N=10e6+10;
// use incase of input and output file
// freopen(input.txt,r,stdin);
// freopen(output.txt,w,stdout);

long long f1(long long x, long long m){
    if(x<=m) return x*x;
    else return -x*x;
}

long long f2(long long x, long long m){
    if(x<=m) return pow(3,x);
    else return -pow(3,x);
}

void solve()
{
    long long n,m; in(n>>m);
    long long low=0, high=n, mid, ans=0;
    int choice;
    out("Enter 1 for function 1 or 2 for function 2: "); in(choice);
    if(choice==1){
        while(low<=high){
            mid = low + (high-low)/2;
            if(f1(mid,m)>f1(mid+1,m)){
                high=mid-1;
                ans=mid;
            } else if(f1(mid,m)<=f1(mid+1,m)){
                low=mid+1;
                ans=mid+1;
            }
        }
        out("Maximum value "<<f1(ans,m)<<" occurs at "<<ans);
    }
    else{
        while(low<=high){
            mid = low + (high-low)/2;
            if(f2(mid,m)>f2(mid+1,m)){
                high=mid-1;
                ans=mid;
            } else if(f2(mid,m)<=f2(mid+1,m)){
                low=mid+1;
                ans=mid+1;
            }
        }
        out("Maximum value "<<f2(ans,m)<<" occurs at "<<ans);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
}