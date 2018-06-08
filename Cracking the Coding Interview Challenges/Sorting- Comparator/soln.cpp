
vector<Player> comparator(vector<Player> players) {
    
    if(players.empty()|| players.size() == 1)
    {
        return players;
    }
    
    int pivotIdx = players.size()/2;
    Player pivot = players[pivotIdx];
    
    vector<Player> left;
    vector<Player> right;
        
    for(int i = 0; i< players.size(); i++)
    {
        if(i == pivotIdx)
            continue;
        
        if(players[i].score <  pivot.score)
        {
            right.push_back(players[i]);
        }
        else if (players[i].score == pivot.score)
        {
            auto res = pivot.name.compare(players[i].name);
            if(res <0)
            {
                right.push_back(players[i]);
            }
            else{
                left.push_back(players[i]);
           }
        }
        else
        {
            left.push_back(players[i]);
        }
    }
    
    left = comparator(left);
    right = comparator(right);
    
    vector<Player> result;
    result.insert(result.end(),left.begin(),left.end());
    result.push_back(pivot);
    result.insert(result.end(), right.begin(), right.end());
   
    
    return result;
}
