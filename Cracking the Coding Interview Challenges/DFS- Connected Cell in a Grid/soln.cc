#include <bits/stdc++.h>

using namespace std;
int n,m;
int countt=0;

void dfs(vector<vector<int>> grid, vector<vector<bool>> &visited, int i, int j) {
    
    if (grid[i][j]==0) { 
        return ;
    }
    if (visited[i][j]) return ;
    visited[i][j]=true;
    countt++;
    
    if ( (i-1 >= 0) ) {
        dfs(grid,visited,i-1,j);
        if ( j-1 >= 0 ){
            dfs(grid,visited,i-1,j-1);
        }
    }
    if (j-1 >= 0 ) {
        dfs(grid,visited,i,j-1);
        if ( i+1 < n ){
            dfs(grid,visited,i+1,j-1);
        }
    }
    if ( i+1 < n ) {
        dfs(grid,visited,i+1,j);
        if ( j+1 < m ) {
            dfs(grid,visited,i+1,j+1);
        }
    }
    if ( j+1 < m ) {
        dfs(grid,visited,i,j+1);
        if (i-1 >=0 ) {
            dfs(grid,visited,i-1,j+1);
        }
    }
    
}

// Complete the maxRegion function below.
int maxRegion(vector<vector<int>> grid,vector<vector<bool>> &visited) {
    int max=0;
    int temp=0;
    for (int i = 0 ; i < n ; i++)
        for (int j = 0; j < m; j++)
            if (!visited[i][j])
            {
                countt=0;
                dfs(grid, visited, i, j);
                if ( countt > max )
                    max = countt;                
            }
    return max;

}

int main()
{
    
    ofstream fout(getenv("OUTPUT_PATH"));
    //int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> grid(n);
    vector<vector<bool>> visited(n);
    for (int i = 0; i < n; i++) {
        grid[i].resize(m);
        visited[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            visited[i][j]=false;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int res = maxRegion(grid,visited);

    fout << res << "\n";

    fout.close();

    return 0;
}
