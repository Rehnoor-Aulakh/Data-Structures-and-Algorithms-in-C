// https://www.geeksforgeeks.org/adding-two-polynomials-using-linked-list/

/* Structure of Node used
struct Node
{
    int coeff;
    int pow;
    struct Node* next;

    Node(int c, int p){
        coeff = c;
        pow = p;
        next = NULL;
    }
};
*/

class Solution {
  public:
    /* The below method print the required sum of polynomial
    p1 and p2 as specified in output  */
    Node *addPolynomial(Node *head1, Node *head2) 
    {
        // Handle cases where one of the lists is empty
        if (head1 == NULL) return head2;
        if (head2 == NULL) return head1;

        Node *prevI = NULL;
        Node *i = head1;
        Node *j = head2;

        while (i != NULL && j != NULL) {
            if (i->pow > j->pow) {
                prevI = i;
                i = i->next;
            } 
            else if (j->pow > i->pow) {
                Node *temp = j;
                j = j->next;

                // Insert temp before the current i
                if (prevI == NULL) {
                    // If prevI is NULL, we're at the head
                    temp->next = head1;
                    head1 = temp; // Update head1
                } else {
                    temp->next = i; // Point to current i
                    prevI->next = temp; // Link previous to new node
                }
                prevI = temp; // Move prevI to temp
            } 
            else { // i->pow == j->pow
                i->coeff += j->coeff; // Add coefficients
                prevI = i; // Move prevI to current i
                i = i->next; // Move to next in head1
                j = j->next; // Move to next in head2
            }
        }

        // If there are remaining nodes in j, attach them
        if (j != NULL) {
            if (prevI == NULL) {
                // If prevI is NULL, we're at the head
                head1 = j; // If head1 was empty
            } else {
                prevI->next = j; // Link remaining nodes
            }
        }

        return head1; // Return the modified head1
    }
};