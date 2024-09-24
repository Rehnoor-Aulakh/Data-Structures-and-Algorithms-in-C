// https://www.interviewbit.com/problems/rotate-list/
// https://leetcode.com/problems/rotate-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* head, int k) 

    {
        if(head==NULL || head->next==NULL ||k==0)
        {
            return head;
        }
        //first find the length of the linked list
        int length=0;
        ListNode *temp=head;
        while(temp!=NULL)
        {
            length++;
            temp=temp->next;
        }
        //Minimalize the value of k
        k=k%length;
        if(k==0)
        {
            return head;
        }
        //Algorithm::
        //We have to divide the linked list into 2 parts
        //move the pointer to length-k, which will be the new tail and the next pointer to it will be the new head
        //separate these two by newTail->next=NULL and attach the head of old linked list to the tail of the second half
        ListNode *newTail=head;
        for(int i=1;i<(length-k);i++)
        {
            newTail=newTail->next;
        }
        ListNode *newHead=newTail->next;
        newTail->next=NULL;
        //Now go to the end of 2nd linked list and attatch the head to it
        temp=newHead;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=head;
        return newHead;
    }
