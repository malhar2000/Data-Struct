#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>


using namespace std;

int main(){
    int n = 15;
    int count = 0;
    while(n){
        n &= (n-1);
        count++;
    }
    cout << count << endl;
}