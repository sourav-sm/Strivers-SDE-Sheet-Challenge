//reverse a linked list
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)return NULL;
        if(head->next==NULL)return head;

        ListNode *newHead=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;

        return newHead;
    }
};

//***********find middle of the linked list********/
/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node *findMiddle(Node *head) {
    // Write your code here
   //Node *temp=head;
   Node *slow=head;
   Node *fast=head;
   while(fast!=NULL && fast->next!=NULL){
       slow=slow->next;
       fast=fast->next->next;///the main idea behind this is by this when fast reaches to NULL
       //or go outside then slow reaches to mid
   }
   return slow;
}

//***********merge two sorted linked list*************/
#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

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

//**************Remove nth node from the linked list***********/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) {
            return nullptr;
        }
        
        int len = 0;
        ListNode* temp = head;
        
        // Calculate the length of the linked list
        while (temp != nullptr) {
            len++;
            temp = temp->next;
        }
        
        // If n is greater than the length of the list, no removal is needed
        if (n > len) {
            return head;
        }
        
        int pos = len - n; // Position of the node to remove from the beginning
        
        // Handle the case where the head needs to be removed
        if (pos == 0) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        
        // Find the node before the one to be removed
        temp = head;
        for (int i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }
        
        // Remove the nth node from the end
        ListNode* toRemove = temp->next;
        temp->next = toRemove->next;
        delete toRemove;
        
        return head;
    }
};

/*******************Add two number as a linked list**********/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummyHead=new ListNode(0);//dummy node to hold the result
        ListNode *current=dummyHead;
        int carry=0;
        
        while(l1!=nullptr || l2!=nullptr){
            int x=(l1!=nullptr)?l1->val:0;
            int y=(l2!=nullptr)?l2->val:0;

            int sum=x+y+carry;
            carry=sum/10;

            current->next=new ListNode(sum%10);
            current=current->next;
            if(l1!=nullptr)l1=l1->next;
            if(l2!=nullptr)l2=l2->next;
        }
        if(carry>0){
            current->next=new ListNode(carry);
        }
        return dummyHead->next;
    }
};


/******************delete node in the linked list********/
void deleteNode(LinkedListNode<int> * node) {
    // Write your code here.
    node->data=node->next->data;
    node->next=node->next->next;
    return;
}
