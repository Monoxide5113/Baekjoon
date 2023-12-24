#include <cstdio>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    
    int res = 0;
    for(int i = 0; i < N; ++i){
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