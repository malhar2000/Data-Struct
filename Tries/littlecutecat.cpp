

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Node{
    public:
        char data;
        unordered_map<char, Node*> children;
        bool isTerminal;
    
    Node(char d) {
        data = d;
        isTerminal = false;
    }
};

class Trie{
public:
    Node* root;
    
    Trie(){
        root = new Node('\0');
    }
 
    void insert(string word);
    // bool serach(vector<string> words, string document);
    void search_helper(Trie t, string document, int i, unordered_map<string, bool> &m);
};

void Trie::search_helper(Trie t, string document, int i, unordered_map<string, bool> &m){
    Node *temp = t.root;
    for(int j = i; j < document.length(); j++){
        if(temp->children.count(document[j]) == 0){
            return;
        }
        temp = temp->children[document[j]];
        if(temp->isTerminal){
            string found = document.substr(i, j-i+1);
            m[found] = true;
        }
    }
    return;
}

void Trie::insert(string word){
    Node *temp = root;
    for(char c : word){
        if(temp->children.count(c) == 0){
            temp->children[c] = new Node(c);
        }
        temp = temp->children[c];
    }
    temp->isTerminal = true;
}

void serach(vector<string> words, string document){
     Trie t;

     for(string word : words){
        t.insert(word);
     }

     unordered_map<string, bool> m;

     for(int i = 0; i < document.length(); i++){
        t.search_helper(t, document, i, m);
     }
     for(auto w : words){
        if(m[w]){
            cout << "found " << w << endl;
        }
     }
    return;
}
int main(){

 

    vector<string> search_words = {"cute cat", "ttle", "kill", "cat"};
    string document = "little cute cat loves coding c++.";
    serach(search_words, document);

}