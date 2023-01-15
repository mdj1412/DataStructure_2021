//  Created by 민동준 on 2021/11/04.
//
//  FILE: main_program.cpp
//  Basic calculator program that needs to interact with the user to read in and
//  evaluate infix expressions using those three public member functions defined in evaluator class and
//  should show the intermediate results by writing the input expression
//  (in infix notation), its postfix expression, and the evaluation result to the standard output.
//  And it should be able to repeat the same process until the user wants to quit.
//


#include "evaluator.hpp"
#include <iostream>
#include <cstdlib>    // Provides EXIT_SUCCESS

using namespace std;
using namespace main_mindongjun_2018603039;

int main(void)
{
    evaluator a;
    int go, num = 1;
    cout << "입력 : infix" << endl;
    cout << "출력 : 중간 계산(infix & postfix) & 마지막 결과" << endl << endl;
    
    while (true)
    {
        string infix, postfix;
        double result;
        
        cout << "프로그램을 실행하시겠습니까?(1.시작 2.종료) : ";
        cin >> go;
        cin.ignore();       // buffer 비우기
        if (go == 2) { break; }
        cout << "\n====================================================" << endl;
        cout << "[ " << num << " 번 째 실 행 ]" << endl;
        
        infix = a.read_expression();
        cout << "read_expression\t\t: " << infix << endl;
        postfix = a.convert_to_postfix(infix);
        cout << "convert_to_postfix\t: " << postfix << endl;
        cout << endl;
        
        result = a.evaluate_postfix(postfix);
        cout << endl << num++ << "번째 계산 결과 : " << result << endl;
        cout << "\n====================================================" << endl;
    }
    cout << "\n\n1번 예시 실제값 : " << 2.0+(3.0)*2.0-(5.0) << endl;
    cout << "2번 예시 실제값 : " << 1.0 + 7 + (1.03 * 1.0 + .4) / 1 << endl;
    cout << "3번 예시 실제값 : " << -9 + 7 + (1.03 * -9 + .4) / -9 << endl;
    //    string ex2 = "k      +7 +     (1.03  *   x11+.4) /yx1";
    //    string ex3 = "p12*(7 -(xy1+ (y-w))/4) +2 *z/ (w + s * 8)";
    cout << "4번 예시 실제값 : " << 1.0 * (7.0 - (1.0 + (1.0 - 1)) / 4.0) + 2.0 * 1.0 / (1.0 + 1.0 * 8.0) << endl;
    cout << "5번 예시 실제값 : " << (-9) * (7.0 - ((-9) + ((-9) - (-9))) / 4.0) + 2.0 * (-9) / ((-9) + (-9) * 8.0) << endl << endl;
    cout << "프로그램을 종료합니다." << endl;
    return EXIT_SUCCESS;
}



