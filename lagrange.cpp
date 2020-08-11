#include <iostream>
#include <cmath>

double lagrange(int n, double *xi, double *f, double x);

double lagrange(int n, double *xi, double *f, double x)
{
    // Initialise variable and dynamic array
    double *l,p;
    l = new double[n+1];
    // Set the initial value of the sum pn(x) as 0
    p=0;
    // For loops used to set the l(i) values
    for(int i=0;i<=n;i++)
    {
        // Set initial l(i) as 1 as the next for loop computes the product so needs an initial values to multiply
        l[i]=1;
        // For loop computes the product given by the Lagrange interpolant formula
        for(int j=0;j<=n;j++)
        {
            // Use if statement to make sure j!=i product isn't included
            if(j!=i)
            {
                l[i] = (x-xi[j])/(xi[i]-xi[j])*l[i];
            }
        }
    }
    // For loop that computes the sum for the Lagrange form of the interpolating polynomial
    for(int k=0;k<=n;k++)
    {
        p = p + f[k]*l[k];
    }
    // Deallocate array
    delete[] l;
    return p;
}
