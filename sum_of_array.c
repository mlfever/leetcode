#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int idx;
    int idx2;
    int *result_array;

    *returnSize = 0;

    for (idx = 0; idx < numsSize - 1; idx++)
    {
        //printf("idx: %d\n", idx);
        for (idx2 = idx + 1; idx2 < numsSize; idx2++)
        {
            //printf("first: %d, second: %d\n", idx, idx2);

            if ((nums[idx] + nums[idx2]) == target)
            {
                result_array = malloc(sizeof(int) * 2);

                result_array[0] = idx;
                result_array[1] = idx2;
                *returnSize = 2;
                return result_array;
            }
        }
    }

    return NULL;
}

int main()
{
    int array[] = {2, 7, 11, 15};
    int size = sizeof(array) / sizeof(int);
    int target = 17;
    int result_size;
    int *result_array;

    result_array = twoSum(array, size, target, &result_size);
    if (result_array != NULL)
    {
        printf("index: %d %d\n", result_array[0], result_array[1]);
    }

    return 0;
}
