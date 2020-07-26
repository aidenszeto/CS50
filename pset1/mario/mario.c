#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("height: ");
    }
    while (height>8 || height<1);
    for (int i=height-1; i>=0; i--)
    {
        for (int j=0; j<i; j++)
        {
           printf(" ");
        }
        for (int k=0; k<height-i; k++)
        {
           printf("#");
        }
        printf("  ");
        for (int k=0; k<height-i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}