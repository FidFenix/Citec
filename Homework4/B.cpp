#include<bits/stdc++.h>
using namespace std;
#define N 1004
string line;
int memo[N][N];
int n;
int f(int A, int B){
    if(A > B)return 0;
    if(A == B)return 1;
    if(memo[A][B] != -1)return memo[A][B];
    if(line[A] == line[B]) return memo[A][B] = 2 + f(A + 1, B - 1);
    return memo[A][B] = max(f(A + 1, B), f(A, B - 1));
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);cout.tie(NULL);
    int t;
    cin>>t;
    getline(cin,line);
    while(t--){
        getline(cin, line);
        // A  MI NO ME AGARRAN 
        if(!line.size()){
            cout<<"0"<<endl;
            continue;
        }
        n = line.size()-1;
        memset(memo,-1,sizeof memo);
        cout<<f(0,n)<<endl;
    }
}
