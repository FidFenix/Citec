#include<bits/stdc++.h>
using namespace std;
int main(){
    int j, r, num, mac = -1, pos;
    while(scanf("%d %d",&j,&r) != EOF){
        int m[j];
        mac = -1;
        memset(m, 0, sizeof m);
        for(int i = 0; i < j*r; i++){
            scanf("%d",&num);
            m[i%j] += num;
            if(m[i%j] >= mac){
                mac = m[i%j];
                pos = i%j;
            }
        }
        printf("%d\n",pos+1);
    }
}
