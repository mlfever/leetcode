#include <stdio.h>
#include <stdbool.h>
#include <string.h>

static inline bool is_left_bracket(char left)
{
    if ((left == '(') || left == '{' || left == '[')
    {
        return true;
    }
    else
    {
        return false;
    }
}

static inline bool is_right_bracket(char right)
{
    if ((right == ')') || right == '}' || right == ']')
    {
        return true;
    }
    else
    {
        return false;
    }
}

static inline bool is_bracket_match(char left, char right)
{
    if ((left == '(') && (right == ')'))
    {
        return true;
    }
    else if ((left == '{') && (right == '}'))
    {
        return true;
    }
    else if ((left == '[') && (right == ']'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isValid(char *s)
{
    int i;
    int len = strlen(s);
    int last_left_index = 0;
    int *left_array;

    // zero string is valid
    if (len == 0)
    {
        return true;
    }

    // brackets must be pairs
    if ((len % 2) != 0)
    {
        return false;
    }

    left_array = malloc(len * sizeof(int));
    if (left_array == NULL)
    {
        return false;
    }


    for (i = 0; i < len; i++)
    {
        if (is_left_bracket(s[i]))
        {
            left_array[last_left_index++] = i;
        }
        else if (is_right_bracket(s[i]))
        {
            if (last_left_index == 0)
            {
                return false;
            }

            if (!is_bracket_match(s[left_array[last_left_index - 1]], s[i]))
            {
                return false;
            }
            else
            {
                last_left_index--;
            }
        }
        else
        {
            return false;
        }
        
    }

    if (last_left_index != 0)
    {
        return false;
    }

    return true;
}

int main(int argc, char **argv)
{
    char input[32];

    while(scanf("%s", &input) != EOF)
    {
        if (isValid(input))
        {
            printf("true\n");
        }
        else
        {
            printf("false\n");
        }
    }
}