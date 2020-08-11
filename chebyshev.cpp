#include <iostream>
#include <cmath>

double chebeval(int n, double x);
double chebsum(int n, double *a, double x);

double chebeval(int n, double x)
{
    // Initialise variable and dynamic array
    double *cheb;
    double chebans;
    cheb = new double[n+1];
    // Set first Chebyshev values
    cheb[0] = 1;
    cheb[1] = x;
    // For loop for the Chebyshev recursion formula
    for (int i=2;i<n+1;i++)
    {
        cheb[i] = 2*x*cheb[i-1]-cheb[i-2];
    }
    // Set chebans as the final Chebyshev value
    chebans = cheb[n];
    // Deallocate arrays
    delete[] cheb;
    return chebans;
}

double chebsum(int n, double *a, double x)
{
    // Initialise variable and dynamic array
    double *b;
    double chebsumans;
    b = new double[n+3];
    // Set the first Clenshaw algorithm values
    b[n+2] = 0;
    b[n+1] = 0;
    // For loop to compute the Clenshaw algorithm
    for(int i=n;i>0;i--)
    {
        b[i] = a[i] + 2*x*b[i+1] - b[i+2];
    }
    // Formula to compute the sum
    b[0] = a[0] + x*b[1] - b[2];
    // Set chebsumans as the final sum value
    chebsumans = b[0];
    // Deallocate arrays
    delete[] b;
    return chebsumans;
}

double *chebcoef(int n, double *f)
{
    // Initialise the dynamic arrays, a will contain the Chebyshev coefficients
    double *d, *a;
    d = new double[n+1];
    a = new double[n+1];
    // Set end d points as 2 and the rest set as 1 using a for loop
    d[0]=2;
    d[n]=2;
    for(int i=1;i<n;i++)
    {
        d[i]=1;
    }
    // The first for loop is for each a(i) value and the nested for loop is for the sum at each i
    for(int k=0;k<=n;k++)
    {
        // Set a(i) as 0 initially as the values will be summed onto the current a(i)
        a[k]=0;
        // For loop computes the sum for each a(i)
        for(int j=0;j<=n;j++)
        {
           a[k] = a[k]+(2./(double(n)*d[k]))*(f[j]/d[j])*cos(k*j*M_PI/double(n));
        }
    }
    // Return the dynamic array a
    return a;
}
