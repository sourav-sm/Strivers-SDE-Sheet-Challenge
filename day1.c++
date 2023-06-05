//set matrix zero
#include <bits/stdc++.h>
	// Write your code here.
	void setZeros(vector<vector<int>>& matrix) {
	// Write your code here.
    int n=matrix.size();
    int m=matrix[0].size();
	int row[n]={0};
	int col[m]={0};
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(matrix[i][j]==0){
				row[i]=1;
				col[j]=1;
			}
		}
	}
   //re trivarse
   for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(row[i]==1 || col[j]==1){
				matrix[i][j]=0;
			}
		}
	}
}
//best time to buy stock and sell
#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int maxProfit=0;
    int minPrice=INT_MAX;
    for(int i=0;i<prices.size();i++){
        minPrice=min(minPrice,prices[i]);
        maxProfit=max(maxProfit,prices[i]-minPrice);
    }
    return maxProfit;
}
//majoriy element
#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	map<int,int> m;

	for(int i=0;i<n;i++){
		m[arr[i]]++;
	}

	for(auto it:m){
		if(it.second>(n/2)){
			return it.first;
		}
	}
	return -1;

}
//majority element 2
#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    int n=arr.size();
    vector<int>ls;

    map<int,int>m;
    int mini=int(n/3)+1;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
        if(m[arr[i]]==mini){
            ls.push_back(arr[i]);
        }
        if(ls.size()==2)break;
        }
    return ls;
}
