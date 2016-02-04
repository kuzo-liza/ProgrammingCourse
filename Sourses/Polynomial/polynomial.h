#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

class Polynomial
{
public:
    //Конструктор по умолчанию, создаёт многочлен второй степени
    Polynomial();
    //Конструктор с параметром, принимает значение степени многочлена
    Polynomial(unsigned int _polynomialDegree);
    //Деструктор
    ~Polynomial();

    //Перегрузка оператора + для сложения многочленов
    Polynomial operator +(Polynomial& anotherPolynomial);
    //Перегрузка оператора - для вычитания многочленов
    Polynomial operator -(Polynomial& anotherPolynomial);
    //Перегрузка оператора * для умножения многочленов
    Polynomial operator *(Polynomial& anotherPolynomial);
    //Перегрузка оператора = для присвоения значения многочлену
    Polynomial& operator =(const Polynomial& anotherPolynomial);
    //Конструктор копирования
    Polynomial (const Polynomial& anotherPolynomial);

    //Функция вывода многочлена в консоль
    void print();
    //Функция для получения степени многочлена
    unsigned int getPolynomialDegree();
    //Функция для вычисления значения многочлена при заданном Х
    double calculate(double x);
    //Функция присвоения значению коэффициента на позиции coeffNumber значения coeffValue
    void setPolynomialCoeff(unsigned int coeffNumber, double coeffValue);

private:
    //Степень многочлена
    unsigned int polynomialDegree;
    //Массив коэффициентов
    double *polynomialCoeff;
};

#endif // POLYNOMIAL_H
