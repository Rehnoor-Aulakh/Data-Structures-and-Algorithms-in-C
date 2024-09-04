bool hasCycle(ListNode *head) 
    {
        //Using Floyd's Algorithm of Slow and Fast Pointers
        ListNode *slow=head,*fast=head;
        if(head==NULL)
        {
            return false;
        }
        if(head->next==NULL)
        {
            return false;
        }
        while(slow!=NULL && fast!=NULL)
        {
            fast=fast->next;
            if(fast!=NULL)
            {
                fast=fast->next;
            }
            slow=slow->next;
            if(fast==slow)
            {
                return true;
            }
            
        }
        return false;
    }

    //If you have to return the node at which the cycle is present

    ListNode* hasCycle(ListNode *head)
   {
        //Using Floyd's Algorithm of Slow and Fast Pointers
        ListNode *slow=head,*fast=head;
        if(head==NULL)
        {
            return NULL;
        }
        if(head->next==NULL)
        {
            return NULL;
        }
        while(slow!=NULL && fast!=NULL)
        {
            fast=fast->next;
            if(fast!=NULL)
            {
                fast=fast->next;
            }
            slow=slow->next;
            if(fast==slow)
            {
                cout<<"Cycle is present at "<<slow.data;
                return slow;
            }
            
        }
        return NULL;
    }

    ListNode* getStartingNode(ListNode *head)
    {
        ListNode *intersection=hasCycle(head);
        ListNode *slow=head;
        //We know that mathematically, distance travelled by slow and intersection to reach at beginning point of loop will be same
        while(slow!=intersection)
        {
            slow=slow->next;
            intersection=intersection->next;
        }
        return slow;
    }

    void remove(ListNode *head)
    {
        ListNode *Starting=getStartingNode(head);
        ListNode *temp=Starting;
        while(temp.next!=Starting)
        {
            temp=temp->next;
        }
        temp->next=NULL;
    }