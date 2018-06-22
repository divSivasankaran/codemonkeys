#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if(n<=1)
        return false;
    for(int i=2;i<=int(sqrt(n));i++)
        if(n%i==0)
            return false;
    return true;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int p_itr = 0; p_itr < p; p_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        bool res = isPrime(n);

        string result = "Not prime";
        if(res)
            result = "Prime";

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
