//delete a node 
void deleteNode(LinkedListNode<int> * node) {
    // Write your code here.
    node->data=node->next->data;
    node->next=node->next->next;
    return;
    
}

//cycle 2 return node
Node *firstNode(Node *head)
{
    //    Write your code here.
    if(head==NULL)return NULL;
    Node* fast=head;
    Node* slow=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if (slow == fast) {
            Node* start = head;
            while (start != slow) {
                start = start->next;
                slow = slow->next;
            }
            return start;
        }
    }
    return NULL;
}