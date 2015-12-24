#ifndef PLURALITY
#define PLURALITY

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

class Array
{
   int *mas,k;
   void Add(int);
   void Sub(int);
public:
   Array():k(0),mas(new int(0)) {};
   Array(const Array &);
   ~Array() {delete[]mas;};
   void operator+=(int n) {Add(n);};
   void operator+=(Array &);
   void operator-=(int n) {Sub(n);};
   void operator-=(const Array &);
   Array operator*(const Array &)const;
   void operator*=(const Array &);
   friend bool operator==(Array &, Array &);
   friend bool operator<=(Array &, Array &);
   friend ostream& operator<<(ostream &, const Array &);
   friend istream& operator>>(istream &s, Array &);
   int HowMany() {return k;};
};

#endif // PLURALITY
