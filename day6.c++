//pascal triangel
#include <bits/stdc++.h>
using namespace std;

int ncr(int n,int r){
  long long res=1;
  for(int i=0;i<r;i++){
    res=res*(n-i);
    res=res/(i+1);
  }
  return (int)(res);
}
vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
  vector<vector<long long int>>ans;
  for(int i=1;i<=n;i++){
    vector<long long int>tlist;
    for(int j=1;j<=i;j++){
      tlist.push_back(ncr(i-1,j-1));
    }
    ans.push_back(tlist);
  }
  return ans;
}
//