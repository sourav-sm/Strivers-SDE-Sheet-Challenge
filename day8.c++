//Find Minimum Number Of Coins
#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    // Write your code here
    int coins[]={1,2,5,10,20,50,100,500,1000};
    int n=9;//total avialable coins=9
    vector<int>ans;
    for(int i=n-1;i>=0;i--){
         while(amount>=coins[i]){
             amount-=coins[i];
             ans.push_back(coins[i]);
         }
    }
    return ans.size();
}

//Job Sequencing Problem
#include <bits/stdc++.h> 
bool compare(vector<int>&a,vector<int>&b){
   return a[1]>b[1];//sort jobs based on their profits
}
int jobScheduling(vector<vector<int>> &jobs)
{
    sort(jobs.begin(), jobs.end(), compare); // Sort the jobs
    
    int maxProfit = 0;
    int n = jobs.size();
    vector<bool> slots(n, false); // Slots to keep track of scheduled jobs
    
    for (int i = 0; i < n; i++) {
        int deadline = jobs[i][0];
        
        // Find a slot for the job starting from its deadline
        for (int j = min(n, deadline) - 1; j >= 0; j--) {
            if (!slots[j]) {
                slots[j] = true; // Schedule the job in the slot
                maxProfit += jobs[i][1]; // Add the profit of the job
                break;
            }
        
    }
    
    return maxProfit;
    
}
