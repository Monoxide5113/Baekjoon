#include <cstdio>
#include <map>
using namespace std;

map<int, bool> flag;

bool Match(int ans, int que, int strike, int ball){
    int da[3], dq[3];
    for(int i = 0; i < 3; ++i){
        da[i] = ans % 10;
        dq[i] = que % 10;
        ans /= 10;
        que /= 10;
    }
    
    int tmpStrike = 0, tmpBall = 0;
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            if(da[i]==dq[j]) (i==j ? tmpStrike : tmpBall)++;
        }
    }
    return strike==tmpStrike && ball==tmpBall;
}

int main() {
    int N;
    scanf("%d", &N);
    
    for(int i = 1; i < 10; ++i){
        for(int j = 1; j < 10; ++j){
            if(i==j) continue;
            for(int k = 1; k < 10; ++k){
                if(i==k || j==k) continue;
                flag[i*100 + j*10 + k] = true;
            }
        }
    }
    
    int res = 9 * 8 * 7;
    for(int n = 0; n < N; ++n){
        int num, strike, ball;
        scanf("%d %d %d", &num, &strike, &ball);
        for(auto& i : flag){
            if(!i.second) continue;
            if(!Match(i.first, num, strike, ball)){
                i.second = false;
                res--;
            }
        }
    }
    
    printf("%d\n", res);
}