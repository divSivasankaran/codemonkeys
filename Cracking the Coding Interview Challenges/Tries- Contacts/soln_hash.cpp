#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);



int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    std::unordered_map<string,int> strMap;
    
    for (int n_itr = 0; n_itr < n; n_itr++) {
        string opContact_temp;
        getline(cin, opContact_temp);

        vector<string> opContact = split_string(opContact_temp);

        string op = opContact[0];

        string contact = opContact[1];
        
        string add = "add";
        if(!op.compare(add))
        {
            string t;
            for(int i = 0; i <contact.size(); i++ )
            {
                t = t+contact[i];
                 //O(1) on average
                if(strMap.find(t)==strMap.end())
                {
                    //O(1) on average
                    strMap[t] = 0;
                }
                strMap[t]++;
            }
        }
        else{
            //O(1) on average
            if(strMap.find(contact)==strMap.end())
            {
                cout<<0<<endl;
            }
            else{
                cout<<strMap[contact]<<endl;
            }
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
