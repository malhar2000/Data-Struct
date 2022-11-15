#include <iostream>
#include <unordered_map>
#include <cmath>
using namespace std;
int main(){
    unordered_map<int, int> mp;
    int arr[] = {2,2,3,3,2,4,4,4,4,4};

    for(int x: arr){
        mp[x]++;
    }

    for(auto x: mp){
        if(x.second%2 == 1 || x.second%3==1){
            cout << x.first << " " << x.second << endl;
            cout << "-1" << endl; 
            return -1;
         }
        else{
            mp[x.first] = floor(x.second/3);

        }
    }
}