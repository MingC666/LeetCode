#include <iostream>
#include <vector>
#include <algorithm>
#include <queue> 
using namespace std;
/*
Given an array  of meeting time intervals where intervals[i] = [start_i, end_i], return the minimum number of people needed to attend all meetings. One people can attend two meetings if there is no conflict between such two meetings.
Input: nums = [[0, 30], [15, 20], [5, 10]]
Output: 2
// 2 meeting most for a person
*/ 

int checking(vector<vector<int>> meetings)
{
  
  // sort the meeting
  sort(meetings.begin(), meetings.end());
  //     QUETION 1
  // {0, 30,}, {15, 20}, {30, 40}, {0, 100}, {50, 60}
  // {0, 10},  {0, 10}, {10, 20}, {20, 50},    // false
  // {0, 10}, {10, 15}, {20, 20}        //true
  // for(int i=1; i<meetings.size(); i++)
  //   {
  //     if(meetings[i][0] < meetings[i-1][1])
  //     {
  //       return false;
  //     }
  //   }
  
  // 2. put then end time of the meeing  int to queue
  // {0, 30,}, {0, 100},  {15, 20}, {30, 40}, , {50, 60}
  // {0, 30}, {15, 20}
  // {0, 100} {30, 40}
  // {40, 60}



  // QUESTION 2
  /*
    Given an array  of meeting time intervals where intervals[i] = [start_i, end_i], return the minimum number of people needed to attend all meetings. One people can attend two meetings if there is no conflict between such two meetings.
Input: nums = [[0, 30], [15, 20], [5, 10]]
Output: 2
  */
  priority_queue<int, vector<int>, greater<int>> pq;  // rank the early finish time in front
  
  // base case 
  if(meetings.size() == 0) return 0;
  if(meetings.size() == 1) return 1;
  
  //   {0, 10},    {5, 30}, {10, 15}, {20, 20}, 
  pq.push(meetings[0][1]);
  for(int i=1; i< meetings.size(); i++)
    {
      // adding new end_time of the meeting if it need a new person to join
      // if the start_time of the meeting are in OR later than earlest end meeting, we pop
      // the earlest one meeting and add new end_time to 'pq'
      if(meetings[i][0] >= pq.top())
      {
        pq.pop();
        pq.push(meetings[i][1]);
      }
      // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
      else        // forgot the ELSE statment, wichi will push all endtime to the 'pq'......
        pq.push(meetings[i][1]);

    }
  
  return pq.size();
  
}
int main() {
  // vector<vector <int>> input{ {0, 10}, {10, 15}, {20, 20}, {5, 30}}; 2
  //vector<vector <int>> input{ {0,30}, {15, 20}, {5, 10}};    // 2
  // vector<vector <int>> input{ {0, 10}, {10, 15}, {15, 20}, {20, 100}};  // 1
  vector<vector <int>> input{ {0, 10}, {10, 15}, {15, 20}, {20, 100}, {17, 30}};  // 2
  cout << checking(input);
}
