#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// We count inversions by performing merge sort (Other sorts would work too, but time-comlpexity of Omega (n log n) will fail for large input arrays.
long countInversions(vector<int>& arr) {

    if(arr.size()<=1)
    {
        return 0;
    }
    
    int mid = arr.size()/2;
    std::vector<int> left, right;
    
    // Recursively split the array into left & right sections & sort them
    
    left.insert(left.end(), arr.begin(), arr.begin()+mid);
    right.insert(right.end(), arr.begin()+mid, arr.end());
    //We will combine the resulting inversions in each sub-array with the final inversion count later.  
    long linv = countInversions(left);
    long rinv = countInversions(right);
       
    // now we combine the two sorted sub-arrays by looking at the first element of each sub-array
    long l = 0, r= 0, inv=0, i=0;
    for(i = 0; i< arr.size() && l < left.size() && r < right.size(); i++){
        // When the first element in the right sub-array is less than the first element in the left sub-array, it means all elements in the left array are greater than this element.
        if(left[l] > right[r])
        {
            //So, even though we don't exacly perform that many inversions, we count the actual number of inversions needed
            inv = inv + (left.size()-l);
            arr[i] = right[r];
            r++;
        }
        else
        {
            // In this case, the left sub-array is < than the right sub-array.. so it is already sorted (for the first two elements of each sub-array). So no inversions.
            arr[i] = left[l];
            l++;
        }
    }
    // The loop above might have stopped earlier if either of the sub-arrays were exhausted. If so, we still need to add the remaining elements to our final sorted - array. However, there is no inversions involved in these transactions because -
    while(l<left.size())
    { //These inversions are accounted for already when we moved the right-sub-array ahead of the left.
        arr[i] = left[l];
        i++;
        l++;
    }
    while(r<right.size())
    {//These elements are sorted correctly already, so no inversions.
        arr[i] = right[r];
        i++;
        r++;
    }
  // now we must combine all the inversions we have performed so far (the number we did for the two sub-arrays and the number of inversions in combining the two sorted arrays)
    return rinv+ linv + inv;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);
        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        long result = countInversions(arr);

        fout << result << "\n";
    }

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
