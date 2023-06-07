//find mid of linkedlist
Node *findMiddle(Node *head) {
    // Write your code here
    Node *slow=head;
   Node *fast=head;
   while(fast!=NULL && fast->next!=NULL){
       slow=slow->next;
       fast=fast->next->next;///the main idea behind this is by this when fast reaches to NULL
       //or go outside then slow reaches to mid
   }
   return slow;
}

//reverse liked list
LinkedListNode<int>* reverseLinkedList(LinkedListNode<int>* head) {
    if (head == NULL) {
        return NULL;
    }

    if (head->next == NULL) {
        return head;
    }

    LinkedListNode<int>* newHead = reverseLinkedList(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
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
//merge 2 sorted linked list
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
     if (first == NULL) return second;
    if (second == NULL) return first;

    if (first->data > second->data) std::swap(first, second);

    Node<int>* res = first;

    while (first != NULL && second != NULL) {
        Node<int>* temp = NULL;

        while (first != NULL && first->data <= second->data) {
            temp = first;
            first = first->next;
        }

        temp->next = second;
        std::swap(first, second);
    }

    return res;
    }
 //seacrh in 2d
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int lo = 0;
        if(!mat.size()) return false;
        int hi = (mat.size() * mat[0].size()) - 1;
        
        while(lo <= hi) {
            int mid = (lo+hi)/2;
            if(mat[mid/mat[0].size()][mid % mat[0].size()] == target) {
                return true;
            }
            if(mat[mid/mat[0].size()][mid % mat[0].size()] < target) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return false;
}
//remove dublicates
int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
	int count=0;
	for(int i=0;i<n;i++){
      if(arr[i]==arr[i+1]){
		  count++;
	  }
	}
	return n-count;
}

