#include<bits/stdc++.h>
using namespace std;
#define N 10004
int arr[N];
int memo1[N][101];
int memo2[N][101];
int n, k;
bool f(int pos, int sum){
    if(pos >= n){
        if(sum == 0)return 1;
        return 0;
    }
    if(sum >= 0){
        if(memo1[pos][sum] != -1)return memo1[pos][sum];
        return memo1[pos][sum] = f(pos + 1, (sum + arr[pos]%k)%k) || f(pos+1,(sum - arr[pos]%k + k)%k);
    }else{
        if(memo2[pos][-sum]!=-1)return memo2[pos][-sum];
        return memo2[pos][-sum] = f(pos + 1, (sum + arr[pos]%k)%k) || f(pos+1,(sum - arr[pos]%k + k)%k);
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(memo1,-1,sizeof memo1);
        memset(memo2,-1,sizeof memo2);
        scanf("%d %d",&n,&k);
        for(int i = 0; i < n; i++) scanf("%d",arr + i);
        printf(f(1,arr[0])?"Divisible\n":"Not divisible\n");
    }
}
