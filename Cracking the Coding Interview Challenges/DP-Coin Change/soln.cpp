#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
// Hold the change for all values we encounter along with the MinCoin
// change[min_coin_denomination][n]=ways
// This is to avoid double counting the repetitive cases like 1,2 and 2,1.
unordered_map<int, unordered_map<int, unsigned long>> change;

unsigned long ways(int n, vector<int> coins) {
    //handle degenerate case
    if(n<=0 || coins.empty())
        return 0;
    unsigned long way_count = 0;
    if(change.find(coins[0]) == change.end()||change[coins[0]].find(n)==change[coins[0]].end())
    {
        for(int i=0; i<coins.size();i++)
        {
           if(n == coins[i])
               way_count++;
           if(n > coins[i])
           {
             //We need combinations, not permutations.
             // This means we don't have to preserve the order. (i.e., 2,1 is the same as 1,2)
             // One way to do this is to order the change by increasing value of change.
             // To do that, we can pass the coins in recursive fashion by removing all coins that are smaller than itself.
               vector<int> new_coins;
               new_coins.insert(new_coins.begin(), coins.begin()+i, coins.end());
               way_count += ways(n-coins[i],new_coins);
           }

        }
        change[coins[0]][n] = way_count;
        return way_count;
    }

    return change[coins[0]][n];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    string coins_temp_temp;
    getline(cin, coins_temp_temp);

    vector<string> coins_temp = split_string(coins_temp_temp);

    vector<int> coins(m);

    for (int i = 0; i < m; i++) {
        int coins_item = stoi(coins_temp[i]);

        coins[i] = coins_item;
    }

    sort(coins.begin(), coins.end());
    unsigned long res = ways(n, coins);

    fout << res << "\n";

    fout.close();

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
