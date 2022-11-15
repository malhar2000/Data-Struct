#include<iostream>
#include<vector>
 
using namespace std;

int main(){
    vector<int> x = {3, 10, 5, 8, 2, 25};
    int max = INT_MIN;

    for(int i = 0; i < x.size(); i++){
        for(int j = 0; j < x.size(); j++){
            if(i!=j){
                int value = x[i]^x[j];
                if(value>max){
                    max = value;
                }
            }
        }
    }
    cout << max << endl;
}