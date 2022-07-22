// include header files
#include <cs50.h>
#include <stdio.h>

// declare function
bool valid_triangle(int x, int y, int z);

int main(void)
{
    int x;
    int y;
    int z;
     // ask user for input
     // prompt user forever UNTIL x,y,z are postive integers
    do
    {
    x = get_int("Give me the length of side 1 of a triangle: ");
    }
    while(x < 0);
    do
    {
    y = get_int("Give me the length of side 2 of a triangle: ");
    }
    while(y < 0);
    do
    {
    z = get_int("Give me the length of side 3 of a triangle: ");
    }
    while(z < 0);

    // call function and return a boolean(true/false)
    bool a = valid_triangle(x, y, z);
}

// function defintion
bool valid_triangle(int x, int y, int z)
{
    int side12 = x + y; // side12 is side 1 + side 2
    int side13 = x + z; // side13 is side 1 + side 3
    int side23 = y + z; // side23 is side 2 + side 3
     if (side12 > z && side13 > y && side23 > x)
    {   // if two side sum is greater than the third
        printf("The triangle is valid!\n");
    }
    else
    {   // if any two side sum is not greater than the third
        printf("The triangle is not valid!\n");
    }
    return 0;
}