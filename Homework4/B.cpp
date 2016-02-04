#include<bits/stdc++.h>
using namespace std;
#define N 1004
string line1, line2;
int memo[N][N];
int n;
int f(int A, int B){
    if(A >= n || B >= n)return 0;
    if(memo[A][B] != -1)return memo[A][B];
    if(line1[A] == line2[B]) return memo[A][B] = 1 + f(A + 1, B + 1);
    return memo[A][B] = max(f(A + 1, B), f(A, B + 1));
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>>line1;
        line2 = "";
        n = line1.size();
        for(int i = n -1; i >= 0; i--)line2 += line1[i];
        memset(memo,-1,sizeof memo);
        cout<<f(0,0)<<endl;
    }
}
