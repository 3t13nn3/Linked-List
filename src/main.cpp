#include "LinkedList.hpp"
#include <iostream>

int main() {

	linked::LinkedList<int> l;
	std::cout << "Instanciate the list:" << std::endl;
	std::cout << "-- " << l << "\n" << std::endl;

	for (size_t i(0); i < 10; ++i) {
		l.Push(i);
	}
	std::cout << "Filling list with Push():" << std::endl;
	std::cout << "-- " << l << "\n" << std::endl;

	l.Insert(42, 5);
	std::cout << "Inserting 42 at index 5 with Insert():" << std::endl;
	std::cout << "-- " << l << "\n" << std::endl;

	l.Remove(5);
	std::cout << "Removing the 5th element with Remove():" << std::endl;
	std::cout << "-- " << l << "\n" << std::endl;

	l.Swap(0, 9);
	std::cout << "Swapping the 0th element with the 9th with Swap():"
			  << std::endl;
	std::cout << "-- " << l << "\n" << std::endl;

	l.Reverse();
	std::cout << "Reversing the list with Reverse():" << std::endl;
	std::cout << "-- " << l << "\n" << std::endl;

	std::cout << "Is the list empty with Empty():" << std::endl;
	std::cout << "-- " << l.Empty() << "\n" << std::endl;

	l.Clear();
	std::cout << "Is the list empty after calling Clear() with Empty():"
			  << std::endl;
	std::cout << "-- " << l.Empty() << std::endl;

	return 0;
}