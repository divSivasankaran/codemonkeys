#include <bits/stdc++.h>

using namespace std;

void exploreRegion(vector<vector<int>>& grid, vector<vector<bool>> &processed, vector<pair<int, int>> &region, vector<pair<int, int>> &outer) {
    int rows= grid.size();
    int cols = grid[0].size();
    while(!outer.empty())
    {
        auto p = outer.front();
        outer.erase(outer.begin());
        int r = p.first;
        int c = p.second;
        if(r<0||c<0||r>=rows || c>= cols||processed[r][c]==true)
            continue;
        processed[r][c] = true;
        
        if(grid[r][c] == 1)
        {
            //Add this node to the region
            region.push_back(pair<int,int>(r,c));
            // Add its neighbours to outer
            for(int i=max(0,r-1);i<=std::min(r+1,rows-1);i++)
                for(int j=max(0,c-1);j<=std::min(c+1,cols-1);j++)
                    outer.push_back(pair<int,int>(i,j));
        }
    }
}
int explore(vector<vector<int>>& grid, vector<vector<bool>> &processed)
{ 
    int m = grid.size();
    int n = grid[0].size();
    
    vector<pair<int,int>> to_process;
    for(int i = 0; i< grid.size(); i++)
    {
        for(int j = 0; j< grid[0].size();j++)
            to_process.push_back(pair<int,int>(i,j));
    }
    
    unordered_map<int,vector<pair<int,int>>> regions;
    int region_count = 0;
    int curr_index = 0;
    int rows= grid.size();
    int cols = grid[0].size();
    while(!to_process.empty())
    {
        auto back = to_process.front();
        to_process.erase(to_process.begin());
        int r = back.first;
        int c = back.second;
        //Already processed or not part of a region, keep going
        if(r<0|| c<0|| r>=rows || c>= cols||processed[r][c]==true)
            continue;
        if(grid[r][c]==0)
        {
            processed[r][c] = true;
            continue;
        }
        //Region discovered. Get all connected nodes 
        vector<pair<int,int>> re;
        regions[region_count] = re;        
        vector<pair<int,int>> outer;
        outer.push_back(pair<int,int>(r,c));
        exploreRegion(grid, processed, regions[region_count++],outer);
    }
    int max = 0;
    for(int i=0;i<regions.size();i++)
    {
        max  = std::max(int(regions[i].size()),max);
    }
    return max;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> grid(n);
    for (int i = 0; i < n; i++) {
        grid[i].resize(m);

        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    vector<vector<bool>> processed(n, vector<bool>(m, false));
    
    int res = explore(grid, processed);

    fout << res << "\n";

    fout.close();

    return 0;
}
