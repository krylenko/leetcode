/**

 * Definition for singly-linked list.

 * struct ListNode {

 *     int val;

 *     struct ListNode *next;

 * };

 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) 

{

    

    

    struct ListNode* endptr = head;

    struct ListNode* nptr = head;

    struct ListNode* nprev = head;

    

    if( head == NULL )

      return NULL;

    

    int i = 1;

    while( endptr->next )

    {

      endptr = endptr->next;

      if(i>=n)

      {

        nprev = nptr;

        nptr = nptr->next;

      }

      ++i;

    }

    

    if( nptr == head )

      head = nptr->next;

    else

      nprev->next = nptr->next;

    

    return head;

    

}
