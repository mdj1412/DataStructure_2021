//  Created by 민동준 on 2021/11/03.
//
//  FILE: evaluator.cpp
//
//  Basic calculator program that takes an arithmetic expression evaluator
//  (using a stack that stores data in a doubly linked list)
//  expression as input, convert to postfix and evaluates the arithmetic expression.
//  The purpose is to illustrate a fundamental use of stacks.
//

#include "evaluator.hpp"


namespace main_mindongjun_2018603039
{
    // infix string으로 반환
    string evaluator::read_expression()
    {
        string ins, result;
        size_t idx, length;
        
        cout << "infix를 입력하시오." << endl << "=> ";
        getline(cin, ins);      // == getline(cin, ins, '\n');
        idx = 0;
        length = ins.length();
        
        while (idx < length)
        {
            // < 경우의 수 >
            // 1. 숫자 또는 변수(알파벳으로 시작)일 경우
            // 2. 연산자일 경우
            // 3. 왼쪽 또는 오른쪽 괄호일 경우
            
            if (is_operand(ins[idx]))
            {
                // 변수 이름 : x0, xy1, x12y   => 모두 고려!!!
                do
                {
                    result.push_back(ins[idx++]);
                } while ((is_operand(ins[idx])) || (!is_operator(ins[idx]) && (strchr(" ", ins[idx]) == NULL)));
                continue;
            }
            
            else if (is_operator(ins[idx]))
            {
                result.push_back(' ');
                result.push_back(ins[idx]);
                result.push_back(' ');
            }
            
            else if (is_parenthesis(ins[idx]))
                result.push_back(ins[idx]);
            
            idx++;
        }
        return result;
    }


    // infix -> postfix
    string evaluator::convert_to_postfix(string s)
    {
        string result;
        size_t idx, length;
        
        idx = 0;
        length = s.length();
        while (idx < length)
        {
            // < 경우의 수 >
            // 1. 왼쪽 괄호가 올 경우
            // 2. 숫자나 변수(알파벳으로 시작)가 올 경우
            // 3. 연산자가 올 경우
            //    a) +* 일 경우
            //    b) ++ ** *+ 일 경우
            // 4. 오른쪽 괄호가 올 경우
            
            if (s[idx] == LEFT_PARENTHESIS)
                operations.push(LEFT_PARENTHESIS);
            
            else if (is_operand(s[idx]))
            {
                // 변수 이름 : x0, xy1, x12y   => 모두 고려!!!
                do
                {
                    result.push_back(s[idx++]);
                } while (is_operand(s[idx]));
                result.push_back(' ');
                continue;
            }
            
            else if (is_operator(s[idx]))
                check_operations(result, s[idx], idx);
            
            else if (s[idx] == RIGHT_PARENTHESIS)
            {
                while (operations.top() != LEFT_PARENTHESIS) { add_operation_to_result(result); }
                operations.pop();
            }
            
            idx++;
        }
        // stack operations에 남은거 전부 받기
        while (!operations.empty()) { add_operation_to_result(result); }
        return result;
    }


    // postfix -> result
    double evaluator::evaluate_postfix(string s)
    {
        string number;
        size_t idx, length;

        idx = 0;
        length = s.length();
        
        while (idx < length)
        {
            // < 경우의 수 >
            // 1. 숫자일 경우
            // 2. 기호일 경우
            // 3. 변수(알파벳으로 시작)의 경우
            
            if (is_number(s[idx]))
            {
                string_to_double(s, idx);
                continue;
            }
            
            else if (is_operator(s[idx]))
                evaluate_stack_tops(s[idx]);
            
            else if (isalpha(s[idx]))
            {
                // 변수 이름 : x0, xy1, x12y   => 모두 고려!!!
                input_variable(s, idx);
                continue;
            }

            idx++;
        }
        
        double answer = numbers.top();
        numbers.pop();
        return answer;
    }








    bool evaluator::is_operator(char c) { return (strchr("+-*/", c) != NULL); }
    bool evaluator::is_operand(char c) { return (is_number(c) || isalpha(c)); }
    bool evaluator::is_number(char c) { return (isdigit(c) || (c == DECIMAL)); }
    bool evaluator::is_parenthesis(char c) { return ((c == LEFT_PARENTHESIS) || (c == RIGHT_PARENTHESIS)); }


    // operations에 연산자를 쌓을 때 판단해주는 함수
    void evaluator::check_operations(string& result, char c, size_t idx)
    {
        if (!operations.empty() && (operations.top() != LEFT_PARENTHESIS))
            if ((strchr("+-", operations.top()) == NULL) || (strchr("*/", c) == NULL))
            {
                add_operation_to_result(result);
                if (!operations.empty() && (operations.top() != LEFT_PARENTHESIS))
                    if ((strchr("+-", operations.top()) == NULL) || (strchr("*/", c) == NULL)) { add_operation_to_result(result); }
            }
        operations.push(c);
    }



    // stack에 쌓여있던 연산자(operations)를 result에 저장시키는 함수
    void evaluator::add_operation_to_result(string& result)
    {
        result.push_back(operations.top());
        result.push_back(' ');
        operations.pop();
    }


    // 문자열(숫자)을 double로 바꿔주는 함수
    void evaluator::string_to_double(string& s, size_t& idx)
    {
        string number;
        
        do
        {
            number.push_back(s[idx++]);
        } while (is_number(s[idx]));
        numbers.push(stod(number));
    }




    // 변수에 숫자를 입력하는 함수
    void evaluator::input_variable(string& s, size_t& idx)
    {
        string number;
        double variable;
        
        do
        {
            number.push_back(s[idx++]);
        } while (s[idx] != ' ');
        
        cout << "변수 " << number << " 입력 : ";
        cin >> variable;
        numbers.push(variable);
    }




    // double evaluator::evaluate_postfix(string s) 에서 사용함
    // 연산을 해주는 함수
    void evaluator::evaluate_stack_tops(char operation)
    // Library facilities used: stack
    {
        double operand1, operand2;

        operand2 = numbers.top();
        numbers.pop();
        operand1 = numbers.top();
        numbers.pop();
        
        switch (operation)
        {
            case '+': numbers.push(operand1 + operand2);
                      break;
            case '-': numbers.push(operand1 - operand2);
                      break;
            case '*': numbers.push(operand1 * operand2);
                      break;
            case '/': numbers.push(operand1 / operand2);
                      break;
        }
    }


}


