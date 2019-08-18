
#define TEST    1


#ifdef TEST
#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
     int val;
     struct ListNode *next;
};

#endif

static struct ListNode *listNodeInit(int val)
{
    struct ListNode *new;

    new = malloc(sizeof(struct ListNode));
    if (new == NULL)
    {
        return NULL;
    }
    else
    {
        new->val = val;
        new->next = NULL;
        return new;
    }
}

static void listNodeShow(struct ListNode *list)
{
    struct ListNode *next;

    if (list == NULL)
    {
        return;
    }

    while (list)
    {
        next = list->next;
        printf("%d  ", list->val);
        list = next;
    }
    printf("\n");

    return;
}

static void listNodeDestory(struct ListNode *list)
{
    struct ListNode *next;

    if (list == NULL)
    {
        return;
    }

    while (list)
    {
        next = list->next;
        free(list);
        list = next;
    }

    return;
}

static void listNodeAddTail(struct ListNode *prev, struct ListNode *new)
{
    while (prev)
    {
        if (prev->next == NULL)
        {
            prev->next = new;
            new->next = NULL;
        }
        prev = prev->next;
    }
}

static struct ListNode *listNodeInitArray(int *arr, int size)
{
    int i;
    struct ListNode *list = NULL;
    struct ListNode *node = NULL;

    for (i = 0; i<size; i++)
    {
        node = listNodeInit(arr[i]);
        if (node == NULL)
        {
            listNodeDestory(list);
            return NULL;
        }

        if (list == NULL)
        {
            list = node;
        }
        else
        {
            listNodeAddTail(list, node);
        }
    }

    return list;
}


struct ListNode* addTwoNumbers(struct ListNode* pl1, struct ListNode* pl2){
    struct ListNode *merge = NULL;
    struct ListNode *list = NULL;
    struct ListNode *node = NULL;
    struct ListNode *next = NULL;
    struct ListNode *l1 = pl1;
    struct ListNode *l2 = pl2;
    int sum;
    int inc = 0;
    int last_inc = 0;

    while (l1 && l2)
    {
        sum = l1->val + l2->val + last_inc;

        if (sum >= 10)
        {
            sum = sum - 10;
            inc = 1;
        }
        else
        {
            inc = 0;
        }

        node = listNodeInit(sum);
        if (merge == NULL)
        {
            merge = node;
        }
        else
        {
            listNodeAddTail(merge, node);
        }

        last_inc = inc;
    
        l1 = l1->next;
        l2 = l2->next;
    }

    if (l1)
    {
        list = l1;
    }
    else if(l2)
    {
        list = l2;
    }

    if (list)
    {
        while(list)
        {
            next = list->next;

            sum = last_inc + list->val;
            if (sum >= 10)
            {
                sum = sum - 10;
                inc = 1;
            }
            else
            {
                inc = 0;
            }

            node = listNodeInit(sum);
            if (merge != NULL)
            {
                listNodeAddTail(merge, node);
            }
            else
            {
                merge = node;
            }
            list = list->next;

            last_inc = inc;
        }
    }
    
    if (last_inc)
    {
        node = listNodeInit(last_inc);
        if (merge != NULL)
        {
            listNodeAddTail(merge, node);
        }
        else
        {
            merge = node;
        }
    }
    
    return merge;
}



#ifdef TEST
int main(int argc, char **argv)
{
    struct ListNode *sum;
    struct ListNode *l1;
    struct ListNode *l2;

    //int a1[] = {2, 4, 6};
    //int a2[] = {5, 6, 4, 5, 7};
    //int a2[] = {5, 6, 4};
    //int a2[] = {5, 6, 2};
    int a1[] = {1};
    int a2[] = {9, 9};


    l1 = listNodeInitArray(a1, sizeof(a1) / sizeof(a1[0]));
    l2 = listNodeInitArray(a2, sizeof(a2) / sizeof(a2[0]));

    sum = addTwoNumbers(l1, l2);

    listNodeShow(l1);
    listNodeShow(l2);
    listNodeShow(sum);
}

#endif
