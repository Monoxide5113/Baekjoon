#include <cstdio>
using namespace std;

const int MAX = 20;
int N, S, seq[MAX], res = 0, curSum = 0;

void Dfs(int cur, int curSum){
    if(cur >= N) return;
    
    if(curSum + seq[cur] == S) res++;
    curSum += seq[cur];
    Dfs(cur+1, curSum);
    curSum -= seq[cur];
    Dfs(cur+1, curSum);
}

int main(){
    scanf("%d %d", &N, &S);
    for(int i = 0; i < N; ++i){
        scanf("%d", seq + i);
    }
    
    Dfs(0, 0);
    printf("%d\n", res);
}
