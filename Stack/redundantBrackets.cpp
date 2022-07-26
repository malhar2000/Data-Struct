#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool checkRedundantBrackets(string input)
{
    stack<char> s;

    for (auto ch : input)
    {
        if (ch != ')' && ch != '}' && ch != ']')
        {
            s.push(ch);
             
        }
        else
        {   
            bool operator_found = false;
            while(!s.empty() and s.top() != '('){
                char top = s.top();
                if(top == '+' or top == '-' or top == '*' or top == '/'){
                    operator_found = true;
                }
                
                s.pop();
            }
            s.pop();//the opening bracket
            if(!operator_found){
                return true; //the pair is redundant
            }
        }
    }

    return false;//not redundant
     
}

int main()
{
    bool val = checkRedundantBrackets("((A+B) + C)");
    if (val)
    {
        cout << "Redundant" << endl;
    }
    else
    {
        cout << "Not Redundant" << endl;
    }
    return 0;
}