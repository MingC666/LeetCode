int solution(vector<int> inputArray) {
    int n = inputArray.size();
    
    
    for(int result=2; result<=1000; ++result)
    {
        int i = 0;
        for( ; i<n; ++i)
        {
            if(inputArray[i]%result == 0)
                break;
        }
        if(i==n)
            return result;
        
    }
    return -1;
}

