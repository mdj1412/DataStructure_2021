//  Created by 민동준 on 2021/11/03.
//
//  FILE: evaluator.hpp
//  PROVIDES: A class for some functions that needed to use the calculator.
//            stack<Item> and template doubly linked list are used here,
//            all within the namespace main_mindongjun_2018603039.
//
//  PUBLIC MEMBER VARIABLE for the evaluator class:
//      Note: Defined Variables that are frequently used in the function.
//
//      const char DECIMAL
//          It is a const variable used to express decimal points, that is '.'.
//
//      const char LEFT_PARENTHESIS
//          This is the left parenthesis for expressing the order of operations, that is '('.
//
//      const char RIGHT_PARENTHESIS
//          This is the right parenthesis for expressing the order of operations, that is ')'.
//
//  PRIVATE MEMBER VARIABLE for the evaluator class:
//      stack<char> operations
//          It is used often many functions like convert_to_postfix, check_operations, add_operation_to_result, ...
//          It was often used to judge each character(type).
//
//      stack<double> numbers
//          It is used often many functions like evaluate_postfix, string_to_double, input_variable, evaluate_stack_tops, ...
//          It's used to save real numbers.
//
//  PUBLIC MEMBER FUNCTIONS for the evaluator class:
//      string read_expression()
//          Note: Function that reads in the expression from the standard input and
//                returns the string representing the user-provided expression.
//                The first letter of the variable should be composed of alphabet.!!!!!!!
//                ex) a, b12, b1c, dd5, ...
//
//          Precodition: The user input is a well-formed infix arithmetic expression
//          (i.e., no error checking required) where the following conditions are met:
//              (1) all operators(+,-,*,and /) are binary,
//              (2) operands are numbers or variables, and
//              (3) parentheses are allowed in the expression, but not every operation needs to be fully parenthesized
//          Postcondition: A string for infix expression has been returned (Example: “(1.03 * x + .4) / y” )
//          The operation equation received at irregular intervals (word spacing) is changed at regular intervals
//          (word spacing) and returned as a string.
//
//      string convert_to_postfix(string s)
//          Note: Function that converts s (an infix arithmetic expression) into a postfix notation
//                and returns the result string.
//
//          Precondition: s is a well-formed infix arithmetic expression (i.e., no error checking required)
//          where the following conditions are met:
//              (1) all operators(+,-,*,and /) are binary,
//              (2) operands are numbers or variables, and
//              (3) parentheses are allowed in the expression, but not every operation needs to be fully parenthesized
//          Postcondition: A string for postfix expression converted from s has been returned and the postfix
//          string should have at least one blank space between operands/operators. (For example, 10 2 * .4 + )
//
//      double evaluate_postfix(string s)
//          Note: Function that evaluates string s which is a postfix arithmetic expression and returns the result.
//                If a variable in the expression has to be evaluated and no value is known for it yet,
//                then the evaluation routine should ask the user to enter its value from the standard input.
//
//          Precondition: string s is a well-formed postfix arithmetic expression (i.e., no error checking required)
//          in which variables are allowed.
//          Postcondition: The evaluation result for s has been returned
//
//  PRIVATE MEMBER FUNCTIONS for the evaluator class:
//      bool is_operator(char c)
//          Note: Check whether it is an operator or not.
//
//      bool is_operand(char c)
//          Note: Check whether it is an operand or not.
//
//      bool is_number(char c)
//          Note: Check whether it is an number or not.
//
//      bool is_parenthesis(char c)
//          Note: Check whether it is an parenthesis or not.
//
//      void check_operations(string& result, char c, size_t idx)
//          Note: When we convert to infix into postfix, we check the stack operations because of operation order.
//
//          Postcondition: do -> added the top operation to result(string) and pop it.
//          while none of these three conditions are true:
//              (1) The stack becomes empty, or
//              (2) The next symbol on the stack is a left parenthesis, or
//              (3) The next symbol on the stack is an operation with lower precedence than the next input symbol.
//          push this symbol(char c) onto the stack(stack<char> operations).
//
//      void add_operation_to_result(string& result)
//          Note: This function stores operation, that is top of the stack<char> operations,
//          in the result(string), when we convert to infix into postfix
//
//          Precondition: The stack operations is not empty.
//          Postcondition: Push the top operations onto the result(string).
//
//      void string_to_double(string& s, size_t& idx)
//          Note: Using evaluate_postfix(string s), the function that converts the string stored
//          in the s(string) into numbers(double).
//
//          Postcondition: Changing the index and saving new number(double) in the stack<double> numbers.
//
//      void input_variable(string& s, size_t& idx)
//          Note: Using evaluate_postfix(string s), this function receives a real number.
//
//          Postcondition: Store the input real number in the stack<double> numbers.
//
//      void evaluate_stack_tops(char operation)
//          Note: Function used within evaluate_postfix when calculating in the middle.
//
//          Precondition: The operation contains + - * or /, and the numbers stack contains at least two numbers.
//          Postcondition: The top two numbers have been popped from the number stack and the operation has
//          operation(+ - * or /). The two numbers have been combined using the operation (with the second number
//          popped as the left operand). The result of the operation has then been pushed back onto the numbers stack.
//





#ifndef evaluator_hpp
#define evaluator_hpp
#include "stack.hpp"
#include <cctype>     // Provides isdigit, isalpha
#include <cstring>    // Provides strchr
#include <iostream>   // Provides cout
#include <string>     // Provides return type, push_back, pop_back


namespace main_mindongjun_2018603039
{
    class evaluator
    {
    public:
        const char DECIMAL = '.';
        const char LEFT_PARENTHESIS = '(';
        const char RIGHT_PARENTHESIS = ')';

        string read_expression();                       // infix string으로 정리해서 반환
        string convert_to_postfix(string s);            // infix -> postfix
        double evaluate_postfix(string s);              // postfix -> result value
    private:
        stack<char> operations;         // convert_to_postfix 관련 함수들에서 자주 사용되는 변수
        stack<double> numbers;          // evaluate_postfix 관련 함수들에서 자주 사용되는 변수
        bool is_operator(char c);
        bool is_operand(char c);
        bool is_number(char c);
        bool is_parenthesis(char c);
        
        // string evaluator::convert_to_postfix(string s) 에서 사용함
        void check_operations(string& result, char c, size_t idx);      // operations에 연산자를 쌓을 때 판단해주는 함수
        void add_operation_to_result(string& result);                   // stack에 쌓여있던 연산자(operations)를 result에 저장시키는 함수
        
        // double evaluator::evaluate_postfix(string s) 에서 사용함
        void string_to_double(string& s, size_t& idx);                  // 문자열(숫자)을 double로 바꿔주는 함수
        void input_variable(string& s, size_t& idx);                    // 변수에 숫자를 입력하는 함수
        void evaluate_stack_tops(char operation);                       // 연산을 해주는 함수
    };
}






#endif /* evaluator_hpp */
