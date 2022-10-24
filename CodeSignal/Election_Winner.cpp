int solution(vector<int> votes, int k) {
    int count = 0;
    int t_max = *max_element(votes.begin(), votes.end());
    int n = 0;
    for(auto i: votes)
    {
        if(i+k > t_max)
        {
            count++;
        }
        if(i == t_max) n++;
    }
    
    if(count==0 && n==1) return 1;
    return count; 
}

int v1(vector<int> votes, int k) {
    sort(votes.begin(), votes.end());
    int n = votes.size();
    int t_max = votes[n-1];
    int count = 0;
    
    int i = n-1;
    for(; i>=0; i--)
    {        cout << votes[i]+k << endl;
        if(votes[i]+k > t_max) 
            count++;
        else {
            break;
        }
    }
    if(count==0 && n>2 && votes[i]>votes[i-1]) return 1;
    
    return count; 
}




