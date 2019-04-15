#include "main.h"

void f_task(void);

int main()
{
    f_task();

    return 0;
}


void f_task()
{
    char str[100];
    int id = 0, max = 0, count = 0, len;
    printf("Enter the words separated by space: ");
    gets(str);
    len = strlen(str);
    for (int i = 0; i < len; ++i)
    {
        if (str[i] != ' ') count += 1;
        else
        {
            if (count > max)
            {
                max = count;
                id = i - count;
            }
            count = 0;
        }
        if (count > max)
        {
        max = count;
        id = i - count;
        }
    }
    max += id;
    printf("The longest word is ");
    for (int i = id; i <= max; ++i)
    {
        putchar(str[i]);
    }
    printf("\n");
}
