/*
For inputString = "00-1B-63-84-45-E6", the output should be
solution(inputString) = true;
For inputString = "Z1-1B-63-84-45-E6", the output should be
solution(inputString) = false;
For inputString = "not a MAC-48 address", the output should be
solution(inputString) = false.  
*/
bool solution(string inputString) {
    regex ex("([0-9|A-F]{2}-){5}[0-9|A-F]{2}");
    return regex_match(inputString, ex);
}

