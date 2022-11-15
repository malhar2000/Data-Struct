#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>


using namespace std;

int main(){
    vector<int> v{-2,1,-3,4,-1,2,1,-5,14};
    int current_sum =v[0];
    int max = INT_MIN;
    int start_index = 0;

    for(int i=1; i<v.size();i++){
        if(current_sum > max){
            max = current_sum;
        }
         if(current_sum < 0){
            current_sum = 0;
            start_index = i;
         }
         current_sum += v[i];
    }
    if(current_sum > max){
        max = current_sum;
    }
    cout << max << endl;
    cout << start_index << endl;
    
}