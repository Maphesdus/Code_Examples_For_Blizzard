// fib2.cpp: An iterative fibonacci solution
#include <cassert>
#include <iostream>
using namespace std;

int fib(int n){
	assert(n >= 0);
	
	// Base cases:
	if(n == 0 || n == 1){
		return n;
	}
	
	int curr = 0
	int next = 1;
	
	for (int i = 2; i <= n; ++i){
		int temp = next;
		next = curr + next;
		curr = temp;
	}

	return next;
}

int main(){
	for (int i: {1, 2, 3, 4})
		cout << fib(i) << endl;
}