#include <iostream>
#include <cmath>

double lagrange(int n, double *xi, double *f, double x);
double *chebcoef(int n, double *f);
double chebsum(int n, double *a, double x);
double fq3(double x);
double fq3b(double x);
void q3();
void q3c();

// Define the function x^4+x so it returns the answer for a given x
double fq3(double x)
{
    double ans = pow(x,4)+x;
    return ans;
}

// Define the function 1/(1+16x^2) so it returns the answer for a given x
double fq3b(double x)
{
    double ans = 1./(1.+16.*pow(x,2));
    return ans;
}

void q3()
{
    std::cout << "Question 3a)\n\n";
    // Initialise variable n and dynamic arrays, note x is only used in the TEST to begin with
    int n = 2;
    double *x1, *f1, *x;
    // x1 computes the uniformly spaced nodes, f1 evaluates those nodes at the function
    x1 = new double[n+1];
    f1 = new double[n+1];
    double n1 = double(n);
    for(int i=0;i<=n;i++)
    {
        x1[i] = -1.+i*2./n1;
        f1[i] = fq3(x1[i]);
    }

    /* TEST
    x = new double[n+1];
    x[0] = -1;
    x[1] = 0;
    x[2] = 1;
    for(int j=0;j<3;j++)
    {
        std::cout << "x = " << x[j] << " is " << lagrange(n,x1,f1,x[j]);
        std::cout << " and the error is " << fabs(f1[j] - lagrange(n,x1,f1,x[j])) << std::endl;
    }
    delete[] x;
    */
    // Use lagrange function to interpolate using x1 and f1 at point x = 1/6
    std::cout << "The Lagrangian form of the interpolating polynomial using uniform points, with f(x) = x^4+x and n = " << n << " evaluated at x = 1/6 is " << lagrange(n,x1,f1,1./6.);
    std::cout << " and the error is " << fabs(fq3(1./6.)-lagrange(n,x1,f1,1./6.)) << std::endl;

    // Deallocate arrays
    delete[] x1;
    delete[] f1;

    // Lines 63-78 are a repeat of above but with n = 4
    n = 4;
    double xa = 1./6.;
    x1 = new double[n+1];
    f1 = new double[n+1];
    n1 = double(n);
    for(int i=0;i<=n;i++)
    {
        x1[i] = -1.+i*2./n1;
        f1[i] = fq3(x1[i]);
    }

    std::cout << "The Lagrangian form of the interpolating polynomial using uniform points, with f(x) = x^4+x and n = " << n << " evaluated at x = 1/6 is " << lagrange(n,x1,f1,xa);
    std::cout << " and the error is " << fabs(fq3(xa)-lagrange(n,x1,f1,xa)) << std::endl;

    delete[] x1;
    delete[] f1;

    std::cout << "\n\nQuestion 3b) \n \n";

    // Initialise variables and dynamic arrays
    n = 2;
    xa = 1./6.;
    double *x2, *f2;
    x1 = new double[n+1];
    f1 = new double[n+1];
    x2 = new double[n+1];
    f2 = new double[n+1];
    // n1 is a double so that when computing the Chebyshev nodes it is not computing integer division
    n1 = double(n);
    // x1, f1 are the Chebyshev nodes and function evaluated at those nodes respectively
    // x2, f2 are the Uniform nodes and function evaluated at those nodes respectively
    for(int i=0;i<=n;i++)
    {
        x1[i] = -cos((M_PI)*i/n1);
        f1[i] = fq3(x1[i]);
        x2[i] = -1.+i*2./n1;
        f2[i] = fq3(x2[i]);
    }
    // Output required values
    std::cout << "The Lagrangian form of the interpolating polynomial with f(x) = x^4+x, n = 2 and evaluated at x = 1/6 using:\n";

    std::cout << "Uniform points is " << lagrange(n,x2,f2,xa);
    std::cout << " and the error is " << fabs(fq3(xa)-lagrange(n,x2,f2,xa)) << std::endl;

    std::cout << "Chebyshev points is " << lagrange(n,x1,f1,xa);
    std::cout << " and the error is " << fabs(fq3(xa)-lagrange(n,x1,f1,xa)) << "\n\n\n";
    // Deallocate arrays
    delete[] x1;
    delete[] x2;
    delete[] f1;
    delete[] f2;

    // Initialise dynamic arrays, n contains the different n values and y contains the different x values so that nested for loops
    // can be used to output the required values
    int *na;
    double *y;
    na = new int[2];
    y = new double[2];
    y[0] = 1./6.;
    y[1] = .9;
    na[0] = 2;
    na[1] = 10;
    std::cout << "The Lagrangian form of the interpolating polynomial with f(x) = 1/(1+16x^2), evaluated with:\n";
    // The first for loop calculates/outputs for different x values, the nested for loop calculates/outputs for different n values
    for(int k=0;k<2;k++)
    {
        for(int l=0;l<2;l++)
        {
            // Lines 132-154 are the same as 82-113 but with a different function
            x1 = new double[na[l]+1];
            f1 = new double[na[l]+1];
            x2 = new double[na[l]+1];
            f2 = new double[na[l]+1];
            n1 = double(na[l]);
            for(int i=0;i<=na[l];i++)
            {
                x1[i] = -cos((M_PI)*i/n1);
                f1[i] = fq3b(x1[i]);
                x2[i] = -1.+i*2./n1;
                f2[i] = fq3b(x2[i]);
            }

            std::cout << "Uniform points at x = " << y[k] << " and n = " << na[l] << " is " << lagrange(na[l],x2,f2,y[k]);
            std::cout << " and the error is " << fabs(fq3b(y[k])-lagrange(na[l],x2,f2,y[k])) << std::endl;

            std::cout << "Chebyshev points at x = " << y[k] << " and n = " << na[l] << " is " << lagrange(na[l],x1,f1,y[k]);
            std::cout << " and the error is " << fabs(fq3b(y[k])-lagrange(na[l],x1,f1,y[k])) << std::endl;

            delete[] x1;
            delete[] x2;
            delete[] f1;
            delete[] f2;
        }
    }
}

void q3c()
{
    std::cout << "\n\nQuestion 3c)\n\n";
    // Initialise variable and dynamic array
    int n = 2;
    double *x, *f, *a;
    x = new double[n+1];
    f = new double[n+1];
    a = new double[n+1];
    // For loop to find new Chebyshev nodes used for the Chebyshev form of the interpolating polynomial and the function evaluated at these nodes
    for(int i=0;i<=n;i++)
    {
        x[i] = cos((M_PI)*i/n);
        f[i] = fq3b(x[i]);
    }
    std::cout << "The Chebyshev coefficients are: " << std::endl;
    // Use Chebyshev coefficient function
    a = chebcoef(n,f);
    // Output the Chebyshev coefficients
    for(int i=0;i<=n;i++)
    {
        std::cout << a[i] << std::endl;
    }
    std::cout << "\nThe error is " << fabs(fq3b(.9)-chebsum(n,a,.9)) << std::endl;
    // Deallocate arrays
    delete[] x;
    delete[] f;
    delete[] a;
}

