#include <iostream>
#include <cmath>

double chebeval(int n, double x);
void q2a();

void q2a()
{
    std::cout << "Question 2a)\n\n";
    // Set n and x value to put into chebeval
    int n1 = 2;
    double x1 = 0.5;
    // Output the values
    std::cout << "P2(0.5) = " << chebeval(n1,x1) << std::endl;
    // Repeat for different n's and x's
    int n2 = 3;
    double x2 = -0.5;
    std::cout << "P3(-0.5) = " << chebeval(n2,x2) << std::endl;

    int n3 = 9;
    double x3 = 0.7;
    std::cout << "P9(0.7) = " << chebeval(n3,x3) << "\n\n\n";
}
