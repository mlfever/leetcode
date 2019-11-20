#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



bool isPalindrome(int x){
    int bits;
    int i;
    int m = x;
    int array[32];

    if (x < 0)
    {
        return false;
    }

    for (i = 0; m != 0; i++)
    {
        array[i] = m % 10;
        m = m / 10;
    }
    bits = i;

    for (i = 0; i < (bits / 2); i++)
    {
        if (array[i] != array[bits - i - 1])
        {
            return false;
        }
    }

    return true;
}

int main(int argc, char **argv)
{
    int num;

    if (argc != 2)
    {
        printf("usage: ./a.out <NUM>\n");
        return -1;
    }

    num = atoi(argv[1]);

    printf("num: %d is palindrome: %d\n", num, isPalindrome(num));

    return 0;
}