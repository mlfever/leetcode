#include <stdio.h>
#include <string.h>

#define LEN 3

typedef struct roman_map
{
    char    roman[LEN];
    int     num;   
} roman_map;

static roman_map dmap[] = {
    {"CM", 900},
    {"CD", 400},
    {"XC", 90},
    {"XL", 40},
    {"IX", 9},
    {"IV", 4}
};
 
static roman_map smap[] = {
    {"I", 1},
    {"V", 5},
    {"X", 10},
    {"L", 50},
    {"C", 100},
    {"D", 500},
    {"M", 1000}
};

static int get_num_from_roman(char *s, int *num, int *offset)
{
    int i;
    int len = strlen(s);

    for (i = 0; i < sizeof(dmap) / sizeof(dmap[0]); i++)
    {
        if (!strncmp(s, dmap[i].roman, 2))
        {
            *num = dmap[i].num;
            *offset = 2;
            return 0;
        }
    }

    for (i = 0; i < sizeof(smap) / sizeof(smap[0]); i++)
    {
        if (!strncmp(s, smap[i].roman, 1))
        {
            *num = smap[i].num;
            *offset = 1;
            return 0;
        }
    }

    return -1;
}

int romanToInt(char *s)
{
    int num;
    int offset;
    int value = 0;
    int i = 0;
    int rv;

    if (s[0] == '-')
    {
        printf("no valid num, return -1");
        return -1;
    }

    while (s[i] != '\0')
    {
        rv = get_num_from_roman(&s[i], &num, &offset);
        if (rv != 0)
        {
            printf("not valid num, index: %d, return -1", i);
            return -1;
        }

        value += num;
        i += offset;
    }

    return value;
}

int main(int argc, char **argv)
{
    int result;

    if (argc != 2)
    {
        printf("usage: a.out <roman NUM>\n");
        return -1;
    }

    result = romanToInt(argv[1]);

    printf("roman num: %s, to int: %d\n", argv[1], result);

    return 0;
}