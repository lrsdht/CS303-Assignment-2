#include "SingleLinked.h"
#include "Stack.cpp"

int main() {
    Stack stack;

    cout << "Is the stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;

    // Inserting values onto the stack
    stack.push(5);
    stack.push(10);
    stack.push(15);

    cout << "Is the stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;

    // Removing an element from the stack
    stack.pop();

    // Finding the top of the stack
    cout << "Top of the stack: " << stack.top() << std::endl;

    // Finding the average value of the stack elements
    cout << "Average value of stack elements: " << std::fixed << std::setprecision(2) << stack.average() << std::endl;

    return 0;
}