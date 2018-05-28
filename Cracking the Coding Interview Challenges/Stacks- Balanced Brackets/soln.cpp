#include <bits/stdc++.h>

using namespace std;

char matcher(char v){
    char res;
    switch(v){
        case '[': res = ']';
             break;
        case ']': res = '[';
             break;
        case '{': res = '}';
             break;
        case '}': res = '{';
             break;
        case '(': res = ')';
             break;
        case ')': res = '(';
             break;
        default: res = 'n';    
    }
    return res;
}

bool isLeft(char v){
    if(v == '['|| v=='('||v=='{')
        return true;
    else
        return false;
}

bool process_expression(string exp){
    std::stack<char> to_process;
    bool balanced = true;
    int i = 0;
    while(i < exp.length())
    {
        if(isLeft(exp[i])) //Opening braces.. so we add it to our stack
        {
            to_process.push(exp[i]);
        }
        else{
            // There are no more left braces to match!
            if(to_process.empty()){
                balanced = false;
                break;
            }
            
            //It's a closed brace .. this means we need to check if it matches the most recent unmatched bracket
            char p = to_process.top();
            to_process.pop();
            // the two do not match, exit the loop and return false
            if(p != matcher(exp[i]))
            {
                balanced = false;
                break;
            }            
        }
        i++;
    }
    //check for the case where there are unmatched left braces after the string has been read fully.
    if(!to_process.empty()){
        balanced = false;
    }
    return balanced;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string expression;
        getline(cin, expression);
        bool result  = process_expression(expression);
        if(result)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}
