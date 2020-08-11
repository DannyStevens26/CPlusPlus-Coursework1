// Include appropriate libraries, this is done in all files in the coursework
#include <iostream>
#include <cmath>

// Function prototypes, this is done in all the files in the coursework
double *horner(double *cof, double x, int n);
void q1a();
void q1b();
void q1c();
void q2a();
void q2b();
void q3();
void q3b();
void q3c();

void q1a()
{
    // Initialise variables, with test as polynomial coefficients, polynomial found at point x
    // hornans is the function horner dynamic array output
    double x = 0.5;
    double *test, *hornans;
    test = new double[4];
    hornans = new double[4];
    test[0] = 1.0;
    test[1] = 2.0;
    test[2] = 0.0;
    test[3] = 3.0;
    int n1 = 4;
    hornans = horner(test,x,n1);
    std::cout << "Question 1a)\n\n";
    // Output the final horner value
    std::cout << "The polynomial evaluated at x is: " << hornans[3] << "\n\n\n";
    // Deallocate arrays
    delete[] test;
    delete[] hornans;
}

// The main here runs every question part at once in the project "Coursework"
// Q3b is not run as its output is not needed but is there to be checked if required
int main(int arc, char* argv[])
{
    q1a();
    q1b();
    q1c();
    q2a();
    q2b();
    q3();
    //q3b();
    q3c();
}

