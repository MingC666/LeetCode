/*
For inputString = "aabb", the output should be
solution(inputString) = true.

We can rearrange "aabb" to make "abba", which is a palindrome.
*/

bool solution(string inputString) {
    vector<short> memo(26, 0);
    
    for(auto c:inputString)
    {
        memo[c-'a'] ++;
    }
    
    short odd = 0;
    
    for(auto i:memo)
    {
        if(i%2 == 1)
            odd++;
        if(odd>1)
            return false;
    }
    
    return true;
}
