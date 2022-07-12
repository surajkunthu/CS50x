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
2. Compiling - Takes source code and converts into [**Assembly Language**](https://en.wikipedia.org/wiki/Assembly_language)
3. Assembling - Takes assembly code and converts into [Machine Code (binary)](https://en.wikipedia.org/wiki/Machine_code)
4. Linking - Links all the 1s and 0s together into one file, `hello.c`

## Debugging
22:40

