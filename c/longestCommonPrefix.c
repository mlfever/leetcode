#include <stdio.h>
#include <string.h>

char * get_str(char *str, int len)
{
    char *com;

    com = malloc(len + 1);
    if (len != 0)
    {
        strncpy(com, str, len);
    }
    com[len] = '\0';

    return com;
}

char * longestCommonPrefix(char ** strs, int strsSize)
{
    int i;
    int len = 0;

    for (len = 0; strlen(strs[0]) != len; len++)
    {
        for (i = 0; i < strsSize - 1; i++)
        {
            if (strs[i][len] != strs[i + 1][len])
            {
                return get_str(strs[0], len);
            }
        }
    }

    return get_str(strs[0], len);
}

int main(int argc, char **argv)
{
    char *common;
    int i;

    if (argc == 1)
    {
        printf("usage: ./alongestCommonPrefix <STR1> <STR2> ... <STRN>\n");
        return -1;
    }

    common = longestCommonPrefix(argv[1], (argc - 1));

    printf("[\n");
    for (i = 1; i < argc; i++)
    {
        printf("\"%s\" ", argv[i]);
    }
    printf("]\n");

    printf("common str: %s\n", common);

    return 0;
}