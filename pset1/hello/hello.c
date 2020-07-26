#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string answer = get_string("What is your name?\n"); //gets user input
    printf("Hello, %s\n", answer); //prints hello, (user input)
}