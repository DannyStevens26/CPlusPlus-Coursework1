#include <iostream>
#include <cmath>

double *horner(double *cof, double x, int n);
double newton(double *cof, double z, int n, double tol, int nmax);
void q1c();

void q1c()
{
    std::cout << "Question 1c)\n\n";
    // Initialise variables
    int n;
    int m;
    double z;
    double tol;
    int nmax;
    double *test1c, *root, *horn1c;

    /* TEST of the roots of x^2-1
    n = 2;
    m = n;
    z = 4;
    tol = 10e-8;
    nmax = 20;
    horn1c = new double[3];
    root = new double[3];
    test1c = new double[3];
    test1c[0] = 1;
    test1c[1] = 0;
    test1c[2] = -1;
    horn1c = horner(test1c,z,n);
    for(int i=0; i<n; i++)
    {
        root[i] = newton(test1c,z,m,tol,nmax);
        horn1c = horner(test1c,root[i],m);
        for (int j=1; j<n; j++)
        {
            test1c[j] = test1c[j]+horn1c[j]*root[i];
        }
        m = m-1;
    }
    std::cout << "The roots of x^2-1 are: " << std::endl;
    for(int k=0; k<n; k++)
    {
        std::cout << "x = " << root[k] << std::endl;
    }
    delete[] horn1c;
    delete[] root;
    delete[] test1c;
    */

    n = 5;
    m = n;
    z = 4;
    tol = 10e-8;
    nmax = 20;
    // Set the size for the dynamic arrays
    horn1c = new double[6];
    root = new double[5];
    test1c = new double[6];
    // test1c is the polynomial coefficients
    test1c[0] = 1;
    test1c[1] = 1;
    test1c[2] = -9;
    test1c[3] = -1;
    test1c[4] = 20;
    test1c[5] = -12;
    // A for loop that finds a root on each loop
    for(int i=0; i<n; i++)
    {
        // Find one approximate root of the polynomial using newton
        root[i] = newton(test1c,z,m,tol,nmax);
        // Calculate all horner values evaluated at the root just calculated
        horn1c = horner(test1c,root[i],m);
        // For loop to set the new polynomial coefficients as horner values calculated above (i.e. deflation procedure)
        for (int j=0; j<m; j++)
        {
            test1c[j] = horn1c[j];
        }
        // Deflation procedure reduces order by 1 so consider 1 less coefficient
        m = m-1;
    }
    std::cout << "\nThe approximate roots of x^5+x^4-9x^3+20x-12 are: " << std::endl;
    // Output roots
    for(int k=0; k<n; k++)
    {
        std::cout << "x = " << root[k] << std::endl;
    }
    std::cout << "\n\n";
    // Deallocate arrays
    delete[] horn1c;
    delete[] root;
    delete[] test1c;
}
