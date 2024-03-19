# Linear System (1)

Solving linear system plays a key role in many scientific application, such as engineering, physics, chemistry, computer science, and economics. 

## Example 

The solution of the linear system `Ax = b` can be retrieved as

```text
Ly = Pb

Ux = y
```

by exploiting the PALU decomposition of `A`.

## Requirements

Write a software able to compute (if possible) the solution of the following systems:

1. `A` is `n` x `n` squared matrix with elements from `1` to `n^2`
2. `A` is `n` x `n` squared matrix with random elements in `[0,2]`
3. `A` is `n` x `n` hilbert squared matrix
   `A[i, j] = 1 / (1 + i + j)`

by exploiting the PALU decomposition of `A` and by assuming that the exact solution is the unitary vector.
