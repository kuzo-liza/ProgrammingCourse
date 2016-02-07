#include <iostream>
#include "polynomial.h"

using namespace std;

int main()
{
    Polynomial pm1;

    cout << "\nPolynomial 1: ";
    pm1.print();

    Polynomial pm2(5);

    cout << "\nPolynomial 2: ";
    pm2.print();

    std::cout << "\nSet polynomial 2 coefficients:\n";
    for (unsigned int i = 0; i <= pm2.getPolynomialDegree(); i++)
    {
        double coeff;
        std::cin >> coeff;
        pm2.setPolynomialCoeff(i, coeff);
    }

    cout << "\nPolynomial 2 after changing coefficients:\n";
    pm2.print();

    cout << "\nPolynomial 3 = Polynomial 1 + Polynomial 2:\n";
    Polynomial pm3 = pm1 + pm2;
    pm3.print();

    cout << "\nPolynomial 3 = Polynomial 1 - Polynomial 2:\n";
    pm3 = pm1 - pm2;
    pm3.print();

    cout << "\nPolynomial 3 = Polynomial 1 * Polynomial 2:\n";
    pm3 = pm1 * pm2;
    pm3.print();

    cout << "\nPolynomial 3 value in x = 3: ";
    cout << pm3.calculate(3) << endl;

    system("pause");
    return 0;
}
