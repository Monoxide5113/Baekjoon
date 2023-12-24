#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 50;
int N, res = 0;
char candy[MAX][MAX];

void Check(){
    for(int i = 0; i < N; ++i){
        int cnt = 1;
        for(int j = 0; j < N; ++j){
            if(candy[i][j] == candy[i][j+1]) cnt++;
            else{
                res = max(res, cnt);
                cnt = 1;
            }
        }
    }
    
    for(int j = 0; j < N; ++j){
        int cnt = 1;
        for(int i = 0; i < N; ++i){
            if(candy[i][j] == candy[i+1][j]) cnt++;
            else{
                res = max(res, cnt);
                cnt = 1;
            }
        }
    }
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        getchar();
        for(int j = 0; j < N; ++j){
            candy[i][j] = getchar();
        }
    }
    
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N-1; ++j){
            swap(candy[i][j], candy[i][j+1]);
            Check();
            swap(candy[i][j], candy[i][j+1]);
        }
    }
    
    for(int j = 0; j < N; ++j){
        for(int i = 0; i < N-1; ++i){
            swap(candy[i][j], candy[i+1][j]);
            Check();
            swap(candy[i][j], candy[i+1][j]);
        }
    }
    
    printf("%d", res);
}