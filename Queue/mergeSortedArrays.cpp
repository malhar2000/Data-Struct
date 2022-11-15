#include <iostream>
#include <queue>

using namespace std;


vector<int> mergeArrays(vector<vector<int> > &arrays) {
    vector<int> result;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int> > > q;
    int numbers_of_arrays = arrays.size();

    for(int i=0; i < numbers_of_arrays; i++) {
        // pushing the first element of the each array in arrays.., array id, and element id...
        q.push({arrays[i][0], i, 0});
    }

    while(!q.empty()){
        auto top_element_data = q.top();
        q.pop();

        int element = top_element_data[0];
        int array_id = top_element_data[1];
        int element_id = top_element_data[2];

        result.push_back(element);

        if(element_id+1 < arrays[array_id].size()){
            q.push({arrays[array_id][element_id+1], array_id, element_id+1});
        }

     }

    return result;
}

int main(){
    vector<vector<int> > arr = {
        {2, 34, 36, 45},
        {10, 23, 24},
        {1, 2, 3, 4, 5, 10} 
        };
    vector<int> result = mergeArrays(arr);
    for(int i : result){
        cout << i << " ";
    }
    cout << endl;
}