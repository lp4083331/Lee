#include <stdio.h>
#include <stdlib.h>

char* find_sub_str(char *str1, char *str2)
{
    int len = 0;
    int max = 0;
    int end = 0;
    int i = 0, j = 0;

    int str1_len = 0;
    int str2_len = 0;

    int row = 0;
    int col = 0;

    char *result = NULL;

    if (str1 == NULL || str2 == NULL || strlen(str1) == 0 || strlen(str2) == 0)
    {
        return NULL;
    }

    str1_len = strlen(str1);
    str2_len = strlen(str2);

    col = str2_len - 1;

    while (row < str1_len)
    {
        i = row;
        j = col;
        len = 0;

        while (i < str1_len && j < str2_len)
        {
            if (str1[i] == str2[j])
            {
                len++;
            }
            else
            {
                len = 0;
            }

            if (len > max)
            {
                max = len;
                end = i;
            }
            i++;
            j++;
        }

        if (col > 0)
        {
            col--;
        }
        else
        {
            row++;
        }

    }

    result = malloc(sizeof(char)* max + 1);
    memset(result, 0x00, max +1);
    memcpy(result, str1 + end-max+1, max);

    return result;
}