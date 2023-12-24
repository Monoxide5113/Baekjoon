#include <cstdio>
#include <vector>
using namespace std;

const int MAX = 1001;
vector<int> tn(1, 1);

int main(){
    for(int i = 2;; ++i){
        int next = tn.back() + i;
        if(next >= MAX) break;
        tn.push_back(next);
    }
    
    int T;
    scanf("%d", &T);
    for(int t = 0; t < T; ++t){
        int K;
        scanf("%d", &K);
        
        bool res = false;
        for(int i : tn){
            for(int j : tn){
                for(int k : tn){
                    if(i + j + k == K){
                        res = true;
                        break;
                    }
                }
                if(res) break;
            }
            if(res) break;
        }
        
        printf("%d\n", res);
    }
}