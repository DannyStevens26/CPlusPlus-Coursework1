#include <iostream>
#include <cmath>

double *horner(double *cof, double x, int n);
double newton(double *cof, double z, int n, double tol, int nmax);

// Horner will return a dynamic array of all the horner values
double *horner(double *cof, double x, int n)
{
    // Add 1 onto n as there are n+1 coefficients for an n order polynomial
    n = n+1;
    // Initialise horn as dynamic array size n
    double *horn;
    horn = new double[n];
    // Set first horn value as first coefficient
    horn[0] = cof[0];
    // For loop to find following horner values
    for (int i=1;i<n;i++)
    {
        horn[i] = cof[i] + horn[i-1]*x;
    }
    return horn;
}

double newton(double *cof, double z, int n, double tol, int nmax)
{
    // Add 1 onto n as there are n+1 coefficients for an n order polynomial
    n = n+1;
    // Initialise all the variables, including hornew as a dynamic array size n
    double *hornew;
    hornew = new double[n];
    double p, q, ans, zcheck;
    // Ensure error is bigger than tolerance for first loop
    double err = tol + 1;
    // Set up cnt to count no. of iterations
    int cnt = 0;
    // While to ensure tolerance and nmax haven't been met yet
    while (err>tol && cnt<nmax)
    {
        // Each iteration find dynamic array of horner values
        hornew = horner(cof,z,n);
        // Set p as final horner value
        p = hornew[n-1];
        // Set initial q value as 0 for each iteration
        q = 0;
        // For loop to find q (associated polynomial) evaluated at the given z value
        for (int j=0;j<(n-1);j++)
        {
            q = q + hornew[j]*pow(z,(n-2)-j);
        }
        // Store the current z value to check the error
        zcheck = z;
        // Newton method iteration
        z = z - p/q;
        // Calculate error (difference of old z to new z)
        err = fabs(z-zcheck);
        // Increase the count value to check against nmax
        cnt++;
    }

    // Deallocate arrays
    delete[] hornew;
    ans = z;
    return ans;
}
