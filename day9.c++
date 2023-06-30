//rain water problem 
//  #include <bits/stdc++.h> 
//  long getTrappedWater(long *arr, int n){
//      // Write your code here.
//      long *left=new long[n];
//      long *right=new long[n];
//      left[0]=0;//because at leftmost block water never be trapped
//      for(int i=1;i<n;i++){
//          left[i]=max(arr[i],left[i-1]);
//      }
//      right[n-1]=arr[n-1];
//      for(int i=n-2;n>=0;i--){
//          right[i]=max(arr[i],right[i+1]);
//      }
//      long ans=0;
//      for(int i=0;i<n;i++){
//          ans+=(min(left[i],right[i])-arr[i]);
//      }
//       delete[] left;
//       delete[] right;
//      return ans;
//  }
//brutforce approch
/*
    Time Complexity : O(N^2)
    Space Complexity : O(1)

    Where N is the total number of elevations.
*/
  #include <bits/stdc++.h> 
/*
    Time Complexity : O(N)
    Space Complexity : O(N)

    Where N is the total number of elevations.
*/

long getTrappedWater(long* arr, int n) {

    // Base case.
    if (n == 0) {
        return 0;
    }

    // Result.
    long totalWaterStored = 0L;

    // Storing leftMax and rightMAx.
    long* leftMax = new long[n]();
    long* rightMax = new long[n]();

    leftMax[0] = arr[0];

    // Filling leftMax.
    for (int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i - 1], arr[i]);
    }

    rightMax[n - 1] = arr[n - 1];

    // Filling rightMax.
    for (int i = n - 2; i >= 0; i--) {
        rightMax[i] = max(arr[i], rightMax[i + 1]);
    }

    // Calculate result.
    for (int i = 1; i < n - 1; i++) {
        totalWaterStored += min(rightMax[i], leftMax[i]) - arr[i];
    }

    delete[] leftMax;
    delete[] rightMax;

    return totalWaterStored;
}
//stack usim=ng array

/*
    Time complexity: O(1)
    Space complexity: O(N)
    
    Where 'N' is the capacity of the stack.
*/

// Stack class.
class Stack {
    
public:
    
    // Declare array.
    vector<int> myStack;
    
    // Stack size.
    int stackSize;
    
    // Maximum size.
    int n;
    
    // Constructor function.
    Stack(int n) {
    
        // Initialize class objects.
        this -> myStack.resize(n);
        this -> stackSize = -1;
        this -> n = n;
    }

    // Push function.
    void push(int num) {
        
        // Check if stack is not full.
        if(stackSize != n - 1) {
            
            // Increment stack size and update array.
            ++stackSize;
            myStack[stackSize] = num;
        }
    }

    // Pop function.
    int pop() {

        // Check if stack is not empty.
        if(stackSize != -1) {
            
            // Decrease size and return element.
            --stackSize;
            return myStack[stackSize + 1];
        }
        else {
            return -1;
        }
    }
    
    // Top function.
    int top() {
        
        // Check if stack is not empty.
        if(stackSize != -1) {
            
            // Return element.
            return myStack[stackSize];
        }
        else {
            return -1;
        }
    }
    
    // To check whether stack is empty or not.
    int isEmpty() {
        
        // Check if stack is not empty.
        if(stackSize != -1) {
            
            // Return element.
            return 0;
        }
        else {
            return 1;
        }        
    }
    
    // To check whether stack is full or not.
    int isFull() {
        
        // Check if stack is not empty.
        if(stackSize != n - 1) {
            
            // Return element.
            return 0;
        }
        else {
            return 1;
        }        
    }
};