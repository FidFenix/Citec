#include<bits/stdc++.h>
using namespace std;
#define N 105
int arr[N];
int memo[101][1000001];
int n, k;
bool f(int pos, int sum){
    if(pos >= n){
        if(!(sum%k))return 1;
        return 0;
    }
    if(memo[pos][sum] != -1)return memo[pos][sum];
    return memo[pos][sum] = f(pos + 1, sum + arr[pos]) || f(pos+1,sum-arr[pos]);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(memo,-1,sizeof memo);
        scanf("%d %d",&n,&k);
        for(int i = 0; i < n; i++) scanf("%d",arr + i);
        printf(f(0,0)?"Divisible\n":"Not divisible\n");
    }
}
