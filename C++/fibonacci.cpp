#include <iostream>

using namespace std;

int fibo(int n) {
	if (n <= 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	} 
	else {
		return fibo(n - 1) + fibo(n - 2);
	}

}

int main() {
	int n;
	printf("Enter a sequence in the fibonacci series: ");
	scanf("%d", &n);
	int myNum = fibo(n);
	
	printf("The %d term is: %d\n", n, myNum);

	return 0;
}




























































