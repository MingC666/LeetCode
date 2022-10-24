int solution(vector<vector<int>> matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    
    // save the sub-matrix as string;
    unordered_set<int> storage;
    for(int i=0; i<row-1; ++i)
    {
        for(int j=0; j<col-1; ++j)
        {
            int temp = 0;
            if(i+1<row && j+1<col)
            {
                temp += matrix[i][j];
                temp = temp*10 + matrix[i][j+1];
                temp = temp*10 + matrix[i+1][j];
                temp = temp*10 + matrix[i+1][j+1];
                storage.insert(temp);
            }
        }
    }
    return storage.size();
}

