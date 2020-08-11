#include <iostream>
#include <cmath>

double lagrange(int n, double *xi, double *f, double x);
double fq3b(double x);
void q3b();

void q3b()
{
    // Initialise variable and dynamic arrays
    int n = 10;
    double *x1, *f1, *x, *x2, *f2;
    x = new double[101];
    x1 = new double[n+1];
    f1 = new double[n+1];
    x2 = new double[n+1];
    f2 = new double[n+1];
    // Set n1 as double n as need to divide by n for Chebyshev nodes and can't do that with an integer
    double n1 = n;
    // For loop to find x1, f1 which are the Chebyshev nodes and function evaluated at those nodes respectively and
    // x2, f2 which are the Uniform nodes and function evaluated at those nodes respectively
    for(int i=0;i<=n;i++)
    {
        x1[i] = -cos((M_PI)*i/n1);
        f1[i] = fq3b(x1[i]);
        x2[i] = -1.+i*2./n1;
        f2[i] = fq3b(x2[i]);
    }
    // For loop to create an array x of uniform points between 1 and -1
    for(int j=0;j<=100;j++)
    {
        x[j] = -1+j*2./100.;
    }
    // Output just the lagrange values so they can be copied and pasted into matlab to create the plots
    for(int k=0;k<=100;k++)
    {
        std::cout << lagrange(n,x2,f2,x[k]) << ", ";
    }
    // Deallocate arrays
    delete[] x1;
    delete[] x2;
    delete[] f1;
    delete[] f2;
}
