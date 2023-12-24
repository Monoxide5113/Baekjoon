#include <cstdio>
#include <algorithm>
using namespace std;

const int BOARD_MAX = 50, BOARD_SIZE = 8, SQUARE_CNT = 64;
char board[BOARD_MAX][BOARD_MAX];

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i){
        getchar();
        for(int j = 0; j < M; ++j){
            board[i][j] = getchar();
        }
    }
    
    int res = SQUARE_CNT;
    for(int i = 0; i <= N - BOARD_SIZE; ++i){
        for(int j = 0; j <= M - BOARD_SIZE; ++j){
            int cnt = 0;
            for(int r = 0; r < BOARD_SIZE; ++r){
                for(int c = 0; c < BOARD_SIZE; ++c){
                    char color = (r+c) % 2 == 0 ? 'W' : 'B';
                    if(board[i+r][j+c] != color) cnt++;
                }
            }
            res = min(res, cnt);
            res = min(res, SQUARE_CNT-cnt);
        }
    }
    
    printf("%d\n", res);
}
