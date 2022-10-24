/*
For names = ["doc", "doc", "image", "doc(1)", "doc"], the output should be
solution(names) = ["doc", "doc(1)", "image", "doc(1)(1)", "doc(2)"].
*/
vector<string> solution(vector<string> names) {
    vector<string> res;
    unordered_set<string> files;
    for(string s:names)
    {
        string temp = s;
        if(files.count(s))
        {
            int i = 0;
            while(files.count(temp))
            {
                temp = s + "(" + to_string(++i) + ")";
            }
        }
        files.insert(temp);
        res.push_back(temp);
    }
    return res;
}

