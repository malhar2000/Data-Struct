#include<iostream>
#include<stack>

using namespace std;


bool checkBrackets(string input){
    stack<char> s;

    for(auto ch: input){
        switch(ch){
            case '[': 
            case '(':
            case '{': s.push(ch); 
                      break;
            case '}':
                      if(!s.empty() and s.top() == '{'){
                         s.pop();
                      }else{
                        return false;
                      }
                      break;
            case ']':
                      if(!s.empty() and s.top() == '['){
                        s.pop();
                      }else{
                        return false;
                      }
                      break;
           case ')':
                      if(!s.empty() and s.top() == '('){
                        s.pop();
                      }else{
                        return false;
                      }
                      break;
        }
    }
    if(s.empty()){
        return true;
    }else{
        return false;
    }
}

int main(){
     
     bool val = checkBrackets("((())){}[");
     if(val){
        cout<<"Balanaced!!"<<endl;
     }else{
        cout<<"NOt Balanaced!!"<<endl;
     }

}