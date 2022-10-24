int getVal(int r, int c, const vector<vector<int>> &image)
{
    int val = 0;
    for(int i=r-1; i<=r+1; ++i)
    {
        for(int j=c-1; j<=c+1; ++j)
        {
            val += image[i][j];
        }
    }
    return val/9;
}

vector<vector<int>> solution(vector<vector<int>> image) {
    int row = image.size();
    int col = image[0].size();
    vector<vector<int>> result;
    
    for(int i=1; i<row-1; ++i)
    {
        vector<int> temp;
        for(int j=1; j<col-1; ++j)
        {
            temp.push_back(getVal(i, j, image));
        }
        result.push_back(temp);
    }
    
    return result;
}

