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

## Arrays
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

### Array of Characters

[hi.c](/Week%202%20Arrays/hi.c)
```c
#include <stdio.h>

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

# Manual pages
[CS50 Manual Pages](https://manual.cs50.io)

Documentation created by developers to help with getting rid of low-level testing/debugging as well as information

1:29:25



