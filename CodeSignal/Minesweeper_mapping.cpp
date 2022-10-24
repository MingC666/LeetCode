// adding 1 to all negibbor coordination
void findMine(int r, int c, vector<vector<int>> &map)
{
    int row = map.size()-1;
    int col = map[0].size()-1;
    for(int i=r-1; i<=r+1; i++)
    {
        // boundary 
        if(i<0 || i>row)
            continue;
        for(int j=c-1; j<=c+1; ++j)
        {
            // skip the mine itself
            if(i==r && j==c)
                continue;
                
            // boundary 
            if(j<0 || j>col)
                continue;
            // otherwise
            map[i][j]++;
        }
    }
}

vector<vector<int>> solution(vector<vector<bool>> matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    vector<vector<int>> res(row, vector<int>(col, 0));
    
    for(int i=0; i<row; ++i)
    {
        for(int j=0; j<col; ++j)
        {
            if(matrix[i][j] == true)
                findMine(i, j, res);
        }
    }
    
    return res;
}

// adding 1 to all negibbor coordination
void findMine(int r, int c, vector<vector<int>> &map)
{
    int row = map.size()-1;
    int col = map[0].size()-1;
    for(int i=r-1; i<=r+1; i++)
    {
        // boundary 
        if(i<0 || i>row)
            continue;
        for(int j=c-1; j<=c+1; ++j)
        {
            // skip the mine itself
            if(i==r && j==c)
                continue;
                
            // boundary 
            if(j<0 || j>col)
                continue;
            // otherwise
            map[i][j]++;
        }
    }
}

vector<vector<int>> solution(vector<vector<bool>> matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    vector<vector<int>> res(row, vector<int>(col, 0));
    
    for(int i=0; i<row; ++i)
    {
        for(int j=0; j<col; ++j)
        {
            if(matrix[i][j] == true)
                findMine(i, j, res);
        }
    }
    
    return res;
}

