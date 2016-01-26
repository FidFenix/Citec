#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
bool P[27];
int K, N;
string palabra;
bool isvowel(char A){
    return A == 'a' || A == 'e'|| A == 'i'|| A == 'o' || A == 'u';
}
void gen(int pos, int V, int W){
    if(pos >= N ){
        if(V + W == K && V >= 1 && W >= 2){
            for(int i = 0; i < N; i++) if(P[i])printf("%c",palabra[i]);
            printf("\n");
        }
    }else{
        if(isvowel(palabra[pos])){
            P[pos] = 1;
            gen(pos+1,V+1,W);
        }else{
            P[pos] = 1;
            gen(pos+1,V,W+1);
        }
        P[pos] = 0;
        gen(pos+1,V,W);
    }
}
int main(){
    char in[2];
    palabra = "";
    scanf("%d %d",&K,&N);
    for(int i = 0; i < N; i++){
        scanf("%s", in);
        palabra +=in[0];
    }
    sort(palabra.begin(),palabra.end());
    gen(0,0,0);
    return 0;
}
