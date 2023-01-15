//  Created by 민동준 on 2021/12/15.
//
//  FILE: main_program.cpp
//  B-tree program that needs to interact with the user to read in and
//  use those three public member functions(insert, erase, count) defined in set class,
//  and show the b-tree results by show_contents.
//  And it should be able to repeat the same process until the user wants to quit.
//


#include "set.hpp"
#include <iostream>
#include <string>
using namespace std;
using namespace main_mindongjun_2018603039;


int main(void)
{
    set<int> btree;
    string interacting_user;
    int value;
    
    cout << "다음 4가지 중 하나를 입력하시오."  << endl;
    cout << "------------------------------------------------------------------------"  << endl;
    cout << "insert x – inserts x to the current set(B-tree)"  << endl;
    cout << "erase x – erase x from the current set (B-tree)"  << endl;
    cout << "count x - counts the number of x in the current set (B-tree); returns either 1 or 0"  << endl;
    cout << "quit – quit"  << endl;
    cout << "------------------------------------------------------------------------"  << endl;

    while (true)
    {
        cout << "======================================================================="  << endl;

        cout << "입력 : ";
        cin >> interacting_user;

//        cout << "case ? " << interacting_user << endl << "value ? " << value << endl;


        if (!interacting_user.compare("quit"))
        {
            cout << "프로그램을 종료합니다." << endl;
            break;
        }
        
        cin >> value;

        // insert 하는 경우
        if (!interacting_user.compare(0, 6, "insert"))
        {
            cout << "[ insert 함수 실행 전 ]" << endl;
            btree.show_contents(6);
            cout << "[ insert 함수 실행 후 ]" << endl;
            btree.insert(value);
            btree.show_contents(6);
        }

        // erase 하는 경우
        else if (!interacting_user.compare(0, 5, "erase"))
        {
            cout << "[ erase 함수 실행 전 ]" << endl;
            btree.show_contents(6);
            cout << "[ erase 함수 실행 후 ]" << endl;
            btree.erase(value);
            btree.show_contents(6);
        }

        // count 하는 경우
        else if (!interacting_user.compare(0, 5, "count"))
        {
            cout << value << "의 갯수 : " << btree.count(value) << endl;

        }

        // 세 가지 경우가 아닐 때
        else { cout << "잘못 입력하셨습니다." << endl; }
        cin.ignore();
    }
    
    
    
    
    
    
    
    
    /* minimum = 1 일 때 */
//    for (int i=0;i<60;i+=10) {
//        btree.insert(i);
//    }
//    btree.show_contents();
//    btree.erase(30);
//    btree.show_contents();
//    btree.erase(40);
//    btree.show_contents();
//    btree.erase(50);
//    btree.show_contents();
//    btree.erase(10);
//    btree.show_contents();
    
    
    /* minimum = 1 일 때 */
//    for (int i=0;i<100;i+=10) {
//        btree.insert(i);
//    }
//    btree.show_contents();
//    btree.erase(50);
//    btree.show_contents();
//    btree.erase(70);
//    btree.show_contents();
//    btree.erase(60);
//    btree.show_contents();
//    btree.erase(80);
//    btree.show_contents();
//    btree.erase(10);
//    btree.show_contents();
//    btree.erase(30);
//    btree.show_contents();
//    btree.erase(20);
//    btree.show_contents();
//    btree.erase(40);
//    btree.show_contents();
//    btree.erase(0);
//    btree.show_contents();
//    btree.erase(90);
//    btree.show_contents();
    
    
    
    
    /* minimum = 2 일 때 */
//    for (int i=5;i<14;)
//    {
//        btree.insert(i);
//        i+=2;
//    }
//    btree.show_contents(6);
//
//
//    for (int i=1;i<4;i++) { btree.insert(i); }
//    btree.show_contents(6);
//
//    for (int i=100;i<103;i++) { btree.insert(i); }
//    btree.show_contents(6);
//
//    for (int i=103;i<108;i++) { btree.insert(i); }
//    btree.show_contents(6);
//
//    btree.insert(108);
//    btree.show_contents(6);
//
//
//
//    // case 4, 3
//    btree.erase(102);
//    btree.show_contents(6);
//
//
//    // case 2
//    btree.erase(11);
//    btree.show_contents(6);
//
//    // case 1
//    btree.erase(107);
//    btree.show_contents(6);
//
//    // case 4
//    btree.erase(1);
//    btree.show_contents(6);
//
//
//    btree.erase(103);
//    btree.show_contents();
//
//    cout << "enter" << endl;
//
//
//    for (int i=30;i<32;i++) { btree.insert(i); }
//    btree.show_contents(6);
//
//    btree.insert(32);
//    btree.show_contents(6);
//
//    for (int i=33;i<36;i++) { btree.insert(i); }
//    btree.show_contents(3);
//
//    for (int i=36;i<39;i++) { btree.insert(i); }
//    btree.show_contents(6);
//
//    for (int i=39;i<42;i++) { btree.insert(i); }
//    btree.show_contents(6);
//
//    for (int i=42;i<45;i++) { btree.insert(i); }
//    btree.show_contents(6);
    
    
    return 0;
}

