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
    
    void insert_helper(string word);
    void insert(string word);
    bool serach(string word);
};

void Trie::insert_helper(string word){
    Node *temp = root;
    for(char c : word){
        if(temp->children.count(c) == 0){
            temp->children[c] = new Node(c);
        }
        temp = temp->children[c];
    }
    temp->isTerminal = true;
}

bool Trie::serach(string word){
    Node *temp = root;
    for(char c : word){
        if(temp->children.count(c) == 0){
            return false;
        }
        temp = temp->children[c];
    }
    return temp->isTerminal;
}

void Trie::insert(string word){
    for(int i = 0; word[i] != '\0'; i++){
        cout << word.substr(i) << endl;
        Trie::insert_helper(word.substr(i));
    }

}


int main(){


    Trie t;

    vector<string> words = {"apple"};
    for(string word : words){
        t.insert(word);
    }

    vector<string> search_words = {"bana", "apple", "pple", "no"};
    for(string word : search_words){
        if(t.serach(word)){
            cout << "Yes " << word << endl;
        }else{
            cout << "No " << word << endl;
        } 
    }

}