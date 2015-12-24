#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Array
{
   int *mas, k;
   void Add(int);
   void Sub(int);
public:
   Array():k(0), mas(new int(0)) {};
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


Array::Array(const Array &x):k(x.k)
{
   mas = new int[k];
   for(int i = 0; i < k; i++)
      mas[i] = x.mas[i];
}

void Array::Add(int n)
{
   int *t, pos;
   for (pos = 0; pos < k && mas[pos] < n; pos++) {}
   if (mas[pos]!= n)
   {
      t=new int[++k];
      for(int i = 0; i < k-1; i++)
      t[i < pos?i:i+1] = mas[i];
      t[pos] = n;
      delete[]mas;
      mas = t;
   }
}

void Array::operator+=(Array &x)
{
   for(int i = 0;i < x.k; i++)
      Add(x.mas[i]);
}

void Array::Sub(int n)
{
   if (k > 0)
   {
      int *t, pos;
      for (pos = 0; pos < k && mas[pos] < n; pos++) {}
      if (mas[pos] == n)
      {
         t=new int[--k];
         for(int i = 0; i < k+1; i++)
         if (i != pos) t[i < pos?i:i-1] = mas[i];
         delete[]mas;
         mas = t;
      }
   }
}

void Array::operator-=(const Array &x)
{
   for (int i = 0; i < x.k; i++)
      return Sub(x.mas[i]);
}

Array Array::operator*(const Array &x)const
{
   Array t(*this), t2(*this);
   t-=x;
   for(int i = 0; i < t.k; ++i)
      t2.Sub(t.mas[i]);
      return t2;
}

void Array::operator*=(const Array &x)
{
   Array t(*this);
   t-=x;
   for (int i = 0;i<t.k;i++)
      Sub(t.mas[i]);
}

bool operator==(Array &x, Array &y)
{
   if (x.k != y.k) return false;
   for (int i = 0; i < x.k; i++)
   if (x.mas[i] != y.mas[i]) return false;
   return true;
}

bool operator<=(Array &x, Array &y)
{
   int s = 0;
   for (int i = 0; i < x.k; i++)
   while(x.mas[i] != y.mas[i+s])
   {
      if (x.k+s > y.k) return false;
      s++;
   }
   return true;
}

ostream &operator<<(ostream &s, const Array &p)
{
   if (p.k != 0){
   s<<"(";
   for (int i = 0;i < p.k-1; i++){
      s<<p.mas[i]<<",";
      }
      s<<p.mas[p.k-1];
      }
   return s<<")";
}
istream &operator>>(istream &s, Array &p)
{
  int tmp;
  char c;
  s>>c;

  while(c!=')')
  {
    s>>tmp>> c;
    p.Add(tmp);
    }
    return s;

  }

