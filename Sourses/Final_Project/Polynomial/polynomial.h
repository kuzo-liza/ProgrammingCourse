#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

class Polynomial
{
public:
    Polynomial();
    Polynomial(unsigned int _polynomialDegree);
    ~Polynomial();

    Polynomial operator +(Polynomial& anotherPolynomial);
    Polynomial operator -(Polynomial& anotherPolynomial);
    Polynomial operator *(Polynomial& anotherPolynomial);
    Polynomial& operator =(const Polynomial& anotherPolynomial);
    Polynomial (const Polynomial& anotherPolynomial);

    void print();
    unsigned int getPolynomialDegree();
    double calculate(double x);
    void setPolynomialCoeff(unsigned int coeffNumber, double coeffValue);

private:
    unsigned int polynomialDegree;
    double *polynomialCoeff;
};

#endif // POLYNOMIAL_H
