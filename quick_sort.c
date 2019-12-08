#include <stdio.h>


void show_nums(int nums[], int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        printf("%d\t", nums[i]);
    }
    printf("\n");
}

void quick_sort(int nums[], int left, int right)
{
    int i;
    int j;
    int temp;
    int k;

    if (left >= right)
    {
        return;
    }

    i = left;
    j = right;
    temp = nums[left];

    while (i < j)
    {
        // first get smaller then index from right
        while (j > i)
        {
            if (nums[j] < temp)
            {
                nums[i] = nums[j];
                i++;
                break;
            }

            j--;
        }

        // then get bigger then index from left
        while (i < j)
        {
            if (nums[i] > temp)
            {
                nums[j] = nums[i];
                j--;
                break;
            }

            i++;
        }
    }
    nums[i] = temp;

    quick_sort(nums, left, i - 1);
    quick_sort(nums, i + 1, right);
}

int main(int argc, char **argv)
{
    int nums[] = {59, 33, 53, 23, 42, 1, 90, 54};

    show_nums(nums, sizeof(nums) / sizeof(nums[0]));

    quick_sort(nums, 0, sizeof(nums) / sizeof(nums[0]) - 1);

    show_nums(nums, sizeof(nums) / sizeof(nums[0]));
}