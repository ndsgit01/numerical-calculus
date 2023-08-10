# numerical-calculus

Project contains, 
- implementations of a few Numerical Analysis algorithms to approximate a few basic operations in Calculus
- application of above approximations in a 'convoluted' way to estimate (well... correctly upto atleast 5 decimal places without too much fine tuning) the famous mathematical constants:
    - $\pi$ (Integration: approximation of area of a quarter circle with radius 2 will infact be the approximation of $\pi$)
    - $e$  (solving ordinary differential equation:  differentiation of a function is itself and the value of the function at 0 is 1, approximating the value of the solution to this ode at 1 will approximate $e$, since the solution is the function $e^x$)

The implemented methods are listed below:

## Numerical methods for:

### Differentiation:
(Finite difference approximations of first derivative) [ Ref: https://en.wikipedia.org/wiki/Numerical_differentiation ]
-  Newton's difference quotient
-  Symmetric difference quotient
-  Five-point method

*Areas to explore: - step size, higher order derivatives, differential quadrature*

### Integration:
(Quadrature rules applying Riemann sum to approximate one dimensional single definite intervals with finite limits) [ Ref: https://en.wikipedia.org/wiki/Numerical_integration , https://en.wikipedia.org/wiki/Riemann_sum ]
-  Midpoint rule
-  Trapezoidal rule
-  composite Simpson's 1/3 rule

*Areas to explore: - adaptive - non uniform step width, unbounded interval limits, multi dimensional integrals*

### Ordinary Differential Equations
(An explicit RungeKutta method - forward Euler method to approximate value of the solution to the first order ode with inital value) [ Ref: https://en.wikipedia.org/wiki/Euler_method ]
- Euler method

*Areas to explore: - higher order ode, linear multistep methods*
