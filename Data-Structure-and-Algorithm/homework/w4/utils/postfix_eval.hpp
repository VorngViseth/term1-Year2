#include "../utils/stack.hpp"
#include <string>
#include <cmath>
#include <cctype>

#ifndef POSFIX
#define POSFIX

class PostfixEval{
    private:
        bool isOperator(char c){
            return (
                c == '+' ||
                c == '-' ||
                c == '*' ||
                c == '/' ||
                c == '^'
            );
        }

        float calculate(float op1, float op2, char op){
            if (op == '+') return op1 + op2;
            else if (op == '-') return op1 - op2;
            else if (op == '*') return op1 * op2;
            else if (op == '/') return op1 / op2;
            else if (op == '^') return pow(op1, op2);
            else return 0;
        }

    public:

        float evaluate(string s){
            // complete the logic here
            Stack stack;
            float number;
            int i = 0;
             
            while(i < s.size()) {
                
                if(s[i] == ' ') {
                    i++;
                    continue;
                }

                if (isdigit(s[i]) || s[i] == '.') {

                int j = i;
                while( j < s.size() && (isdigit(s[j]) || s[j] == '.')) j++; 

                number = stof(s.substr(i, j-i));
                stack.push(number);

                i = j;

                }else if (i < s.size() && isOperator(s[i])) {
                    float op2 = stack.peek();
                    stack.pop();                    
                    float op1 = stack.peek();
                    stack.pop();
                    float result = calculate(op1, op2, s[i]);
                    stack.push(result);
                    i++ ;

                }
            }

            return stack.peek();
        }
};

#endif  