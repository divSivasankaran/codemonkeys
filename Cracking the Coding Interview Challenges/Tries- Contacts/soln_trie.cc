#include <bits/stdc++.h>
using namespace std;
class node
{
    public:
    int size;
    std::map<char,node*> children;
    node();
    node(int n);
};

node::node()
{
    size=1;
}
node::node(int n)
{
    size=n;
}

void addContact(node* root, string s){
    node* curnode=root;
    std::map<char,node*>::iterator it;
    for (int i = 0 ; i < s.length() ; i++){
        it = (curnode->children).find(s[i]);
        if ( it != (curnode->children).end()) {
            curnode = it->second;
            (curnode->size)+=1;
        }
        else {
            curnode->children[s[i]]=new node;
            curnode=curnode->children[s[i]];
        }
    }
}

int findContact(node* root, string s) {
    if (!root) return 0;
    node* curnode =root;
    std::map<char,node*>::iterator it;
    for ( int i = 0 ; i < s.length() ; i++ ) {
        it = (curnode->children).find(s[i]);
        if ( it == curnode->children.end())
            return 0;
        curnode = it->second;
    }
    return curnode->size;    
}


vector<string> split_string(string);

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    node* root= new node(1);
    for (int n_itr = 0; n_itr < n; n_itr++) {
        string opContact_temp;
        getline(cin, opContact_temp);

        vector<string> opContact = split_string(opContact_temp);

        string op = opContact[0];
        string contact = opContact[1];
        if (op.compare("add")==0) {
            addContact(root,contact);
        }
        else {
            cout<<findContact(root,contact)<<"\n";
        }
        
    }

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

