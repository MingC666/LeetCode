/*
For code = "010010000110010101101100011011000110111100100001", the output should be
solution(code) = "Hello!".

The first 8 characters of the code are 01001000, which is 72 in the binary numeral system. 72 stands for H in the ASCII-table, so the first letter is H.
Other letters can be obtained in the same manner.

*/
string solution(string code) {
    int index = 0;
    string res = "";
    
    while(index<code.size())
    {
        string sub_code = code.substr(index, 8);
        // decode the sub_code
        int val = 0;
        for(int i=7, j=0; i>=0; --i, ++j)
        {
            if(sub_code[i] == '1')
            {
                val += pow(2,j);
            }
        }
        res += char(val);
        index += 8;
    }
    
    return res;
}

