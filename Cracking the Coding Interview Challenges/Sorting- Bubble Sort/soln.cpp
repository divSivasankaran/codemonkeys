#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int bubbleSort(vector<int> &a)
{
    int numSwaps = 0;
    for(int i = 0; i< a.size(); i++)
    {
        for(int j = i+1; j< a.size(); j++)
        {
            if(a[i]>a[j])
            {
                numSwaps++;
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
    
    return numSwaps;
}


int main() {
	int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }

    int numSwaps = bubbleSort(a);
    cout<<"Array is sorted in "<<numSwaps<<" swaps."<<endl;
    cout<<"First Element: "<<a.front()<<endl;
    cout<<"Last Element: "<<a.back();
    return 0;
}
