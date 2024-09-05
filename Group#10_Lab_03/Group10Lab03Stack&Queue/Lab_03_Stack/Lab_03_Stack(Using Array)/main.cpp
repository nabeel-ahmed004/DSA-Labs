#include <iostream>
#include<Stack.h>
using namespace std;

int main()
{
    Stack stack;
    stack.push(9.6);
    stack.push(-2.0);
    stack.push(-9.0);
    stack.push(4.0);
    stack.print();
    cout << "Top: " << stack.top() << endl;
    stack.pop();
    cout << "Top: " << stack.top() << endl;
    while (!stack.empty()) stack.pop();
    stack.print();
    return 0;
}
