#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //vector<int> a(n);
    std::multimap<int,int> a;
    std::multimap<int,int>::iterator it;
    for (int i = 0; i < n; i++) {
        int a_item;
        cin >> a_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        a.insert(std::make_pair(a_item,1));
        if ( i == 0 )
        {
            it=a.begin();
            //ut<<it->first<<"\n";
            printf("%.1f\n",(float)it->first);
            continue;
        }
        if ( i%2 == 0 )
        {
            if (a_item >= it->first)
            {
                printf("%.1f\n",(float)it->first);
            }

            else
            {
                it--;
                printf("%.1f\n",(float)it->first);
            }
        }
        else
        {
            if (a_item >= it->first) {
                float sum=(float)it->first;
                it++;
                sum+=(float)it->first;
                printf("%.1f\n",sum/2);        
            }

            else
            {
                it--;
                float sum=(float)it->first;
                it++;
                sum+=(float)it->first;
                printf("%.1f\n",sum/2);  
            } 
        }
    }

    return 0;
}


