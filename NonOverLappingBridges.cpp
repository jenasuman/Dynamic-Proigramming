#include <bits/stdc++.h>
#include <stdint.h>
using namespace std;
#define int int64_t
//You can solve it in O(N*N) but the optimal way to solve it is O(N*Log(N))
int non_overlapping_bridges(vector<pair<int,int>>& temp,int n){
  
  sort(begin(temp),end(temp));
  
  vector<int> dp;
  dp.push_back(temp[0].second);
  for(int i=1;i<n;i++)
  {    if(dp.back()<temp[i].second){
         dp.push_back(temp[i].second);
       }
       else{
          int index=lower_bound(begin(dp),end(dp),temp[i].second)-begin(dp);
          dp[index]=temp[i].second;
       }
  }
  return dp.size();
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int mod=998244353;
    
    int n=4;
    vector<pair<int,int>> temp;
    temp.push_back(make_pair(6,2));
    temp.push_back(make_pair(4,3));
    temp.push_back(make_pair(2,6));
    temp.push_back(make_pair(1,5));
     
    cout<<non_overlapping_bridges(temp,n)<<endl;
    
   	return 0;
}