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
#if 0
void quick_sort(int nums[], int left, int right)
{
    int i;
    int j;
    int temp;
    int k;

    if (left == right)
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
#endif
void quick_sort(int s[], int l, int r)
{
    if (l < r)
    {
        //Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换 参见注1
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while(i < j && s[j] >= x) // 从右向左找第一个小于x的数
                j--;  
            if(i < j) 
                s[i++] = s[j];
            
            while(i < j && s[i] < x) // 从左向右找第一个大于等于x的数
                i++;  
            if(i < j) 
                s[j--] = s[i];
        }
        s[i] = x;
        quick_sort(s, l, i - 1); // 递归调用 
        quick_sort(s, i + 1, r);
    }
}
int main(int argc, char **argv)
{
    int nums[] = {59, 33, 53, 23, 42, 1, 90, 54};

    show_nums(nums, sizeof(nums) / sizeof(nums[0]));

    quick_sort(nums, 0, sizeof(nums) / sizeof(nums[0]) - 1);

    show_nums(nums, sizeof(nums) / sizeof(nums[0]));
}