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


# PSETS
[Lab](https://cs50.harvard.edu/x/2022/labs/3/)

[Problem Set 3](https://cs50.harvard.edu/x/2022/psets/3/)

Task 1:
 - Plurality

Task 2:
- Standard: [Runoff]()

- Challenge: [Tidemann]()

