#include<bits/stdc++.h>
using namespace std;
bool test(int a, int b, int c, int q){
    if(a == b && q == a && q == b)return 1;
    if(a == c && a == q && c == q)return 1;
    if(b == c && b == q && c == q)return 1;
    return 0;
}
int main(){
    int n, q, d, c, s, p,cola,heap,pila,queries;
    while(scanf("%d",&n) != EOF){
        queue<int> C;
        stack<int> S;
        priority_queue<int> P;
        queries = cola = pila = heap = 0;
        while(n--){
            scanf("%d %d",&q,&d);
            if(q == 1){
                C.push(d);
                S.push(d);
                P.push(d);
            }else{
                queries++;
                if(!C.empty()){
                    c = C.front();
                    if(c == d) C.pop(),cola++;
                }
                if(!S.empty()){
                    s = S.top();
                    if(s == d ) S.pop(),pila++;
                }
                if(!P.empty()){
                    p = P.top();
                    if( p == d) P.pop(),heap++;
                }
            }
        }
        if(cola != queries && pila != queries && heap != queries)printf("impossible\n");
        else if(test(cola, pila, heap, queries))printf("not sure\n");
        else{
            if(cola == queries)printf("queue\n");
            else if(pila == queries)printf("stack\n");
            else printf("priority queue\n");
        }
    }
}
