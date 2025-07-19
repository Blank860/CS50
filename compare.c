#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");
    char *t = get_string("t: ");

    if (strcmp(s, t) == 0) //cause the value given to a string just holds the address in the memory of the actual string so when compared different values will hold different addresses so it wont come back as equal
    {
        printf("same\n");
    }
    else
    {
        printf("different\n");
    }
}
