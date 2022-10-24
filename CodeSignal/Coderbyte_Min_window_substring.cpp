/*
Input: {"ahffaksfajeeubsne", "jefaa"}
Output: aksfajeInput: {"ahffaksfajeeubsne", "jefaa"}
Output: aksfaje
*/
#include <iostream>
#include <string>
#include <limits.h>
#include <unordered_map>
using namespace std;

bool checking(unordered_map<char, int> &mp)
{
  for(auto it:mp)
    if(it.second > 0)
      return false;
    return true;
}

string MinWindowSubstring(string strArr[], int arrLength) {
  string s = strArr[0];
  string target = strArr[1];
  unordered_map<char, int> mp;
  for(auto c:target) mp[c]++;

  int left = 0;
  int start_index = -1;
  int result = INT_MAX;
  bool findall = false;
  for(int end=0; end<s.size(); end++)
  {
    if(mp.count(s[end]))
    { 
      if(left==-1) 
        left = end;
      mp[s[end]]--;
      findall = checking(mp);
    }

  
    while(findall)
    {
      if(result > end-left+1)
      {
        start_index = left;
        result = end-left+1;
      }
 //cout << left << ":"<<s[left] << " and " << end << ":" << s[end]<<endl;
      // remove the first match 
      mp[s[left]]++;
      left++;
      findall = checking(mp);
      
      // move left to new match location
      while(!mp.count(s[left]))
      {
        left++;
      }
    }
  }

  if(result!=-1)
    return s.substr(start_index, result);
  
  return "";
}

int main(void) { 
   
  // keep this function call here
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << MinWindowSubstring(A, arrLength);
  return 0;
    
}
