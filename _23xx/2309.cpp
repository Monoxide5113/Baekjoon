#include <cstdio>
#include <algorithm>
using namespace std;

const int SIZE = 9, SUM = 100;
int dwarves[SIZE];

int main(){
    int sum = 0;
    for(int i = 0; i < SIZE; ++i){
        scanf("%d", dwarves + i);
        sum += dwarves[i];
    }
    sort(dwarves, dwarves + SIZE);
    sum -= 100;
    
    int dwarf1, dwarf2;
    bool flag = false;
    for(int i = 0; i < SIZE - 1; ++i){
        for(int j = i + 1; j < SIZE; ++j){
            if(sum == dwarves[i] + dwarves[j]){
                dwarf1 = i;
                dwarf2 = j;
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    
    for(int i = 0; i < SIZE; ++i){
        if(i == dwarf1 || i == dwarf2) continue;
        printf("%d\n", dwarves[i]);
    }
}