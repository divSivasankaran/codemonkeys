#include <bits/stdc++.h>

using namespace std;

//We store the number of permutations for a number once we calculate it.
// So we won't have to calculate it again when it is encountered in the future.
unordered_map<int,int> ways;

int stepPerms(int n) {
    // if the key already exists in our map, then just return that.
    if(ways.find(n)!=ways.end())
    {
        return ways[n];
    }
    //If the number is 0 or <0 then there are no permutations, so return 0
    if(n<=0)
    {
        return 0;
    }

    // Recursively calculate the possibilities by fixing one option at a time,
    // and get the combinations of the remaining steps
    vector<int> step_size = {1,2,3};
    int result = 0;
    for(int i = 0; i< step_size.size(); i++)
    {
        if(n==step_size[i])
            result++;
        else if(n > step_size[i])
        {
            result += stepPerms(n-step_size[i]);
        }
    }
    // Add the result we have found to the map and return it.
    ways[n] = result;
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int s;
    cin >> s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int s_itr = 0; s_itr < s; s_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int res = stepPerms(n);

        fout << res << "\n";
    }

    fout.close();

    return 0;
}
