#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);



int main()
{
    string mn_temp;
    getline(cin, mn_temp);

    vector<string> mn = split_string(mn_temp);

    int m = stoi(mn[0]);

    int n = stoi(mn[1]);

    string magazine_temp_temp;
    getline(cin, magazine_temp_temp);

    vector<string> magazine_temp = split_string(magazine_temp_temp);

    vector<string> magazine(m);
    // Create a hash map with all the magazine words along with a counter for each word encountered 
    // (In order to handle multiple occurances of the same word)
    unordered_map<string, int> magazine_set;
    for (int i = 0; i < m; i++) {
        string magazine_item = magazine_temp[i];
        // Insert the words into the map and increase the counter for each word (magazine_item)
        magazine[i] = magazine_item;
        if(magazine_set.find(magazine_item) == magazine_set.end())
        {
            magazine_set[magazine_item] = 0;
        }
        magazine_set[magazine_item]++;
    }

    string ransom_temp_temp;
    getline(cin, ransom_temp_temp);

    vector<string> ransom_temp = split_string(ransom_temp_temp);

    vector<string> ransom(n);
    

    for (int i = 0; i < n; i++) {
        string ransom_item = ransom_temp[i];

        ransom[i] = ransom_item;
    }
    // Check if each word in the ransom can be found in the magazine
    // Exit the loop when a word cannot be found/we have looped through all word
    bool can = true;
    while(can && !ransom.empty()) 
    {
        string word = ransom.back();
        ransom.pop_back();
        if(magazine_set.find(word)==magazine_set.end()|| magazine_set[word]<=0)
        {
            can = false;
        }
        else{
            magazine_set[word]--;
        }
    }
    // Print out the result
    if(can)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
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
