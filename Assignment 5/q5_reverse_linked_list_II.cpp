//https://www.interviewbit.com/problems/reverse-link-list-ii/
//https://leetcode.com/problems/reverse-linked-list-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* head, int left, int right) 
{
        if (head == nullptr || left == right) {
            // If the list is empty or no need to reverse since left == right
            return head;
        }

        // Step 1: Create a dummy node to handle edge cases
        ListNode* dummy = new ListNode(0);  // Dummy node to ensure we can handle head changes
        dummy->next = head;
        
        // Step 2: Move `leftPre` to the node just before position `left`
        ListNode* leftPre = dummy;  // Points to the node just before the start of the sublist
        ListNode* currNode = head;  // The current node, starting from the head
        for (int i = 1; i < left; ++i) {
            if (leftPre == nullptr) {
                // If `left` is out of bounds
                return nullptr;
            }
            leftPre = leftPre->next;
            currNode = currNode->next;
        }

        // `currNode` is now at position `left`, and `leftPre` is just before `left`

        ListNode* subListHead = currNode;  // This marks the starting node of the sublist to reverse
        ListNode* preNode = nullptr;       // To hold the previous node while reversing

        // Step 3: Reverse the sublist between `left` and `right`
        for (int i = 0; i < right - left + 1; ++i) {
            ListNode* nextNode = currNode->next;  // Temporarily store the next node
            currNode->next = preNode;             // Reverse the link
            preNode = currNode;                   // Move the `preNode` forward
            currNode = nextNode;                  // Move `currNode` forward
        }

        // Step 4: Reconnect the reversed sublist back into the original list
        leftPre->next = preNode;  // Connect the node before `left` to the `preNode`, which is now the new head of the reversed sublist
        subListHead->next = currNode;  // Connect the original `left` node (now `subListHead`) to `currNode`, the node after `right`

        // Step 5: Return the new head of the list (handle the case where the head might have changed)
        return dummy->next;
    }
