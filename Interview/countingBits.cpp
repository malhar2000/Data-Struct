#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>


using namespace std;

int main(){
    int num = 16;
    
    vector<int> dp(num+1, 0);
    int offset = 1;
    dp[0] = 0;
    for(int i = 1; i < num; i++){
        if(offset*2 == i){
            offset = i;
        }
        dp[i] = 1+dp[i-offset];
         
    }
    for(int i = 0; i < num; i++){
        cout << dp[i] << endl;
    }
}