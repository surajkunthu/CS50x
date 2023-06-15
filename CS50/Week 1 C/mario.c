#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    while (true)
    {
        n = get_int("Size: ");
        if (n > 0)
        {
            break;
        }
    }
  // While loop or do-while loop can work  
  // do-while is just more compact
  //  do
  //  {
  //      n = get_int("Size: ");
  //  }
  //  while (n < 1); // code will run UNTIL n is greater than 1
    
    // For each row
    for (int i = 0; i < n; i++)
    {
        // For each column
        for (int j = 0; j < n; j++)
        {
            // Print a brick
            printf("#");
        }

        // Move to next row
        printf("\n");
    }
}