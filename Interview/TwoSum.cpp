#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(){
    vector<int> v{2, 11, 7, 15};
    unordered_map<int, int> mp; 
    int target = 9;

    for(int i=0; i<v.size(); i++){
        if(mp.find(target-v[i]) != mp.end()){
            cout <<  mp[target-v[i]] << " " << i << endl;
            break;
         } 
          mp[v[i]] = i;
    }
    return 0;
       
  }
    // sort(v.begin(), v.end());
    // int target = 13;

    // int left = 0;
    // int right = v.size()-1;

    // while(left < right){
    //     if(v[left]+v[right] == target){
    //         cout << left << " " << right << endl;
    //         break;
    //     }
    //     else if(v[left]+v[right] > target){
    //         right--;
    //     }
    //     else if(v[left]+v[right] < target){
    //         left++;
    //     }
    // }

     
