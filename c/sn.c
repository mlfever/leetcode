/*
 * Give a series of sequences as
 * follows S_0 = {1}, S_1={1,2,1}, …, S_n = S_{n-1}, n+1, S_{n-1}
 * 
 * 1. ​			How many terms in      S_n, i.e., |S_n|=? 	
 * 2. ​			Write a piece of code to get      S_n[i], where i \in [0, |S_n| -1] 	
 *​	S_2 = {1, 2, 1, 3, 1, 2, 1}
 * s(n) = 2 << (n + 1) - 1
 */

#include <stdio.h>

#define GET_N_SELF(n)   \
    ((1 << (n)) - 1)

// return S_n[i]
int get_value(int n, int s)
{
    int i = 0;

    i = GET_N_SELF(n);

    if (s == i)
    {
        return n + 1;
    }


    if (s > i)
    {
        s = s - i - 1;
    }

    get_value(n - 1, s);
}

void print_value(n)
{
    if (n == 0)
    {
        printf("1 ");
        return;
    }

    print_value(n - 1);
    printf("%d ", n + 1);
    print_value(n - 1);
}

int main(int argc, int **argv)
{
    int v;
    int n;
    int s;

    n = atoi(argv[1]);
    s = atoi(argv[2]);

    print_value(n);
    v = get_value(n, s);
    printf("\n%d\n", v);
}
