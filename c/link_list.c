/**
 * Definition for singly-linked list.
 */
 struct ListNode {
     int val;
     struct ListNode *next;
 };

#define NULL (void *)0


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode tmp;
    struct ListNode *tmp_prev;

    tmp_prev = &tmp;

    while ((l1 != NULL) && (l2 != NULL))
    {
        if (l1->val < l2->val)
        {
            tmp_prev->next = l1;
            l1 = l1->next;
        }
        else
        {
            tmp_prev->next = l2;
            l2 = l2->next;
        }
        tmp_prev = tmp_prev->next;
    }

    tmp_prev->next = (l1 == NULL) ? l2 : l1;
    
    return tmp.next;
}

struct ListNode *new(int a)
{
    struct ListNode *n;

    n = malloc(sizeof(struct ListNode));
    n->val = a;
    n->next = NULL;
}

int main()
{
    struct ListNode *a;
    struct ListNode *b;

    a = new(1);
    a->next = new(2);
    a->next->next = new(4);

    b = new(1);
    b->next = new(3);
    b->next->next = new(4);

    return mergeTwoLists(a, b);
}