//============================================================================
// Name        : Dynamic-Prog-Fibo.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : C/C++ program for Memoized version for nth Fibonacci number */
//============================================================================

#include <iostream>
#include <stdio.h>
#define NIL -1
#define MAX 100

int lookup[MAX];

using namespace std;

/* Function to initialize NIL values in lookup table */
void _initialize()
{
  int i;
  for (i = 0; i < MAX; i++)
    lookup[i] = NIL;
}

/* function for nth Fibonacci number */
int fib(int n)
{
   if (lookup[n] == NIL)
   {
      if (n <= 1)
         lookup[n] = n;
      else
         lookup[n] = fib(n-1) + fib(n-2);
      cout<<lookup[n]<<endl;
   }

   return lookup[n];
}

int main() {
	  int n = 40;
	  _initialize();
	  cout<<"Fibonacci number is %d "<< fib(n)<<endl;
	  return 0;
}
