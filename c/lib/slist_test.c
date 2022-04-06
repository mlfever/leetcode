/*
 * single list struct test
 */

#include "slist.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct nslist_num
{
    slist_t node;
    int num;
} slist_num_t;

slist_head_t g_head;

int add_nums(slist_head_t *head, int *nums, int num_size)
{
    int i;
    slist_num_t *node;

    for (i = 0; i < num_size; i++)
    {
        node = malloc(sizeof(slist_num_t));
        assert(node != NULL);
        node->num = nums[i];
        slist_add_head(head, node);
    }
}

int show_nums(slist_head_t *head, int *nums, int num_size)
{
    int i;
    slist_num_t *node;

    printf("nums:");

    node = head->next;
    for (i = 0; i < num_size; i++)
    {
        if (node != NULL)
        {
            printf("%d\t", node->num);
        }
        node = node->node.next;
    }
    printf("\n");
    return 0;
}

int main()
{
    int nums[] = {1,2,3,4,5};

    slist_head_init(&g_head);
    add_nums(&g_head, nums, sizeof(nums)/sizeof(int));
    show_nums(&g_head, nums, sizeof(nums)/sizeof(int));

    return 0;
}
