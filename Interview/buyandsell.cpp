#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(){
    vector<int> v{5,2,8,1,5,6};
    int left = 0, right = 1;
    int max = INT_MIN;
    for(int i=0; i<v.size(); i++){
        if(v[right] - v[left] > max){
            max = v[right]-v[left];
        }
        if(v[left] < v[right]){
            right++;
        }else if(v[left] > v[right]){
            left++;
            right++;
        }
    }
    cout << max << endl;
}