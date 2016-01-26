#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,y,z;
};
int main(){
    int N;
    scanf("%d",&N);
    node arr[N];
    int X,Y,Z;
    scanf("%d%d%d",&X,&Y,&Z);
    for(int i = 0; i < N; i++) scanf("%d%d%d",&arr[i].x,&arr[i].y,&arr[i].z);
    node aux;
    for(int i = 0; i < (1<<N); i++){
        aux.x = 0;
        aux.y = 0;
        aux.z = 0;
        int count = 0;
        for(int j = 0;j < N; j++){
            if((i&(1<<j))){
                aux.x += arr[j].x;
                aux.y += arr[j].y;
                aux.z += arr[j].z;
                count++;
            }
        }
        if(aux.x == X && aux.y == Y && aux.z == Z && count > 1){
            printf("Y\n");
            return 0;
        }
    }
    printf("N\n");
}
