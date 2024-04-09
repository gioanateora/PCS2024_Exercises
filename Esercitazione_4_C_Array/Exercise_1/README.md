# Dot Product

Dot product between two vectors of the same size $n$ is defined as the sum of the product between the corresponding elements of the two vectors. 

## Example 

v1 = [3,4,7,0,1] v2 = [1,2,0,0,5]

dot product is: 3 * 1 + 4 * 2 + 7 * 0 + 0 * 0 + 1 * 5 = 3 + 8 + 5 = 16

## Requirements

Write a program which computes the dot product between teo vectors by exploiting C-Style arrays.

More precisely, the program must read these vectors from a file of name **vectors.txt** of the following format:

```text
# Size of the two vectors
5
# vector 1
3 4 7 0 1
# vector 2 
1 2 0 0 5
```

in which the character `#` represent a line to be ignored (comment); for the sake of simplicity the vector elements are all positive integers.
The result shall be written in a new file of name **dotProduct.txt** of the following format:

```text
# Size of the two vectors
5
# vector 1
3 4 7 0 1
# vector 2 
1 2 0 0 5
# dot product
16
```
