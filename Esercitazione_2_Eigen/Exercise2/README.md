# Linear System (2)

Solving linear system plays a key role in many scientific application, such as engineering, physics, chemistry, computer science, and economics. 

## Example 

The solution of the linear system `Ax = b` can be retrieved as

```text
Ly = Pb

Ux = y
```

by exploiting the PALU decomposition of `A` or throughout its QR decomposition as

```text
y = Q' b

R x = y
```

## Requirements

Write a software able to compute the linear system solution with PALU and QR decomposition of the following systems:

1. `A = [5.547001962252291e-01, -3.770900990025203e-02; 8.320502943378437e-01, -9.992887623566787e-01]`

   `b = [-5.169911863249772e-01; 1.672384680188350e-01]`
   
2. `A = [5.547001962252291e-01, -5.540607316466765e-01; 8.320502943378437e-01, -8.324762492991313e-01]`

   `b = [-6.394645785530173e-04; 4.259549612877223e-04]`
   
3. `A = [5.547001962252291e-01, -5.547001955851905e-01; 8.320502943378437e-01, -8.320502947645361e-01]`

   `b = [-6.400391328043042e-10; 4.266924591433963e-10]`

All the three system shall have solution
`x = [-1.0e+0; -1.0e+00]`

Check for each system the relative error.
