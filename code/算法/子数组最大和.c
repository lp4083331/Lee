#include <stdio.h>
#include <stdlib.h>


/* ����һ�����飬���������������ۼӺ� 
   arr=[1,-2,3,5,-2,6,-1] ���е���������[3,5,-2,6]�����ۼӳ����ĺ�12 ���Է���12 */
int get_max_array_value(int array[], int length)
{
    int current = 0, result = 0;
    int i = 0;

    if (array == NULL || length <= 0)
    {
        printf("the array is wrong.\n");
        return -1;
    }

    current = result = array[0];
    for (i = 1; i < length; i++)
    {
        current = current < 0 ? 0 : current;
        current += array[i];

        result = max(current, result);
    }

    return result;
}