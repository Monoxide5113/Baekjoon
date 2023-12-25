#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX = 20, NONE = -1;
int N, x[MAX], y[MAX], xPlus, yPlus, xMinus, yMinus;
long long res = NONE;

long long CalDistance(int x, int y){
    return 1LL*x*x + 1LL*y*y;
}

void Dfs(int cur, int cnt){
    if(cur == N){
        long long tmp = CalDistance(xPlus-xMinus, yPlus-yMinus);
        if(res == NONE){
            res = tmp;
            return;
        }
        res = min(res, tmp);
        return;
    }
    
    if(cnt < N/2){
        xPlus += x[cur]; yPlus += y[cur];
        Dfs(cur+1, cnt+1);
        xPlus -= x[cur]; yPlus -= y[cur];
    }
    
    if(cur-cnt < N/2){
        xMinus += x[cur]; yMinus += y[cur];
        Dfs(cur+1, cnt);
        xMinus -= x[cur]; yMinus -= y[cur];
    }
}

int main(){
    int T;
    scanf("%d", &T);
    for(int t = 0; t < T; ++t){
        scanf("%d", &N);
        for(int i = 0; i < N; ++i){
            scanf("%d %d", x+i, y+i);
        }
        
        res = NONE;
        Dfs(0, 0);
        printf("%.6lf\n", sqrt(res));
    }
}