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
#define rp(a, b, c) for(int a = b; i < b + c; a++)
#define out(a) cout<<a<<endl
#define in(a) cin>>a
#define all(x) (x).begin(), (x).end()
#define fr(a, b) for(int i = a; i < b; i++)
#define mod 1000000007
#define pb push_back 
const ll int inf=9223372036854775807;
#define mxe(v)  *max_element(v.begin(),v.end())     // find max element in vector
#define mne(v)  *min_element(v.begin(),v.end())     // find min element in vector
#define vi vector<int>
#define sva(v) sort(all(v))
#define sz(x) int((x).size())
const lli N=10e6+10;
// use incase of input and output file
// freopen(input.txt,r,stdin);
// freopen(output.txt,w,stdout);

vector<vector<int>> add(vector<vector<int>>& v1, vector<vector<int>>& v2){
    size_t n{v1.size()};
    for(size_t i{0}; i<n; i++){
        for(size_t j{0}; j<n; j++){
            v1[i][j]=v1[i][j]+v2[i][j];
        }
    }
    return v1;
}

vector<vector<int>> add_padding(vector<vector<int>>& v){
    size_t m{v.size()}, n{v[0].size()};
    // cout<<m<<" "<<n<<endl;
    size_t fix{(size_t)(pow(2,max(ceil(log2(m)), ceil(log2(n)))))};
    vector<vector<int>>ans(fix, vector<int>(fix));
    for(size_t i{0}; i<fix; i++){
        for(size_t j{0}; j<fix; j++){
            if(i<m && j<n)ans[i][j]=v[i][j];
            else ans[i][j]=0;
        }
    }
    return ans;
}

void display(const vector<vector<int>>& v){
    for(size_t i{0}; i<v.size(); i++){
        for(size_t j{0}; j<v[0].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

vector<vector<int>> sub_vect(vector<vector<int>>& v, pair<int, int>s, pair<int, int>e){
    vector<vector<int>> ans(e.first-s.first+1, vector<int>(e.second-s.second+1));
    for(size_t i{0}; i<=e.first-s.first; i++){
        for(size_t j{0}; j<=e.second-s.second; j++){
            ans[i][j]=v[i+s.first][j+s.second];
        }
    }
    return ans;
}

vector<vector<int>> multiply(vector<vector<int>>& v1, vector<vector<int>>& v2){
    if(v1.size()==1){
        vector<vector<int>>v{{v1[0][0]*v2[0][0]}};
        return v;
    }
    else{
        int mid = (v1.size()-2)/2;

        vector<vector<int>> ans(v1.size(), vector<int>(v1.size()));
        vector<vector<int>> A11 = sub_vect(v1, make_pair(0,0), make_pair(mid, mid));
        vector<vector<int>> A12 = sub_vect(v1, make_pair(0,mid+1), make_pair(mid, v1.size()-1));
        vector<vector<int>> A21 = sub_vect(v1, make_pair(mid+1,0), make_pair(v1.size()-1, mid));
        vector<vector<int>> A22 = sub_vect(v1, make_pair(mid+1,mid+1), make_pair(v1.size()-1, v1.size()-1));

        vector<vector<int>> B11 = sub_vect(v2, make_pair(0,0), make_pair(mid, mid));
        vector<vector<int>> B12 = sub_vect(v2, make_pair(0,mid+1), make_pair(mid, v2.size()-1));
        vector<vector<int>> B21 = sub_vect(v2, make_pair(mid+1,0), make_pair(v2.size()-1, mid));
        vector<vector<int>> B22 = sub_vect(v2, make_pair(mid+1,mid+1), make_pair(v2.size()-1, v2.size()-1));

        vector<vector<int>> A11_B11 = multiply(A11, B11);
        vector<vector<int>> A12_B21 = multiply(A12, B21);
        vector<vector<int>> A11_B12 = multiply(A11, B12);
        vector<vector<int>> A12_B22 = multiply(A12, B22);
        vector<vector<int>> A21_B11 = multiply(A21, B11);
        vector<vector<int>> A22_B21 = multiply(A22, B21);
        vector<vector<int>> A21_B12 = multiply(A21, B12);
        vector<vector<int>> A22_B22 = multiply(A22, B22);

        vector<vector<int>> A = add(A11_B11, A12_B21);
        vector<vector<int>> B = add(A11_B12, A12_B22);
        vector<vector<int>> C = add(A21_B11, A22_B21);
        vector<vector<int>> D = add(A21_B12, A22_B22);

        for(size_t i{0}; i<=mid; i++){
            for(size_t j{0}; j<=mid; j++){
                ans[i][j]=A[i][j];
                ans[i][j+mid+1]=B[i][j];
                ans[mid+i+1][j]=C[i][j];
                ans[mid+i+1][mid+j+1]=D[i][j];
            }
        }

        return ans;
    }
}


vector<vector<int>> matrix_multiply(vector<vector<int>>& v1, vector<vector<int>>& v2){
    size_t m1{v1.size()}, n1{v1[0].size()}, m2{v2.size()}, n2{v2[0].size()};
    if(n1==m2){
        vector<vector<int>> v1_padded = add_padding(v1);
        vector<vector<int>> v2_padded = add_padding(v2);
        vector<vector<int>> ans_padded = multiply(v1_padded, v2_padded);
        vector<vector<int>> ans(m1, vector<int>(n2));
        for(size_t i{0}; i<m1; i++){
            for(size_t j{0}; j<n2; j++){
                ans[i][j]=ans_padded[i][j];
            }
        }
        return ans;
    }
    else{
        cout<<"Invalid multiplication."<<endl;
        return vector<vector<int>>{};
    }
}

void solve()
{
    vector<vector<int>> v1{
        {1, 2, 3, 4, 5, 6, 7},
        {8, 9, 10, 11, 12, 13, 14},
        {15, 16, 17, 18, 19, 20, 21},
        {22, 23, 24, 25, 26, 27, 28},
        {29, 30, 31, 32, 33, 34, 35},
        {36, 37, 38, 39, 40, 41, 42},
        {43, 44, 45, 46, 47, 48, 49}
    };
    vector<vector<int>> v2{
        {1, 2, 3, 4, 5, 6, 7},
        {8, 9, 10, 11, 12, 13, 14},
        {15, 16, 17, 18, 19, 20, 21},
        {22, 23, 24, 25, 26, 27, 28},
        {29, 30, 31, 32, 33, 34, 35},
        {36, 37, 38, 39, 40, 41, 42},
        {43, 44, 45, 46, 47, 48, 49}
    };
    display(matrix_multiply(v1, v2));
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
