// Evaluate your solution here
#include "utils/stack.hpp" 
#include <iostream>
#include "./utils/postfix_eval.hpp"
#include <cassert>

using namespace std;

void case1(PostfixEval pe){
    assert(pe.evaluate("2 3 +") == 5);
    assert(pe.evaluate("2 3 -") == -1);
    assert(pe.evaluate("2 3 *") == 6);
    assert(pe.evaluate("6 3 /") == 2);
    assert(pe.evaluate("2 3 ^") == 8);
}

void case2(PostfixEval pe){
    assert(pe.evaluate("2 3 4 + *") == 14);
    assert(pe.evaluate("2 3 4 + * 15 - 3 +") == 2);
}

void case3(PostfixEval pe){
    assert(pe.evaluate("10 50 + 2.5 -") == 57.5);
}

int main() {

    Stack stack;
    stack.push(2);
    stack.push(2.11);
    stack.push(2);
    stack.push(9.18);
    stack.print();
    cout << stack.peek() << endl;
    stack.pop();
    stack.pop();

    stack.print();
    cout << stack.peek() << endl;


    PostfixEval pe;

    case1(pe);
    case2(pe);
    case3(pe);

    cout << "correct" << endl;

    return 0;
}



