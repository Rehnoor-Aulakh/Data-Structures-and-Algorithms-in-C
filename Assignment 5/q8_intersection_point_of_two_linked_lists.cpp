// https://www.geeksforgeeks.org/write-a-function-to-get-the-intersection-point-of-two-linked-lists/
// https://leetcode.com/problems/intersection-of-two-linked-lists/

/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Algorithm:
//There are many approaches to solve this question
//Brute force method is to fix one pointer i and iterate j through the whole linked list and when i==j, return i, otherwise i=i->next. Time Complexity O(M*N), Space Complexity O(1)
//Hashing Method: Store the first linked list in a hash map and then iterate through the second linked list finding the same node if it is there. Time Complexity O(M+N), Space Complexity O(M+N)
//Yet better approach is to find the sizes of both the Linked Lists and then which ever is larger, place i and j pointers where the size of both is same
// Increment i and j together and if anywhere i==j, then return i. If loop ends, return -1

class Solution {
  public:
    // Function to find intersection point in Y shaped Linked Lists.
    int intersectPoint(Node* headA, Node* headB) 
    {
        //First find the size of both the linked lists
        Node *i=headA;
        int size1=0,size2=0;
        Node *j=headB;
        while(i!=NULL)
        {
            size1++;
            i=i->next;
        }   
        while(j!=NULL)
        {
            size2++;
            j=j->next;
        }
        //find the difference in the sizes
        int diff;
        i=headA;
        j=headB;
        if(size1>size2)
        {
            diff=size1-size2;
            for(int k=0;k<diff;k++)
            {
                i=i->next;
            }
        }
        else if(size1<size2)
        {
            diff=size2-size1;
            for(int k=0;k<diff;k++)
            {
                j=j->next;
            }
        }
        //Now i and j are at their correct positions and the size to be compared is same
        while(i!=NULL)
        {
            if(i==j)
            {
                return i->data;
            }
            else
            {
                i=i->next;
                j=j->next;
            }
        }
        return -1;
                
    }
};