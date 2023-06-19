//maximum activities
#include<bits/stdc++.h>
using namespace std;
int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    int n=start.size();
    vector<pair<int,int>>activities;

    for(int i=0;i<n;i++){
        activities.push_back({finish[i],start[i]});
    }

    sort(activities.begin(),activities.end());

    int count=1;
    int lastactivity=activities[0].first;
    for(int i=1;i<n;i++){
        if(activities[i].second>=lastactivity){
            count++;
            lastactivity=activities[i].first;
        }
    }
    return count;
}

//maximum meetings
#include <bits/stdc++.h> 
struct meeting{
    int start;
    int end;
    int position;
};
bool static comparaor(struct meeting m1,meeting m2){
  if(m1.end<m2.end)return true;
  else if(m1.end>m2.end)return false;
  else if(m1.position<m2.position)return true;
  return false;
  }
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    int n=start.size();
    struct meeting meet[n];
    for(int i=0;i<n;i++){
        meet[i].start=start[i],meet[i].end=end[i],meet[i].position=i+1;
    }
    sort(meet,meet+n,comparaor);

    vector<int>ans;
    int limit=meet[0].end;
    ans.push_back(meet[0].position);

    for(int i=1;i<n;i++){
        if(meet[i].start>limit){
            ans.push_back(meet[i].position);
            limit=meet[i].end;
        }
    }
    return ans;
}

//minimum number of platforms
int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at,at+n);
    sort(dt,dt+n);

    int i=1,j=0,count=1,ans=1;
    while(i<n && j<n){
        if(at[i]<=dt[j]){
            count++;
            i++;//means we need one more platform
        }else{
            count--;
            j++;
        }
        ans=max(ans,count);
    }
    return ans;
}

//fractional knaspsack
#include <bits/stdc++.h> 
bool compare(pair<int, int>& a, pair<int, int>& b)
{
    double r1 = (double) a.second / a.first;
    double r2 = (double) b.second / b.first;

    return r1 > r2;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(), items.end(), compare);

    double maxValue = 0;
    int currWeight = 0;

    for (int i = 0; i < n; i++)
    {
        if (currWeight + items[i].first <= w)
        {
            currWeight += items[i].first;
            maxValue += items[i].second;
        }
        else
        {
            int remainingWeight = w - currWeight;

            // Pick a fraction of current item.
            maxValue += items[i].second * ((double)remainingWeight / items[i].first);
            break;
        }
    }
    return maxValue;
}
