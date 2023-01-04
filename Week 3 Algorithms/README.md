# Week 3: Algorithms

Recall the phone-book tearing algorithms

# Searching
## Linear Search
Find the $50 activity
pseudocode
```pseudocode
for each door from left to right
    if 50 is behind door
        return true
return false
```
Converting into c-like pseudocode
```c
for i from 0 to n-1
    if 50 is behind doors[i]
        return true
return false
```
## Binary Search
pseudocode
```pseudocode
if no doors left
    return false
if 50 is behind middle door
    return true
Else if 50 < middle door
    Search left half
Else if 50 > middle door
    search right half
```

Converting into c-like pseudocode
```c
if no doors left
    return false
if 50 is behind doors[middle]
    return true
Else if 50 < doors[middle]
    Search doors[0] thru doors[middle - 1]
Else if 50 > doors[middle]
    search doors[middle + 1] thru doors[n - 1]
```
## Running Time
O(n)

"big O" notation

Cheat sheet (fastest to slowest)[Upper Bound]:
- $O(n^2)$
- $O(n \log{n})$
- $O(n)$ - linear search
- $O(\log{n})$ - binary search
- $O(1)$

$\Omega$ [Lower Bound]
- $\Omega(n^2)$
- $\Omega(n \log{n})$
- $\Omega(n)$ 
- $\Omega(\log{n})$
- $\Omega(1)$ - linear search & binary search

Upper bound represents how many POSSIBLE steps, Lower bound represents the MINIMUM steps needed to obtain goal

If Upper Bound = Lower Bound: $\Theta$
- $\Theta(n^2)$
- $\Theta(n \log{n})$
- $\Theta(n)$ 
- $\Theta(\log{n})$
- $\Theta(1)$

[search.c](search.c)

[search2.c](search2.c)

[phonebook.c](phonebook.c)

## Data Structures

let's say a person has:

```c
string name;
string number;
```
We can create a data type with:
```c
typedef struct
{
    string name;
    string number;
}
person;
```
Now if we want to build on this:

[phonebook2.c](phonebook2.c)

## Sorting

7 2 5 4 1 6 0 3 $\rarr \square \rarr$ 0 1 2 3 4 5 6 7

### Selection sort
- start with i = 0
- 7 is our smallest number, look at ALL numbers remaining in array. 0 is the smallest
- swap places with 0 and 7
- iterate to i = 1 and continue...

Pseudocode
```c
for i from 0 to n-1
    Find smallest number between numbers[i] and numbers[n-1]
    Swap smallest number with numbers[i]
```

Number of comparisons:
$$ (n-1) + (n-2) + (n-3) + ... + 1 = \frac{n(n-1)}{2} $$

$$=\frac{(n^2 - n)}{2}$$

$$= \frac{n^2}{2} - \frac{n}{2}$$

Since the biggest influencer is $n^2$

$O(n^2)$: Upper Bound

$\Omega(n^2)$: Lower Bound

> So selection sort has: $\Theta(n^2)$

### Bubble Sort
- start with i = 0
- Swap 7 with 2 since 2 \< 7, continue to swap until i=0(7) is not smaller or END of array
- go to i = 0 place again and continue...

Pseudocode
```c
Repeat n-1 times
    for i from 0 to n-2
        if numbers[i] and numbers[i+1] out of order
            swap them
    if no swaps
        quit
```

Number of comparisons:
$$ (n-1) * (n-1) $$

$$n^2 - 1n - 1n + 1$$

$$n^2 - 2n + 1$$

Since the biggest influencer is $n^2$

$O(n^2)$: Upper Bound

$\Omega(n^2)$: Lower Bound

> So bubble sort has: $\Theta(n^2)$

### Recursion

Ability of a function to _call itself_. Ideally on a problem that get smaller and smaller.

Binary Search algorithm pseudocode from earlier
```c
if no doors left
    return false
if 50 is behind middle door
    return true
Else if 50 < middle door
    Search left half // recursive element (calling Search)
Else if 50 > middle door
    search right half // recursive element
```

[iteration.c](iteration.c)

[recursion.c](recursion.c)

### Merge sort

Pseudocode
```c
if only one number
    quit
else
    Sort left half of numbers
    Sort right half of numbers
    Merge sorted halves
```
Divide

| 7 2 5 4 1 6 0 3 | 

| 7 2 5 4 | 1 6 0 3 | 

| 7 2 | 5 4 | 1 6 | 0 3 | 

| 7 | 2 | 5 | 4 | 1 | 6 | 0 | 3 | 

Merge and sort

| 2 7 | 4 5 | 1 6 | 0 3 | 

| 2 4 5 7 | 0 1 3 6 | 

| 0 1 2 3 4 5 6 7 | 

Run time (fastest of the 3 shown):

$O(n \log{n})$: Upper bound

$\Omega(n \log{n})$: Lower bound

> $\Theta(n \log{n})$

# PSETS
[Optional Practice Problems](https://cs50.harvard.edu/x/2023/problems/3/)

[Lab 3: Sort](https://cs50.harvard.edu/x/2023/labs/3/)

[Problem Set 3](https://cs50.harvard.edu/x/2023/psets/3/)

Task 1:
 - [Plurality](https://cs50.harvard.edu/x/2023/psets/3/plurality/)

Task 2:
- Standard: [Runoff](https://cs50.harvard.edu/x/2023/psets/3/runoff/)

- Challenge: [Tidemann](https://cs50.harvard.edu/x/2023/psets/3/tideman/)

