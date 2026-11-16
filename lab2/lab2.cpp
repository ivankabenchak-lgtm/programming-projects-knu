/*
 * Programming project No. 2, variant 161.
 * Author: Ivanna Benchak, group ITK-11.
 */

#include <cmath>
#include <iomanip>
#include <iostream>

const double a = 0.0;
const double b = 1.0;

/// Thrown when an input value cannot be used for the calculation.
/// Holds a short explanation of the problem.
struct InputError
{
    const char* reason;
};

/// Displays information about the author and the task.
void showHeader()
{
    std::cout << "The author of this program is Ivanna Benchak, ITK-11.\n"
              << "Variant 161. The program finds the sum of a power series "
                 "S(x)\nat a point x with the accuracy eps.\n";
}

/// Reads the point x.
/// Throws InputError if x is not a number or lies outside [a; b].
double readPoint()
{
    double x;
    std::cout << "Enter a real number x from [" << a << "; " << b << "]: ";
    std::cin >> x;
    if (std::cin.fail())
        throw InputError{"input error: x is not a number"};
    if (x < a || x > b)
        throw InputError{"wrong value: x does not belong to [0; 1]"};
    return x;
}

/// Reads the accuracy eps.
/// Throws InputError if eps is not a number or is not positive.
double readAccuracy()
{
    double eps;
    std::cout << "Enter the accuracy eps (a positive number): ";
    std::cin >> eps;
    if (std::cin.fail())
        throw InputError{"input error: eps is not a number"};
    if (eps <= 0)
        throw InputError{"wrong value: eps must be positive"};
    return eps;
}

/// Finds S(x) of variant 161. Terms are added until the first term
/// with absolute value less than eps, which is still included.
double s(double x, double eps)
{
    const double xPow4 = x * x * x * x;
    double current = 1;
    double total = current;
    int k = 0;
    while (std::abs(current) >= eps)
    {
        const double denominator = (2 * k + 1) * (2 * k + 2);
        current *= xPow4 / (denominator * denominator);
        total += current;
        ++k;
    }
    return total;
}

/// Displays the entered point and accuracy.
void showInput(double x, double eps)
{
    std::cout << std::scientific << std::uppercase
              << "for x = " << std::setprecision(7) << x << '\n'
              << "for eps = " << std::setprecision(9) << eps << '\n';
}

/// Displays the found value of S(x).
void showResult(double value)
{
    std::cout << std::fixed << std::setprecision(8)
              << "result = " << value << '\n';
}

int main()
{
    showHeader();

    try
    {
        const double x = readPoint();
        const double eps = readAccuracy();

        std::cout << "\n***** do calculations ... ";
        const double value = s(x, eps);
        std::cout << "done\n";

        showInput(x, eps);
        showResult(value);
    }
    catch (const InputError& error)
    {
        std::cout << "\n***** error\n" << error.reason
                  << "\nS(x) cannot be found\n";
    }
}
