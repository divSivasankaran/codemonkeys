#include <bits/stdc++.h>
#include <iomanip>
#include<queue>
using namespace std;


int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> a(n);
    
    //Maintain two heaps - Left heap is a max heap & right heap is a min heap.. 
    // this way we can ensure that the tops of each heap holds the median values at any time.
    
    priority_queue<int,vector<int>,greater<int> > right;
    priority_queue<int,vector<int>> left;
    double median;
    
    cout<<std::fixed<<std::setprecision(1);
    
    struct comparator{
        bool operator()(const long& a,const long& b) const{
            return a<b;
        } 
    };
    
    for (int i = 0; i < n; i++) {
        int a_item;
        cin >> a_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        a[i] = a_item;
        
        if(i==0)
            left.push(a_item);
        else if(a_item > left.top())
            right.push(a_item);   
        else 
            left.push(a_item);
            
        //Balance the two heaps if they aren't of the same size (or at most left = right + 1)
        while(left.empty()||right.size()>left.size())
        {
            int t = right.top();
            right.pop();
            left.push(t);
        }
        while(left.size()>right.size()+1)
        {
            int t = left.top();
            left.pop();
            right.push(t);
        }
                   
        if(i%2==0|| right.empty())
        {
            median = left.top();
        }
        else
        {
            median = ( left.top() + right.top() )/2.0;
        }
               
        cout<<median<<endl;
    }
    
    return 0;
}
