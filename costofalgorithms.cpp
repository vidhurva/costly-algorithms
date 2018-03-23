#include <iostream>
#include <cmath>
using namespace std;

// function prototypes

template <class T>
T power1(T x, unsigned int n, unsigned int& mults);

template <class T>
T power2(T x, unsigned int n, unsigned int& mults);

template <class T>
T power3(T x, unsigned int n, unsigned int& mults);

template <class T>
void printReport(T base, unsigned int pow,
                 T result1, T result2, T result3,
                 unsigned int mults1, unsigned int mults2,
                 unsigned int mults3);


int main()
{
   unsigned int mults1, mults2, mults3;
   cout << "Test for integer base:\n";
   for (unsigned int pow = 0; pow <= 32; pow++) {
      unsigned int base = 2;
      unsigned int result1 = power1(base, pow, mults1);
      unsigned int result2 = power2(base, pow, mults2);
      unsigned int result3 = power3(base, pow, mults3);
      printReport(base, pow, result1, result2, result3,
                  mults1, mults2, mults3);
   }
   cout << "\nTest for floating-point base:\n";
   for (unsigned int pow = 0; pow <= 64; pow++) {
      double base = 0.5;
      double result1 = power1(base, pow, mults1);
      double result2 = power2(base, pow, mults2);
      double result3 = power3(base, pow, mults3);
      printReport(base, pow, result1, result2, result3,
                  mults1, mults2, mults3);
   }
}

template <class T>
T power1(T x, unsigned int n, unsigned int& mults)
{
   mults = 0;
   T result = 1;
   for(int y = 0; y < n; y++)
      result = result * x;
   for(int x = 1; x < n; x++)    
      mults++;
   return result;
}

template <class T>
T power2(T x, unsigned int n, unsigned int& mults)
{
  mults = 0;
   if (n == 0)
      return 1;
   if (n == 1)
      return x;
  T result = x * power2(x, n - 1, mults);
  mults++;
  return result;
}

template <class T>
T power3(T x, unsigned int n, unsigned int& mults)
{
  mults = 0;
   if (n == 0)
      return 1;
   else if (n == 1)
      return x;
   else if (n%2 == 0)
   {
      T result = power3(x, n/2, mults);
      mults++;
      return result * result;
   }
   else
   {
      T result = power3(x, n/2, mults);
      mults += 2;
      return result * result * x;
   }  
}

template <class T>
void printReport(T base, unsigned int pow,
                 T result1, T result2, T result3,
                 unsigned int mults1, unsigned int mults2,
                 unsigned int mults3)
{
     cout << base << "^" << pow << " = ";
   if (result1 == result2 && result2 == result3)
      cout << result1 << ": ";
   else
      cout << "(" << result1 << ", " << result2 << ", " << result3
           << ") [ERROR!]: ";
   cout << "mults1 = " << mults1 << ", mults2 = " << mults2
        << ", mults3 = " << mults3 << endl;
}