# Input/Output

## Exercise 2: Mean value

Write a program which reads the values from a file of name **data.csv** of the following format:
```text
4.3607508686188385e+00
2.5775317072763722e+00
4.1323968950344234e+00
4.1937601339042931e+00
4.6465894317471372e+00
1.7902054771735358e+00
2.3408910228595561e+00
4.0729183792476160e+00
2.1110988432127513e+00
3.2158798231817221e+00
...
```

 1. The file contains a list with $N$ values in $[1, 5]$.
 2. Write a function that maps points in the interval $[-1,2]$.
 3. For each $i=1,\dots,N$, compute the mean of the first $i$ mapped values. Finally, print the result in a file **result.csv** of the following format:


```text
# N Mean
1 1.5205631514641289e+00
2 8.5185596596070401e-01
3 1.0176698677324085e+00
4 1.1120824259063613e+00
5 1.2366543554871596e+00
6 9.6265431421932490e-01
7 8.2594202178008813e-01
...
```
