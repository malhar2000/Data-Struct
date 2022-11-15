#include<iostream>
#include<unordered_map>
#include<vector>


using namespace std;
int main(){
    unordered_map<int, int> left;
    unordered_map<int, int> right;
    vector<int> arr = {1, 16, 4, 16, 64, 16};
    int r = 4;
    int GP = 0;

    for(auto num : arr){
        right[num]++;
    }

    for(int i = 0; i < arr.size(); i++){
        left[arr[i]]++;
        right[arr[i]]--;
        if(left.count(arr[i]/r) != 0 && right.count(arr[i]*r) != 0){
            GP += left[arr[i]/r]*right[arr[i]*r];
        }
    }

    cout << "GP: " << GP << endl;
}