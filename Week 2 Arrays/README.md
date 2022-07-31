# Week 2: Arrays

## `make`

```c
#include <stdio.h>

int main(void)
{
    printf("hello, world\n");
}
```
This is our typical C program.

```bash
$ make hello
$ ./hello
```
We use `make` to compile the code into machine code. Although, `make` compiles the code, it is not actually a compiler. It is a utility that comes on most systems that makes it easier to compile code by using another compiler. It is running **Clang** automatically.

## `Clang`
[Clang - C Language](https://en.wikipedia.org/wiki/Clang)

```bash
$ clang hello
$ ls
a.out* hello.c
```
clang automatically outputs the C file as `a.out`
If we want to rename it, we need to specify the output with Clang as `clang -o` _____ \<program name>

`-o`: output

```bash
$ clang -o hello hello.c
$ ls
hello* hello.c
$ ./hello
hello, world
```

Version 2 of the `hello.c` code
```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("What's your name? "):
    printf("hello, %s\n", name);
}
```

```bash
$ clang -o hello hello.c
/usr/bin/ld: /tmp/hello-d17dfc.o: in function `main'L
hello.c:(.text+0x19: undefined reference to `get_string'
clang: error: linker command failed with exit code 1 (use -v to see invocation)
$
```
We get an error with clang. `make` says 'trust' that the functions `get_string()` and `printf()` are referenced in a library. With `clang` we need to tell the compiler WHERE the referenced functions is found, especially those not in the standard library.

We need to use `-l` after the \<filename> to "link in" the library

`-l`: link

```bash
$ clang -o hello hello.c -lcs50
$ ./hello
What's your name? Suraj
hello, Suraj
```
This is getting tedious adding all the extra terminal commands, so we will stick with `make` for it's automation.

## Compiling
When using `make` to "compile the code", it is actually automatically performing the 4 functions:
1. Preprocessing
   - The `#include`, hashes, are preprocessing directives
```c
...
// #include <cs50.h> is telling the compiler that the prototype function below is available
string get_string(string prompt);
// #include <stdio.h> is telling the compiler that the prototype function below is available
int printf(string format, ...);
...

int main(void)
{
    string name = get_string("What's your name? "):
    printf("hello, %s\n", name);
}
```
2. Compiling - Takes source code a  nd converts into [**Assembly Language**](https://en.wikipedia.org/wiki/Assembly_language)
3. Assembling - Takes assembly code and converts into [Machine Code (binary)](https://en.wikipedia.org/wiki/Machine_code)
4. Linking - Links all the 1s and 0s together into one file, `hello.c`

## Debugging
Techniques for Debugging:

[buggy.c](/Week%202%20Arrays/buggy.c)

- As of right now, its printing 4 and not 3
- Using `printf()` to see what's in the computer memory
- `debug50`: debugger command that is automating the process of VScode's debugger
```bash
$ make buggy
$ debug50 ./buggy
```

Talking through problems is a great debugging tool.
- "Rubber duck"

[buggy2.c](/Week%202%20Arrays/buggy2.c)
- "Step over" vs "Step into"
- "step over": steps over functions
- "step into": dives into functions

## Types
| Type | Bytes | Bits |
| ---- | ---- | ---- |
| `bool` | 1 byte | 8 bits |
| `char` | 1 byte | 8 bits |
| `double` | 8 bytes | 64 bits |
| `float` | 4 bytes | 32 bits |
| `int` | 4 bytes | 32 bits |
| `long` | 8 bytes | 64 bits |
| `string` | ? bytes | ? bits |

RAM - Random Access Memory

[scores.c](/Week%202%20Arrays/scores.c)

```bash
Week2_code/ $ make scores
scores.c:9:29: error: format specifies type 'double' but the argument has type 'int' [-Werror,-Wformat]
    printf("average: %f\n", (score1 + score2 + score3) / 3);
                     ~~     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                     %d
1 error generated.
make: *** [<builtin>: scores] Error 1
```
We get an error. It is a float result but int variables. So we need to address that.

There is a way to store mulitple data of the same type in memory.

# Arrays
```c
int scores[3];
```
This line of code declares an `int` array of size `3`.

```c
scores[0] = 72;
scores[1] = 73;
scores[2] = 33;
```
We are indexing into the scores array and assigning values.

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int scores[3];

    scores[0] = get_int("Scores: ");
    scores[1] = get_int("Scores: ");
    scores[2] = get_int("Scores: ");

    printf("average: %f\n", (scores[0]+ scores[1]+ scores[2]) / 3.0);
}
```
Although this works, we get "smelly code"

Instead of indexing, we could use a `for loop`
```c
  for (int i = 0; i < 3; i++)
    {
        scores[i] = get_int("Score: ");
    }
```

## Array of Characters

[hi.c](/Week%202%20Arrays/hi.c)
```c
#include <stdio.h>x

int main(void)
{
    char c1 = 'H';
    char c2 = 'I';
    char c3 = '!';

    printf("%c%c %c\n", c1, c2, c3);
    printf("%i %i %i\n", c1, c2, c3);                     // IMPLICIT: ASCII values
    printf("%i %i %i\n", (int) c1, (int) c2, (int) c3);   // EXPLICIT: take the variable and convert to an int
}
```
```bash
Week2_code/ $ make hi
Week2_code/ $ ./hi
HI !
72 73 33
72 73 33
```
When we do this:
```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = "HI!";
    printf("%s\n", s);
}          
```

A string is just an array of characters
```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = "HI!";
    printf("%i %i %i \n", s[0], s[1], s[2]);
}
```

```bash
Week2_code/ $ ./hi
72 73 33 
```

The `string` "HI!" is an array of 3 characters (3-bytes).

If we want to delineate where one string ends and another string begins, we need a **special** denotation.

We use a **_nul_** value: `\0` : eight 0-bits 

H [1] I [2] ! [3] \0 [4]

>So "HI!" is actaully 4-bytes, not 3.

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = "HI!";
    printf("%i %i %i %i\n", s[0], s[1], s[2], s[3]);
}
```

```bash
Week2_code/ $ make hi
Week2_code/ $ ./hi
72 73 33 0
```

## `length.c`
[length.c](/Week%202%20Arrays/length.c)
```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("Name: ");

    int i = 0;
    while (name[i] != '\0')
    {
        i++;
    }
    printf("%i\n", i)
}
```
With this we can determine the length of a string.
```bash
Week2_code/ $ ./length
Name: HI!
3
Week2_code/ $ ./length
Name: BYE!
4
```

Let's write our own function and modularize the code:
```c
#include <cs50.h>
#include <stdio.h>

int string_length(string s);

int main(void)
{
    string name = get_string("Name: ");
    int length = string_length(name);
    printf("%i\n", length);
}

int string_length(string s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}
```
### `strlen`
```c
#include <string.h>
```
Comes with C and can calculate the length of a string.

## Manual pages
[CS50 Manual Pages](https://manual.cs50.io)

Documentation created by developers to help with getting rid of low-level testing/debugging as well as information

## `string.c`
[string.c](/Week%202%20Arrays/string.c)

How do we output a `string` in C without using `%s`?
```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Input:  ");
    printf("Output: ");
    for (int i = 0; i < strlen(s); i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");
}
```
This code is _correct_ but is NOT well designed.

`strlen(s)` will ALWAYS be 3 for `HI!`, the string will never change in length 

How can I remember the answer to `strlen` without calling the function everytime


```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Input:  ");
    printf("Output: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");
}
```
## `uppercase.c`
[uppercase.c](/Week%202%20Arrays/uppercase.c)

```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            printf("%c", s[i] - 32);
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}
```
`islower(s[i])` is asking if the `int` value is != 0
```c
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (islower(s[i]))
        {
            printf("%c", s[i] - 32);
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}
```
`toupper()` exists to perform the function for us. It already can determine if the string is uppercase or lowercase.
```c
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", toupper(s[i]));
    }
    printf("\n");
}
```
# command-line arguments
```c
int main(void)
{
    ...
}
```
What does `void` mean?

`main()` is the way to specify whether or not our program will take command line arguments. We say `void` to prevent the program from taking command line arguments.

## argc, argv
With these two commands, we can take command line arguments:

-`argc`: argument count - how many words were input

-`argv`: argument vector - array of all the words that was input

```c
#include <stdio.h>

int main(int argc, string argv[])
{
    ...
}
```

[argv.c](argv.c)
```c
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    printf("hello, %s\n", argv[0]);
}
```
```bash
Week2_code/ $ ./argv Suraj
hello, ./argv
```
`argv`[0] returns the string prior to input

let's change `argv`[0] to [1]
```c
printf("hello, %s\n", argv[1]);
```
```bash
Week2_code/ $ ./argv
hello, (null)
```
How do we prevent the `(null)`? We need some sort of error handling.

```c
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
        if (argc == 2)  // checks the count of the input
        {
            printf("hello, %s\n", argv[1]);
        }
        else        // "error" handling
        {
            printf("hello, world\n");
        }
}
```
```bash
Week2_code/ $ make argv
Week2_code/ $ ./argv
hello, world
Week2_code/ $ ./argv Suraj
hello, Suraj
```

## Exit status
[exit.c](exit.c)
```c
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
```

# Functions
Functions, procedures, methods, or subroutines

*Function* - a _black box_ with a set of 0+ inputs and 1 output.

`function(a, b, c)`

We call is a _black box_ because functions we don't write ourselves, we tend not to know the underlying implementation.

## Why use Functions?
- Organization
  - Break up complicated problem into subparts
- Simplification
  - easier to design, implement, and debug
- Reusability
  - can be recycled

## Function Declarations
- should always go atop your code BEFORE `main()`

```c
return-type name(argument-list);
```
- `return-type` - what kind of variable the function will output
- `name` - what to call the function
- `argument-list` - comma-separated set of inputs, with types and names

example:
```c
int add_two_ints(int a, int b);
```
**try example:**
Function to multiply two floats.
```c
float mult_two_reals(float x, float y); // function declaration

float mult_two_reals(float x, float y)  // function definition
{
    float product = x * y;
    return product;
}
```
**try example:**
Define `add_two_ints()`
```c
int add_two_ints(int a, int b);

int add_two_ints(int a, int b)
{
    return a + b;
}
```

[adder-1.c](adder-1.c)

Sometimes functions can take NO inputs. In that case we declare the function as having a `void` argument list.

Functions sometimes do not have an output. We declare the function as having a `void` argument list as well.

**Practice Problem**
- Write a function called `valid_triangle` that takes three real numbers representing the lengths of the three sides of a triangle as its arguments, and outputs either `true` or `false`, depending on whether those three lengths are capable of making a triangle.
- Triangle may only have sides with positive length
- The sum of the lengths of any two sides of the triangle must be greater than the length of the third side.
[triangle.c](triangle.c)

# Variables and Scope
- *Scope*: characteristic of a variable that defines from which functions that variable may be accessed
  - Local: can only be accessed within the functions in which they are created
  - Global: can be accessed by any function in the program
```c
int main(void)
{
    int result = triple(5);
} 
int triple(int x)
{
    return x * 3;
}
```
`x` is *local* to `triple()`. 

`result` is *local* to `main()`

```c
#include <stdio.h>

float global = 0.5050;

int main(void)
{
    triple();
    printf("%f\n", global);
}
void triple(void)
{
    global *=3;
}
```
Local variables are **passed by value**, the **callee** receives a copy of the passed variable. NOT the variable itself.

Variable in the **caller** is unchanged unless overwritten.

# Arrays
- Fundamental **data structure**
- We use arrays to hold values of the same type at contigous memory locations
- Arrays are partitioned into small, identically-sized blcoks of space called **elements**
- Each of which can store a certain amount of **data**
- all of the same data type such as **int** or **char**
- and which can be accessed directly by an **index**

In C,
- elemernts of an array are indexed starting from 0
- If an array has _n_ elements, the first element is located at index 0. The last element is located at index (_n_ - 1)
- C is bery lenient. It will not prevent you from going "out of bounds" of your array -- segmentation fault

Array declarations
```c
type name[size];
```
- type: what kind of variable
- name: what you want to call the array
- size: how many elements you want to contain

example:
```c
int student_grades[40];
double menu_prices[8];
```

## Data-types
- if you think of a single element of an array of type `data-type` the same as you would any other variable of type `data-type` (which, effectively, it is) then all the familiar operations makes sense.

- when declaring and initializing an array simultaneously, there is a special syntax:

```c
// instantation syntax
bool truthtable[] = { false, true, true };

// individual element syntax
bool truthtable[3];
truthtable[0] = false;
truthtable[1] = true;
truthtable[2] = true;
```

Arrays can consist of more than a single dimension.
```c
bool battleship[10][10];
```
- can think of this as a 10x10 grid of cells
  - in memory though, it's really just a 100-element one-dimensional array
  - Multi-dimensional arrays are great **abstractions** to help visualize game boards or other complex representations
- we can treat individuals elements of arrays as variables, we cannot treat entire arrays themselves as variables
- We CANNOT assign one array to another using the assignment operator. NOT legal C
- Instead, we must use a loop to copy over the elements one at a time

```c
int foo[5] = { 1, 2, 3, 4, 5 };
int bar[5];.
bar = foo; //THIS WILL NOT WORK

for(int j = 0; j < 5l j++)
{
    bar[j] = foo[j]
}
```

- Most variables in C are **passed by value** in function calls 
- Arrays DO NOT follow this rule, they are **passed by reference**
- The callee receives the actual array, NOT a copy of it. (not worth it for a function to receive due to "bulkiness" of arrays)
- What does it mean when the callee manipulates elements of the array?

```c
void set_array(int array[4]);
void set_int(int x);

int main(void)
{
    int a = 10;
    int b[4] = { 0, 1, 2, 3 };
    set_int(a);
    set_array(b);
    printf("%d %d\n", a, b[0]);
}

void set_array(int array[4])
{
    array[0] = 22;
}

void set_int(int x)
{
    x = 22;
}
```
What gets printed here at the end of main?
```bash
10 22
```
# Command Line Arguments
Most of our programs have started:
```c
int main(void){}
```
- Since we've been collecting user input through in-program prompts, we haven't needed to modify this declaration of `main()`
- If we want the user to provide data before program starts running (at run-time) instead of while the program is running
- **command-line arguments**

```c
int main(int argc, string argv[]){}
```
## `argc`
Argument Count
`int`-type variable will store the **number** of command-line arguments the user typed when the program was executed.

| command | argc |
| --- | --- |
| ./greedy | 1 |
| ./greedy 1024 cs50 | 3 |

(counting the number of "arguments" of items with blanks)

## `argv`
Argument vector
- array of **strings** stores, one string per element
- first element of `argv` is always found at `argv[0]`
- the last element of `argv` is always found at `argv[argc-1]`
- example:
```bash
./greedy 1024 cs50
```
| argv indices | argv contents |
| --- | --- |
| argv[0] | "./greedy" |
| argv[1] | "1024" |
| argv[2] | "cs50" |
| argv[3] | ??? - possible segmentation fault |