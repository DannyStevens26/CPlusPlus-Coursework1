#include <iostream>
#include <cmath>

double chebeval(int n, double x);
double chebsum(int n, double *a, double x);
void q2b();

void q2b()
{
    std::cout << "Question 2b)\n\nFor a[i]=1:\n";
    // Initialise variables and a dynamic array, a has the coefficients of the sum
    int n = 3;
    double *a, x;
    a = new double[4];
    a[0]=1;
    a[1]=1;
    a[2]=1;
    a[3]=1;
    x = 0.5;
    // Output answer
    std::cout << "The Chebyshev sum for n = 3, x = 0.5 is " << chebsum(n,a,x) << std::endl;
    // Deallocate arrays
    delete[] a;

    std::cout << "\nFor a[i]=i:\n";
    n = 10;
    // Set up array x1 so that a for loop can be used to output the Chebyshev sums
    double *x1;
    a = new double[11];
    x1 = new double[5];
    x1[0]=-1.;
    x1[1]=-0.5;
    x1[2]=0.;
    x1[3]=0.5;
    x1[4]=1.;
    // For loop to set coefficients
    for(int i=0;i<11;i++)
    {
        a[i]=i;
    }
    // For loop to compute and output the Chebyshev sums
    for (int j=0;j<5;j++)
    {
        std::cout << "The Chebyshev sum for n = 10, x = " << x1[j] << " is " << chebsum(n,a,x1[j]) << std::endl;
    }
    std::cout << "\n\n";
    // Deallocate arrays
    delete[] a;
    delete[] x1;
}
