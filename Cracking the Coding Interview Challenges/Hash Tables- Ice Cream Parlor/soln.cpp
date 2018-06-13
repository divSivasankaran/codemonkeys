#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

void whatFlavors(vector<int> cost, int money) {
    int idx1, idx2 = -1;
    bool found = false;
    multimap<int, int> mapped_cost;
    for(int i=0; i< cost.size(); i++){
        mapped_cost.insert(pair<int, int>(cost.at(i),(i+1)));
    }

    for(idx1 = 0; idx1<cost.size(); idx1++)
    {
         int rem = money-cost[idx1];
         auto itr = mapped_cost.find(cost[idx1]);
         int val = itr->second;
        
        if(rem==cost[idx1])
        {
            mapped_cost.erase(itr);
        }
        if(mapped_cost.find(rem)!=mapped_cost.end())
        {
            idx1 = val;
            idx2 = mapped_cost.find(rem)->second;
            break;
        } 
        if(rem==cost[idx1])
        {
            mapped_cost.insert(pair<int, int>(cost.at(idx1),(val)));
        }
    
    }
    cout<<idx1<<" "<<idx2<<endl;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int money;
        cin >> money;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string cost_temp_temp;
        getline(cin, cost_temp_temp);

        vector<string> cost_temp = split_string(cost_temp_temp);

        vector<int> cost(n);

        for (int i = 0; i < n; i++) {
            int cost_item = stoi(cost_temp[i]);

            cost[i] = cost_item;
        }

        whatFlavors(cost, money);
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
