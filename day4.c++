//intersection point of a ll
Node* findIntersection(Node* firstHead, Node* secondHead) {
    if (firstHead == NULL || secondHead == NULL)
        return NULL;

    Node* a = firstHead;
    Node* b = secondHead;

    while (a != b) {
        a = (a == NULL) ? firstHead : a->next;
        b = (b == NULL) ? secondHead : b->next;
    }

    return a;
}

//detect cycle
bool detectCycle(Node* head) {
    if (head == NULL) {
        return false;
    }

    Node* fast = head;
    Node* slow = head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            return true;
        }
    }

    return false;
}

///palindom of a linked list
//normal apporach
/*
time complexity:O(N)
space complexity:O(N)
*/
bool isPalindrome(node* head) {
    vector<int> arr;
    while(head != NULL) {
        arr.push_back(head->num);
        head = head->next;
    }
    for(int i=0;i<arr.size()/2;i++) 
        if(arr[i] != arr[arr.size()-i-1]) return false;
    return true;
}
//optimal code 
/*
time complexity:O(N/2)
space complexity:O(1)
*/
#include <bits/stdc++.h> 

LinkedListNode<int>* reverse(LinkedListNode<int>* ptr) {
    LinkedListNode<int>* pre=NULL;
    LinkedListNode<int>* nex=NULL;
    while(ptr!=NULL) {
        nex = ptr->next;
        ptr->next = pre;
        pre=ptr;
        ptr=nex;
    }
    return pre;
}
bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    if(head==NULL||head->next==NULL) return true;
        
    LinkedListNode<int>* slow = head;
    LinkedListNode<int>* fast = head;
        
    while(fast->next!=NULL&&fast->next->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = reverse(slow->next);
    slow = slow->next;
    LinkedListNode<int>* dummy = head;
        
    while(slow!=NULL) {
        if(dummy->data != slow->data) return false;
        dummy = dummy->next;
        slow = slow->next;
    }
    return true;

}

//Flatten A Linked List
Node* mergeTwoLists(Node* a, Node* b) {
    Node *dummy = new Node(); // Dummy node to simplify the merging process
    Node *tail = dummy;

    while (a && b) {
        if (a->data < b->data) {
            tail->child = a;
            a = a->child;
        } else {
            tail->child = b;
            b = b->child;
        }
        tail->child->next = nullptr; // Set the next pointer to null after merging
        tail = tail->child;
    }

    // Append the remaining nodes, if any
    if (a) {
        tail->child = a;
    } else {
        tail->child = b;
    }

    return dummy->child; // Return the merged list excluding the dummy node
}

Node* flattenLinkedList(Node* head) 
{
   
        if (head == NULL || head->next == NULL) 
            return head; 
  
        // recur for list on right 
        head->next = flattenLinkedList(head->next); 
  
        // now merge 
        head = mergeTwoLists(head, head->next); 
  
        // return the root 
        // it will be in turn merged with its left 
        return head; 
}

//rotate a linked list
 Node *rotate(Node *head, int k) {
    if(head == NULL||head->next == NULL||k == 0) return head;
    //calculating length
    Node* temp = head;
    int length = 1;
    while(temp->next != NULL) {
        ++length;
        temp = temp->next;
    }
    //link last node to first node
    temp->next = head;
    k = k%length; //when k is more than length of list
    int end = length-k; //to get end of the list
    while(end--) temp = temp->next;
    //breaking last node link and pointing to NULL
    head = temp->next;
    temp->next = NULL;
        
    return head;

}