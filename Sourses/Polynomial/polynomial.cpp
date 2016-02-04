#include "polynomial.h"
#include "math.h"
#include <iostream>

Polynomial::Polynomial()
{
    polynomialDegree = 2;
    polynomialCoeff = new double[polynomialDegree + 1];
    for (unsigned int i = 0; i <= polynomialDegree; i++)
        polynomialCoeff[i] = 1;
}

Polynomial::Polynomial(unsigned int _polynomialDegree)
{
    polynomialDegree = _polynomialDegree;
    polynomialCoeff = new double[polynomialDegree + 1];
    for (unsigned int i = 0; i <= polynomialDegree; i++)
        polynomialCoeff[i] = 1;
}

Polynomial::~Polynomial()
{
    delete [] polynomialCoeff;
}

Polynomial Polynomial::operator +(Polynomial& anotherPolynomial)
{
    double *newPolynomialCoeff;
    unsigned int newPolynomialDegree;

    if (polynomialDegree < anotherPolynomial.polynomialDegree)
    {
        newPolynomialCoeff = new double [anotherPolynomial.polynomialDegree + 1];
        newPolynomialDegree = anotherPolynomial.polynomialDegree;

        for (unsigned int i = 0; i <= anotherPolynomial.polynomialDegree; i++)
        {
            if (i <= polynomialDegree)
                newPolynomialCoeff[i] = polynomialCoeff[i] + anotherPolynomial.polynomialCoeff[i];
            else
                newPolynomialCoeff[i] = anotherPolynomial.polynomialCoeff[i];
        }

    } else
    {
        newPolynomialCoeff = new double [polynomialDegree + 1];
        newPolynomialDegree = polynomialDegree;

        for (unsigned int i = 0; i <= polynomialDegree; i++)
        {
            if (i <= anotherPolynomial.polynomialDegree)
                newPolynomialCoeff[i] = polynomialCoeff[i] + anotherPolynomial.polynomialCoeff[i];
            else
                newPolynomialCoeff[i] = polynomialCoeff[i];
        }
    }

    Polynomial newPolynomial(newPolynomialDegree);
    for (unsigned int i = 0; i <= newPolynomial.getPolynomialDegree(); i++)
        newPolynomial.setPolynomialCoeff(i, newPolynomialCoeff[i]);

    return newPolynomial;
}

Polynomial Polynomial::operator -(Polynomial& anotherPolynomial)
{
    double *newPolynomialCoeff;
    unsigned int newPolynomialDegree;

    if (polynomialDegree < anotherPolynomial.polynomialDegree)
    {
        newPolynomialCoeff = new double [anotherPolynomial.polynomialDegree + 1];
        newPolynomialDegree = anotherPolynomial.polynomialDegree;

        for (unsigned int i = 0; i <= anotherPolynomial.polynomialDegree; i++)
        {
            if (i <= polynomialDegree)
                newPolynomialCoeff[i] = polynomialCoeff[i] - anotherPolynomial.polynomialCoeff[i];
            else
                newPolynomialCoeff[i] = -1 * anotherPolynomial.polynomialCoeff[i];
        }

    } else
    {
        newPolynomialCoeff = new double [polynomialDegree + 1];
        newPolynomialDegree = polynomialDegree;

        for (unsigned int i = 0; i <= polynomialDegree; i++)
        {
            if (i <= anotherPolynomial.polynomialDegree)
                newPolynomialCoeff[i] = polynomialCoeff[i] - anotherPolynomial.polynomialCoeff[i];
            else
                newPolynomialCoeff[i] = polynomialCoeff[i];
        }
    }

    Polynomial newPolynomial(newPolynomialDegree);
    for (unsigned int i = 0; i <= newPolynomial.getPolynomialDegree(); i++)
        newPolynomial.setPolynomialCoeff(i, newPolynomialCoeff[i]);

    return newPolynomial;
}

Polynomial Polynomial::operator *(Polynomial& anotherPolynomial)
{
    unsigned int newPolynomialDegree = polynomialDegree + anotherPolynomial.polynomialDegree;
    double *newPolynomialCoeff = new double [newPolynomialDegree + 1];

    for (unsigned int i = 0; i <= newPolynomialDegree; i++)
        newPolynomialCoeff[i] = 0;

    for (unsigned int i = 0; i <= polynomialDegree; i++)
       for (unsigned int j = 0; j <= anotherPolynomial.polynomialDegree; j++)
           newPolynomialCoeff[i + j] += polynomialCoeff[i]*anotherPolynomial.polynomialCoeff[j];

    Polynomial newPolynomial(newPolynomialDegree);

    for (unsigned int i = 0; i <= newPolynomial.getPolynomialDegree(); i++)
        newPolynomial.setPolynomialCoeff(i, newPolynomialCoeff[i]);

    return newPolynomial;
}

Polynomial& Polynomial::operator =(const Polynomial& anotherPolynomial)
{
    if (&anotherPolynomial == this)
        return *this;

    delete [] polynomialCoeff;
    polynomialDegree = anotherPolynomial.polynomialDegree;
    polynomialCoeff = new double[polynomialDegree + 1];
    for (unsigned int i = 0; i <= polynomialDegree; i++)
        polynomialCoeff[i] = anotherPolynomial.polynomialCoeff[i];

    return *this;
}

Polynomial::Polynomial (const Polynomial& anotherPolynomial)
{
    polynomialDegree = anotherPolynomial.polynomialDegree;

    polynomialCoeff = new double[anotherPolynomial.polynomialDegree + 1];

    for (unsigned int i = 0; i <= anotherPolynomial.polynomialDegree; i++)
        polynomialCoeff[i] = anotherPolynomial.polynomialCoeff[i];
}

void Polynomial::print()
{
    for (int i = polynomialDegree; i >=0; i--)
    {
        std::cout << "(" << polynomialCoeff[i];

        if (i != 0)
            std::cout << "*x^" << i << ") + ";
        else
            std::cout << ")\n";
    }
}

unsigned int Polynomial::getPolynomialDegree()
{
    return this->polynomialDegree;
}

double Polynomial::calculate(double x)
{
    double polynomialValue = 0;
    for (unsigned int i = 0; i <= polynomialDegree; i++)
    {
        polynomialValue += polynomialCoeff[i]*pow(x, i);
    }

    return polynomialValue;
}

void Polynomial::setPolynomialCoeff(unsigned int coeffNumber, double coeffValue)
{
    if (coeffNumber > polynomialDegree)
        return;

    polynomialCoeff[coeffNumber] = coeffValue;
}
