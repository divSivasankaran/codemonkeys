#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int lonely_integer_set(vector<int> a)
{
    unordered_set<int> aset;
    for(int i=0;i<a.size();i++)
    {
        if(aset.find(a[i])==aset.end())
        {
            aset.insert(a[i]);
        }
        else
        {
            aset.erase(a[i]);
        }
    }
    return *aset.begin();
}

int lonely_integer_xor(vector<int> a)
{
    int val = 0;
    for(int i=0;i<a.size();i++)
    {
        // XOR operation for a number on itself will yield 0. 
        val ^= a[i];
    }
    return val;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }
    int li = lonely_integer_xor(a);
    cout<<li<<endl;
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
