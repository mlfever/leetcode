#include <stdio.h>


int reverse(int x)
{
    long long int reverse_num = 0;
    int max = (1 << 31) - 1;
    int min = 0x80000000;

    while(x)
    {
        reverse_num = reverse_num * 10 + x % 10;
        x = x / 10;
    }

    if ((reverse_num > max) || (reverse_num < (int)min))
        return 0;

    return reverse_num;
}

int main(int argc, char **argv)
{
    int num;
    int result;

    if (argc != 2)
    {
        printf("usage: ./reverse.out <NUM>");
        return 0;
    }

    num = atoi(argv[1]);

    result = reverse(num);

    printf("input num: %d, reverse: %d\n", num, result);

    return 0;
}