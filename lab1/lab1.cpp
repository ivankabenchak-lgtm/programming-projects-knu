/*
 * Programming project No. 1, variant 161.
 * Author: Ivanna Benchak, group ITK-11.
 */

#include <cmath>
#include <iomanip>
#include <iostream>
#include <numbers>

/// Thrown when the argument lies outside the domain of the expression.
struct OutOfDomain
{
};

/// Displays information about the author and the task.
void showHeader()
{
    std::cout << "The author of this program is Ivanna Benchak, ITK-11.\n"
              << "The program evaluates the expression of variant 161 "
                 "for a real argument x.\n";
}

/// Tells whether the expression is defined at x.
/// Domain: x > -8, x != -5, x != 13.
bool isDefinedAt(double x)
{
    return x > -8 && x != -5 && x != 13;
}

/// Evaluates the expression of variant 161 at x.
double f(double x)
{
    const double pi = std::numbers::pi;
    const double e = std::numbers::e;
    return std::sin(22.0 / 67) - 17 * pi
           - 57 * e * 15 / ((x + 5) * (x - 13))
           + 11 * std::cos(x - 3) + std::log(x + 8) / std::log(9.0);
}

/// Evaluates the expression at x.
/// Throws OutOfDomain if the expression is undefined at x.
double evaluate(double x)
{
    if (!isDefinedAt(x))
        throw OutOfDomain{};
    return f(x);
}

/// Displays the entered argument.
void showArgument(double x)
{
    std::cout << std::fixed << std::setprecision(5) << "for x = " << x << '\n';
}

/// Displays the value of the expression, or "undefined" if it has none.
void showResult(bool isDefined, double value)
{
    std::cout << "result = ";
    if (isDefined)
        std::cout << std::setprecision(9) << value << '\n';
    else
        std::cout << "undefined\n";
}

int main()
{
    showHeader();

    double arg;
    std::cout << "Enter a real number x (x > -8, x != -5, x != 13): ";
    std::cin >> arg;

    if (std::cin.fail())
        std::cout << "\nwrong input\n";
    else
    {
        std::cout << "\n***** do calculations ... ";
        bool isDefined = true;
        double value = 0;
        try
        {
            value = evaluate(arg);
        }
        catch (const OutOfDomain&)
        {
            isDefined = false;
        }
        std::cout << "done\n";

        showArgument(arg);
        showResult(isDefined, value);
    }
}
