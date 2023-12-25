#include <cstdio>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    
    int len = 0;
    for(int n = N; n != 0; n /= 10) ++len;
    
    int res = 0;
    for(int i = N - len*9; i < N; ++i){
        int sum = i, tmp = i;
        
        while(tmp != 0){
            sum += tmp % 10;
            tmp /= 10;
        }
        
        if(sum == N){
            res = i;
            break;
        }
    }
    
    printf("%d\n", res);
}
