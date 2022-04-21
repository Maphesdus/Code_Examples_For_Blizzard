// fib1.cpp: A recursive fibonacci solution
#include <cassert>
#include <iostream>
using namespace std;

int fib(int n){
	assert(n >= 0);
	return (n == 0 || n == 1) ? n : fib(n-1) + fib(n-2);
}

int main(){
   for (int i: {1, 2, 3, 4})
      cout << fib(i) << endl;
}