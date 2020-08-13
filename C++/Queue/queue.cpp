#include <iostream>
#include <queue>

using namespace std;

void print_queue(queue <int> q) {
	queue <int> printQu = q;
	while (!printQu.empty()) {
		cout << " " << printQu.front();
		printQu.pop();
	}
	cout << "\n";
}

int main () {
	queue <int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	
	cout << "The queue is:";
	print_queue(q);
	
	cout << "The front of the queue is: " << q.front();
	printf("\n");
	cout << "The end of the queue is: " << q.back();
	printf("\n");
	cout << "The size of the queue is: " << q.size();
	printf("\n");
	q.pop();
	print_queue(q);
}






