#include <iostream>
#include <string>
using namespace std;
template<class T>
class Stack {
	T n[100];
	int top = -1;
public:
	void push(T a) {
		n[++top] = a;
	};
	T pop() {
		return n[top--];
	}
	T peek() {
		return n[top];
	}

};


int main() {
	Stack<int> integer_stack;
	Stack<string> string_stack;
	integer_stack.push(2);
	integer_stack.push(54);
	integer_stack.push(255);

	string_stack.push("Welcome");
	string_stack.push("to");
	string_stack.push("C++ World");

	cout << integer_stack.pop() << " is removed from stack" << endl;
	cout << string_stack.pop() << " is removed from stack " << endl;

	cout << "Top element is " << integer_stack.peek() << endl;

	cout << "Top element is " << string_stack.peek() << endl;

}