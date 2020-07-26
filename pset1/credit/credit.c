#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int count = 0;
    int evens = 0;
    int odds = 0;
    int dig1 = 0;
    int dig2 = 0;
    int first2 = 0;
    bool valid;
    
    long num = get_long("number: ");
    
    while (num>0)
    {
        dig2 = dig1;
        dig1 = num%10;
        if (count%2 == 0)
        {
            odds+=dig1;
        }
        else
        {
            evens = evens + (dig1*2/10) + (dig1*2%10);
        }
        count++;
        num/=10;
    }
    
    first2 = dig1*10 + dig2;
    
    valid = (evens+odds)%10 == 0;
    
    if (dig1==4 && count>=13 && count<=16 && valid)
    {
        printf("VISA\n");
    }
    else if (first2>=51 && first2<=55 && valid && count==16)
    {
        printf("MASTERCARD\n");
    }
    else if ((first2==34 && valid) || (first2==37 && valid))
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
