//2 SUM PROBLEM 
//problem link https://www.codingninjas.com/studio/problems/reading_6845742?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
//code--
string read(int n, vector<int> book, int target)
{
    // Write your code here.
    if(target==1){
        return "NO";
    }
    sort(book.begin(),book.end());
    for(int i=0;i<n;i++){
        if((book[i]+book[i+1])>=target){
            return "YES";
        }
    }
    return "NO";
}

//4 sum problem 



//largest sum array sum
//code---
#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
 // vector<int>ans;
 int n=arr.size();
unordered_map<int,int> mpp; 
    int maxi = 0;
    int sum = 0; 
    for(int i = 0;i<n;i++) {
        sum += arr[i]; 
        if(sum == 0) {
            maxi = i + 1; 
        }
        else {
            if(mpp.find(sum) != mpp.end()) {
                maxi = max(maxi, i - mpp[sum]); 
            }
            else {
                mpp[sum] = i;
            }
        }   
    }

    return maxi; 

}

//longest successive elements 
int longestSuccessiveElements(vector<int>&a) {
    // Write your code here.
    if(a.empty()){
        return 0;
    }
    sort(a.begin(),a.end());
    int currlen=1,maxlen=1;
    int n=a.size();
    vector<int>ans;
    for(int i=1;i<n;i++){
       if(a[i]==a[i-1]+1){
           currlen++;
       }else if(a[i]!=a[i-1]){
          currlen=1;
       }
       maxlen=max(maxlen,currlen);
    }
    return maxlen;
}
