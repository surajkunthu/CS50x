#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Missing command-line argument\n");
        return 1;       // clue to the system that something went wrong, since return isn't 0
                        // this will exit out the code immediately since return is NOT 0
    }
    printf("hello, %s\n", argv[1]);
    return 0;           // this is good practice if we have other return values
}