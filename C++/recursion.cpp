#include <iostream>

using namespace std;

int sum (int num) {

	if (num != 0) {
		return num + sum(num - 1);
	} 
	else {
		return num;
	}

}

int main () {
	int n;		
	cout <<"Enter a number to sum a sequence of natural number: ";
	cin >> n;
	int total = sum(n);
	
	cout<<"The sum of natural numbes from 1 to " << n << " are: " << total << endl;
	return 0;
}























































