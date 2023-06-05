//next permutation
#include <bits/stdc++.h> 
using namespace std;
    //  Write your code here.
vector<int> nextPermutation(vector<int> &permutation, int n){
    int ind = -1; // break point
    for (int i = n - 2; i >= 0; i--) {
        if (permutation[i] < permutation[i + 1]) {
            // index i is the break point
            ind = i;
            break;
        }
    }

    // If break point does not exist:
    if (ind == -1) {
        // reverse the whole array:
        reverse(permutation.begin(), permutation.end());
        return permutation;
    }

    // Step 2: Find the next greater element
    //         and swap it with arr[ind]:

    for (int i = n - 1; i > ind; i--) {
        if (permutation[i] > permutation[ind]) {
            swap(permutation[i], permutation[ind]);
            break;
        }
    }

    // Step 3: reverse the right half:
    reverse(permutation.begin() + ind + 1, permutation.end());

    return permutation;
}

//sort 0 1 2
#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //   Write your code here
   int i=0,nextzero=0,nexttwo=n-1;
   while(i<=nexttwo){
      if(arr[i]==0){
         swap(arr[i],arr[nextzero]);
         i++;
         nextzero++;
      }else if(arr[i]==2){
         swap(arr[i],arr[nexttwo]);
         nexttwo--;
         //i++;
      }else{
         i++;
      }
   }

}
//find dublicates

int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
	int sum=0;
	int sum1=0;
	for(int i=0;i<n;i++){
		sum+=arr[i];
	}
	for(int i=1;i<=n-1;i++){
		sum1+=i;
	}
	return sum-sum1;
}

