#include <iostream>

using namespace std;

int factorial (int myNum) {
	int x = myNum;
	//Need to recurse this number somehow
	if (myNum != 1) {
		myNum--;
		myNum = x * factorial(myNum);
	}
	return myNum;
}

int main () {
	int myNum;
	cout << "Enter a number: ";
	cin >> myNum;
	myNum = factorial(myNum);
	
	cout << myNum << "\n";
}








































