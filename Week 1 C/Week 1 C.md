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
    printf("hello, %s\n", answer");
}
```
 - `%s` - placeholder, format code. "Put a string here eventually." In this case it will look for the next available string value, which is `answer`.


```
$ make hello
$ ./hello
What's your name? Suraj
hello, Suraj
```

40:00