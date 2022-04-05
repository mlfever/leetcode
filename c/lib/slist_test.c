/*
 * single list struct test
 */

#include "slist.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct nslist_num
{
    int num;
    slist_t node;
} slist_num_t;

slist_head_t g_head;

int add_nums(slist_head_t *head, int *nums, int num_size)
{
    int i;
    slist_num_t *node;

    for (i = 0; i < num_size; i++)
    {
        node = malloc(sizeof(slist_t));
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

    for (i = 0; i < num_size; i++)
    {
        node = head->next;
        if (node != NULL)
        {
            printf("%d\t", node->num);
        }
    }
    printf("\n");
    return 0;
}

int main()
{
    int nums[] = {1,2,3,4,5};

    slist_head_init(&g_head);
    add_nums(&g_head, nums, sizeof(nums));
    show_nums(&g_head, nums, sizeof(nums));

    return 0;
}
