#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
        if (argc == 2)  // checks the count of the input
        {
            printf("hello, %s\n", argv[1]);
        }
        else            // "error" handling
        {
            printf("hello, world\n");
        }
}