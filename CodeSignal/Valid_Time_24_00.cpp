
/*
For time = "13:58", the output should be
solution(time) = true;
For time = "25:51", the output should be
solution(time) = false;
For time = "02:76", the output should be
solution(time) = false.
*/
bool solution(string time) {
    //checking length
    int n=time.size();
    if(n != 5) return false;
    if(time[2] != ':') return false;
    
    int hour = 0;
    int min = 0;
    if(isdigit(time[0]) && isdigit(time[1]))
    {
        hour = stoi(time.substr(0,2));
        if(hour>23) return false;
    }
    else 
        return false;
    if(isdigit(time[3]) && isdigit(time[4]))
    {
        min = stoi(time.substr(3,2));
        if(min >= 60) return false;
    }
    else {
        return false;
    }
    return true;
}

bool v2(string time) {
    regex pattern("([01]?[0-9]|2[0-3]):[0-5][0-9]");
    return regex_match(time, pattern);
}

bool v3(string time) {
    //checking length
    return stoi(time.substr(0,2))<24 && stoi(time.substr(3,2))<60;
}
