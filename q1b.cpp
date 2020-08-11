#include <iostream>
#include <cmath>

double newton(double *cof, double z, int n, double tol, int nmax);
void q1b();

void q1b()
{
    std::cout << "Question 1b)\n\n";
    // Initialise variables and the dynamic array
    double z, ans, tol;
    double *test1b;
    int n, nmax;
    tol = 10e-8;
    nmax = 10;
    n = 2;
    z = 4;
    // Test1b is a dynamic array with the polynomial coefficients
    test1b = new double[3];
    test1b[0] = 1;
    test1b[1] = 0;
    test1b[2] = -1;
    // Use newton function and output approximate root
    ans = newton(test1b,z,n,tol,nmax);
    std::cout << "An approximate root of x^2-1, with nmax = 10 and initial guess z0 = 4, is: " << ans << std::endl;
    // Deallocate arrays
    delete[] test1b;

    // Lines 30-58 are a repeat of the process above but with a different polynomial and with varying nmax
    z = 4;
    n = 5;
    tol = 10e-8;
    nmax = 5;
    test1b = new double[6];
    test1b[0] = 1;
    test1b[1] = 1;
    test1b[2] = -9;
    test1b[3] = -1;
    test1b[4] = 20;
    test1b[5] = -12;
    ans = newton(test1b,z,n,tol,nmax);
    std::cout << "An approximate root of x^5+x^4-9x^3-x^2+20x-12, with nmax = 5 and initial guess z0 = 4, is: " << ans << std::endl;
    delete[] test1b;

    z = 4;
    n = 5;
    tol = 10e-8;
    nmax = 10;
    test1b = new double[6];
    test1b[0] = 1;
    test1b[1] = 1;
    test1b[2] = -9;
    test1b[3] = -1;
    test1b[4] = 20;
    test1b[5] = -12;
    ans = newton(test1b,z,n,tol,nmax);
    std::cout << "An approximate root of x^5+x^4-9x^3-x^2+20x-12, with nmax = 10 and initial guess z0 = 4, is: " << ans << "\n\n\n";
    delete[] test1b;
}


