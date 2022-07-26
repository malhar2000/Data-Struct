#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int findCenter(vector<vector<int>>edges)
{
    
     unordered_map<int, int> mp{0};   
     for(int i = 0; i < edges.size(); i++){
         for(int node: edges.at(i)){
              mp[node] = mp[node] + 1;
         }
     }
     for(auto t: mp){
         cout << t.first << " " << t.second << endl;
         if(t.second == edges.size()){
            return t.first;
         }
     }
     return -1;
}

int main(){
    vector<vector<int>> e = {{1, 2}, {2,3}, {4,2}}; 
    cout << findCenter(e) << endl;
}