# Week 1: C

## C
>`C`: underlies many Modern languages

- Code ultimately needs to be **correct**.
- **Well-designed** code will take time to get comfortable.
- **Style** is also important
  

### Hello, World! in C
```C
#include <stdio.h>

int main(void)
{
    printf("hello, world\n");
}
```
Although this is _relatively_ easy to read to us humans, a computer will have trouble "reading" this. 

We need an **Integrated Development Environment (IDE)** (such as Visual Studio Code!) to convert into binary (or machine code)

[hello.c](hello.c)

source code &rarr; $\square$ &rarr; machine code

We need *something* to convert the source code to machine code.

> A compiler

### Linux/Bash
We use the "cloud" VSCode since a CodeSpace is already set up for us by CS50. Allows us to compile C code.

`bash` terminal
```bash
$ make hello
$ ./hello
hello, world
```
- `make x` - Compile file `x` (will overwrite file `x`)

- `./x` - Go to file `x` in directory and run

```bash
$ rm hello
rm: remove regular file 'hello'? y
```
- `rm x` - remove file `x` from directory

```bash
$ ls
hello.c
```
- `ls` - list elements in current directory

What happens if I try to run the file without `make hello`?

```bash
$ ./hello
bash: ./hello: No such file or directory
```

What happens if I make changes to `hello.c` without compiling?

```C
#include <stdio.h>

int main(void)
{
    printf("hello, CS50!\n");
}
```
Bash
```bash
$ ./hello
hello, world
```

- Still shows "hello, world" since changes to file are not compiled.


Recompile
```bash
$ ls
hello*  hello.c
$ make hello
$ ./hello
hello, CSC50!
```
What if we try `./hello.c` in bash?
```bash
$ ./hello.c
bash: ./hello.c: Permission denied
```
- the C file is NOT executable. ONLY read-only.

## Functions, Arguments

```C
printf(" "); 
printf("Hello, World!\n");
```
- `printf(" ")` - print/say string function
- `;` - end of function
- `\n` - Escape sequence. New line


```C
string answer = get_string(); 
string answer = get_string("What is your name? "); 
```
- `get_string()` - Ask/prompt user for a string input
- `string answer` - String assignment operator. Returning to C the user input.


### Applying functions, arguments in C
Example: [Hello World](hello.c)

```C
#include <stdio.h>

int main(void)
{
    string answer = get_string("What's your name? ");
    printf("hello, answer\n");
}
```
- We run into errors with this code, why?
  - we use the`<stdio.h>` library to utilize standard input and output (STD I/O)
  - `get_string()` is a function written by CS50, so we need to include the `<cs50.h>` library

```C
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string answer = get_string("What's your name? ");
    printf("hello, answer\n");
}
```

```
$ make hello
$ ./hello
What's your name? Suraj
hello, answer
```
- We need to replace the "string" answer with the user input value

```C
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string answer = get_string("What's your name? ");
    printf("hello, %s\n", answer);
}
```
 - `%s` - placeholder, format code. "Put a string here eventually." In this case it will look for the next available string value, which is `answer`.


```
$ make hello
$ ./hello
What's your name? Suraj
hello, Suraj
```

```c
printf("hello, world");
printf("hello, %s\n", answer);
```

<details>
<summary>
How many inputs are in each `printf()` function?
</summary>

- Top line = 1 -- `hello, world`
- Bottom line = 2 -- `hello, %s\n` and `answer`
</details>


The below code will also work.
```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("hello, %s\n", get_string("What's your name? "));
}
```
<details>
<summary>
Is the better designed or worse?
</summary>

- Worse
- Harder to read from top to bottom
- Cannot iterate code, `printf()` will ONLY take strings in this case
</details>

> arguments &rarr; functions &rarr; return value

## C Basics

```c
#include <stdio.h>

int main(void)
{

}
```
- `#include <stdio.h>` is a header file that loads the library `<stdio.h>`
    - in `C`, by default, there is no data type `string`. We load `<stdio.h>` to allow for `strings`
- `int main(void)` is to the initialze the program
- `{ }` anything within the curly braces is the code/program


## Linux terminal commands
```bash
cd - change directory

cp - copy

ls - list

mkdir - make directory

mv - move

rm - remove

rmdir - remove directory

. - this directory

.. - parent directory
```

`ctrl` + `L` or type `clear` in the terminal to clear terminal window

```bash
$ mkdir pset1
$ mkdir pset2
$ ls
hello* hello.c pset1/ pset2/
$ cd pset1
pset1/ $ ls
pset1/ $ mkdir mario
pset1/ $ ls
mario/
pset1/ $ cd mario/
pset1/mario/ $ code mario.c

pset1/mario/ $ cd ..
pset1/ $ cd mario/
pset1/mario/ $ ls
mario.c
pset1/mario/ $ cd ../..
$ cd pset1/mario/
pset1/mario/ $ cd
$ ./hello
```

## Types

In C, data types are:
- bool - boolean (True/False)
- char - single character
- double - float with more digits
- float - decimal value
- int - integer
- long - integer with more bits
- string - string of characters
- ...

CS50 functions
- get_char
- get_double
- get_float
- get_int
- get_long
- get_string
- ...

Represent in code
- %c - char
- %f - float
- %i - int
- %li - long integer
- $s - string

Operators
- "+"
- "-"
- "*"
- "/"
- "%" - remainder

Variables, syntactic sugar
```c
int counter = 0;
```
These three forms for incrementing by 1 are the same
```c
counter = counter + 1;
counter += 1;
counter++;
```

### Examples
[Calculator.c](calculator.c)
```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");
    printf("%i\n", x + y);
}
```

What if we added `int z` and replaced `x + y`?

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");
    int z = x + y;
    printf("%i\n", z);
}
```
Is this better designed than the previous code snippet?
- Depends on the complexity of the problem.
- In this case, it's pretty easy to understand what's going on.

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for x
    int first_number = get_int("x: ");

    //Prompt user for y
    int second_number = get_int("y: ");

    //Perform addition
    printf("%i\n", first_number + second_number);
}
```
Style-wise, comments and better defined variables help understand the code better for you and anyone else who reads the code.

```bash
$ make calculator
$ ./calculator
x: 1000000000
y: 1000000000
2000000000
$ ./calculator
x: 2000000000
y: 2000000000
-29496
```
<details>
<summary>Why is the program incorrect? The math works out just fine. </summary>

- Most PCs support 32 bits for `ints`
- 32 bits is 4 billion integers
- However, 4 billion total including negative so 2 billion positive and 2 billion negative.
</details>


<details>
<summary>What's the solution to fix this problem? </summary>

- Change `int` to `long`
- Change `get_int` to `get_long`
- Change `%i` to `%li`

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for x
    long x = get_long("x: ");

    //Prompt user for y
    long y = get_long("y: ");

    //Perform addition
    printf("%li\n", x + y);
}
```

```bash
$ make calculator
$ ./calculator
x: 2000000000
y: 2000000000
4000000000
```
</details>

## Conditionals
```c
if (x < y)
{
    printf("x is less than y\n");
}
else if (x > y)
{
    printf("x is greater than y\n");
}
else
{
    printf("x is equal to y\n");
}
```

Example: [Points.c](points.c)

`const` - Tells compiler that this variable will NEVER change.

Example: [parity.c](parity.c)

Example: [agree.c](agree.c)

`''` single quotes for single characters `char`

`""` double quotes for `string`

## Loops

Example: [meow.c](meow.c)

Repeat "forever"
```c
while (true)
{
    printf("meow\n");
}
```

Better design for implementation
```c
int counter = 0;
while (counter < 3)
{
    printf("meow\n");
    counter = counter + 1;
}
```
Cleaned up and more conventional version
```c
int i = 0;
while (i < 3)
{
    printf("meow\n");
    i++;
}
```

`For` Loop
```c
for (int i = 0; i < 3, i++)
{
    printf("meow\n");
}
```

Let's update: [meow.c](meow.c)

What happens if we make the function `meow()` and then move it to the bottom of the code?
```c
#include <stdio.h>


int main(void)
{
   for (int i = 0; i < 3; i++)
   {
        meow();
   }
}

void meow(void)
{
    printf("meow\n");
}
```
Error
```bash
$ make meow
meow.c:8:9: error: implicit declaration of function 'meow' is invalid in C99 [-Werror,-Wimplicit-function-declaration]
        meow();
        ^
fatal error: too many errors emitted, stopping now [-ferror-limit=]
2 errors generated.
make: *** [<builtin>: meow] Error 1
```
C reads from top to bottom

There is a workaround

```c
#include <stdio.h>

void meow(void); // Call the function

int main(void)
{
   for (int i = 0; i < 3; i++)
   {
        meow();
   }
}

void meow(void)
{
    printf("meow\n");
}
```

## Inputs
Example: [discount.c](discount.c)

```c
#include <cs50.h>
#include <stdio.h>

float discount(float price, int percentage);

int main(void)
{
    float regular = get_float("Regular Price: ");
    int percent_off = get_int("Percent Off: ");
    float sale = discount(regular, percent_off);
    printf("Sale Price: %.2f\n", sale);
}

float discount(float price, int percentage)
{
    return price * (100 - percentage) / 100;
}
```

## Validating User Input
Example: [mario.c](mario.c)

## Floating Point Imprecision
The inability for computers to precisely represent values


Example: [calculator.c](calculator.c)

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for x
    float x = get_float("x: ");

    //Prompt user for y
    float y = get_float("y: ");

    // Divide x by y
    float z = x / y;
    
    //Perform operation
    printf("%.50f\n", z);
}
```
This code yields an approximation
```bash
$ ./calculator
x: 1
y: 10
0.10000000149011611938476562500000000000000000000000
```

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for x
    int x = get_int("x: ");

    //Prompt user for y
    int y = get_int("y: ");

    // Divide x by y
    float z = x / y;
    
    //Perform operation
    printf("%.50f\n", z);
}
```
This is a truncation
```bash
$ ./calculator
x: 2
y: 3
0.00000000000000000000000000000000000000000000000000

$ ./calculator
x: 4
y: 3
1.00000000000000000000000000000000000000000000000000
```
## Integer Overflow
```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for x
    int x = get_int("x: ");

    //Prompt user for y
    int y = get_int("y: ");

    // Divide x by y
    float z = (float) x / (float) y;
    
    //Perform operation
    printf("%.50f\n", z);
}
```

Now the value is closer to the right answer
```bash
$ ./calculator
x: 2
y: 3
0.66666668653488159179687500000000000000000000000000
```

Y2K is a famous Integer Overflow event. Most PCs had only 2 bits for storing years

1999 -> 99

2000 -> 00 \
this would be the same as the epoch of PCs keeping track of dates (1970)

Example: [pennies.c](pennies.c)

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    float amount = get_float("Dollar amount: ");
    int pennies = amount * 100;
    printf("Pennies: %i\n", pennies);
}
```
Float point imprecision at $4.20

```bash
$ ./pennies
Dollar amount: .99
Pennies: 99
$ ./pennies
Dollar amount: 1.23
Pennies: 123
$ ./pennies
Dollar amount: 4.20
Pennies: 419
```


use the `math.h` library and the `round()` function
```c
#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    float amount = get_float("Dollar amount: ");
    int pennies = round(amount * 100) ;
    printf("Pennies: %i\n", pennies);
}
```

```bash
$ ./pennies
Dollar amount: 4.20
Pennies: 420
```

# Data Types
Modern languages don't need data types to be declared.

In C, we need to declare data types

## `int` 
Integer
- Data type for variables that will store integers
- 4 bytes of memory (32 bits)
- Integer storage range: 
$$ -2^{31} <-- 0 --> 2^{31}-1 $$

## <span style= "color:lightblue"> unsigned </span> `int`
- a _qualifier_ that can be applied to certain types (including `int`) which doubles the positive range of variables, no longer can use negative values
- Unsigned integer storage range: 
$$ 0 <---> 2^{32}-1 $$

## `char`
character
- Stores single characters
- 1 byte of memory (8 bits)
- ASCII is a standard for representation
- `char` storage range: 
$$ -128 <-- 0 --> 127 $$

## `float`
floating-point value
- stores floating-point values, aka _real numbers_.
- 4 bytes of memory (32 bits)
- Difficuly to describe the range of `float`, limited in how _precise_ we can be

## `double`
- stores floating-point values, aka _real numbers_.
- _double precision_, much more precise than `float`
- 8 bytes of memory (64 bits)

## `void`
- A type, not a _data type_
- Functions can have a `void` return type which means they do not return a value
- Parameter list of a functino can also be `void`, it means the function takes no parameters
- placeholder for "nothing"

## `bool`
- Can only hold two distinct values:
  - `true` or `false`
- part of `#include <cs50.h>`

## `string`
- series of characters
- words, sentences, paragraphs, etc...
- part of `#include <cs50.h>`
  
## Creating a variable
Specify a data type and give it a name
```c
int number;
char letter;
```

For multiple variables of the same type, you must specify the type _once_ then list as many variables of that type
```c
int height, width;
float sqrt2, sqrt3, pi;
```
It's good practive to only _declare_ variables when you need them

## Using a variable
After a variable has been declared, it's no longer necessary to specify that variable's type.
```c
int number;   // declaration
number = 17;  // assignment
char letter;  // declaration
letter = 'H'; // assignment
```
We can simulataneously declare and set the value of a variable (sometimes called _initializing_)

```c
int number = 17;   // initialization
char letter = 'H'; // initialization
```

# Operators

# Conditional Statements

# Loops

# Command Line
