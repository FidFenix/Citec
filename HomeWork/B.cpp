#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, q, num, L, R;
    scanf("%d",&n);
    int arr[n+1];
    arr[0] = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d",arr+i);
        arr[i] += arr[i-1];
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&L, &R);
        printf("%d\n",arr[R] - arr[L-1]);
    }
}
