#include <priorityQueue.h>
#include <priorityQueue.cpp>
#include <iomanip>

int main() {
	double cost[10] = {6.8, 3.6, 1.9, 3.0, 6.0, 9.9, 12.1, 10.5, 19.3, 15.6 };
	PriorityQueue<double> queue ( cost, 10 );
	cout.setf ( ios:: fixed );
	cout << setprecision ( 1 ) << queue.Peek() << "  ";
	queue.Pop();
	cout << queue.Peek() << "  ";
	queue.Pop();
	queue.Push ( 0.8 );
	cout << endl << queue.updateKey ( 0, 5.8 ) << endl;
	while ( !queue.isEmpty() ) {
		cout << queue.Peek() << "  ";
		queue.Pop();
	}
	return 0;
}
