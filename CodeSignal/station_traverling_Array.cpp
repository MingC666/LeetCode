#include <iostream>
#include <vector>
#include <algorithm>
#include <queue> 
#include <set>
#include <map>
#include <unordered_map>
using namespace std;


void backtracking(int start, set<int> &to_visited, map<int, int> &stations, vector<vector<int>> &p, int &result)
{
    if(to_visited.size()==0)
    {
        result = start;
        return;
    }
    for(int i=0; i<p[start][1]; ++i)
    {
        int cango1 = start+i;
        int cango2 = start-i;
        
        if(to_visited.count(cango1))
        {
            to_visited.erase((cango1));
            backtracking(stations[cango1], to_visited, stations, p, result);
            to_visited.insert((cango1));
        }
        if(to_visited.count(cango2))
        {
            to_visited.erase((cango2));
            backtracking(stations[cango2], to_visited, stations, p, result);
            to_visited.insert((cango2));
        }
    }
}


int truckTour(vector<vector<int>> &petrolpumps) {
  sort(petrolpumps.begin(), petrolpumps.end());
  int n = petrolpumps.size();
  
  int result = -1;

  map<int, int> stations;    // stored paired of <station number, its index>
  set<int> to_visited;
  set<int> nodes;
  for(int i=0; i<n; ++i)
  {
    to_visited.insert(petrolpumps[i][0]);
    stations[petrolpumps[i][0]] = i;
  }
  
//for(auto t:to_visited) cout << t << endl;

  
  for(int i=0; i<n; ++i)
  {
    to_visited.erase(petrolpumps[i][0]);
    backtracking(i, to_visited, stations, petrolpumps, result);
    if(result != -1)
        return result;
    
    to_visited.insert(petrolpumps[i][0]);
  }
  return -1;
}

// find the start position where the station can go over all stations,
// from pairs of <'station #', 'distance it can travel'
// for example, {10, 3}, station #10 can go range of station 7~13
//   vector<vector<int>> v {{10, 3}, {3,4}, {1,5}};     result: 1
int main()
{
  vector<vector<int>> v {{10, 3}, {3,4}, {1,5}, {}};
  int result = truckTour(v);
  cout << result;

  return 0;
}#include <iostream>
#include <vector>
#include <algorithm>
#include <queue> 
#include <set>
#include <map>
#include <unordered_map>
using namespace std;


void backtracking(int start, set<int> &to_visited, map<int, int> &stations, vector<vector<int>> &p, int &result)
{
    if(to_visited.size()==0)
    {
        result = start;
        return;
    }
    for(int i=0; i<p[start][1]; ++i)
    {
        int cango1 = start+i;
        int cango2 = start-i;
        
        if(to_visited.count(cango1))
        {
            to_visited.erase((cango1));
            backtracking(stations[cango1], to_visited, stations, p, result);
            to_visited.insert((cango1));
        }
        if(to_visited.count(cango2))
        {
            to_visited.erase((cango2));
            backtracking(stations[cango2], to_visited, stations, p, result);
            to_visited.insert((cango2));
        }
    }
}


int truckTour(vector<vector<int>> &petrolpumps) {
  sort(petrolpumps.begin(), petrolpumps.end());
  int n = petrolpumps.size();
  
  int result = -1;

  map<int, int> stations;    // stored paired of <station number, its index>
  set<int> to_visited;
  set<int> nodes;
  for(int i=0; i<n; ++i)
  {
    to_visited.insert(petrolpumps[i][0]);
    stations[petrolpumps[i][0]] = i;
  }
  
//for(auto t:to_visited) cout << t << endl;

  
  for(int i=0; i<n; ++i)
  {
    to_visited.erase(petrolpumps[i][0]);
    backtracking(i, to_visited, stations, petrolpumps, result);
    if(result != -1)
        return result;
    
    to_visited.insert(petrolpumps[i][0]);
  }
  return -1;
}

// find the start position where the station can go over all stations,
// from pairs of <'station #', 'distance it can travel'
// for example, {10, 3}, station #10 can go range of station 7~13
//   vector<vector<int>> v {{10, 3}, {3,4}, {1,5}};     result: 1
int main()
{
  vector<vector<int>> v {{10, 3}, {3,4}, {1,5}, {}};
  int result = truckTour(v);
  cout << result;

  return 0;
}