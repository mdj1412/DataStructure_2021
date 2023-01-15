//  Created by 민동준 on 2021/10/05.
//
//  FILE: bag_dnode.cpp
//  CLASS implemented: bag


#include "bag_dnode.hpp"        // Provides bag's member functions and nonmember functions

using namespace main_mindongjun_2018603039;

int main(void){
    bag a, b, c, d, e, f, g, h, k, l;

    cout<<"\n==================== [ case 1 ] ====================\n"<<endl;
    cout<<"=====\tmember function insert() 실행 \t=====\n"<<endl;

    cout<<"[ a.insert(i) 실행 전 ] => [ 대입 : 0 2 4 6 8 10 ]\n"<<endl;
    cout<<"변수 a : ";
    a.show_contents();

    for (int i=10;i>=0;i--)
        a.insert(i--);
    cout<<"[ a.insert(i) 실행 후 ] => [ 대입 : 0 2 4 6 8 10 ]\n"<<endl;
    cout<<"변수 a : ";
    a.show_contents();

    cout<<"[ b.insert(i) 실행 전 ] => [ 대입 : 11 13 15 17 19 21 ]\n"<<endl;
    cout<<"변수 b : ";
    b.show_contents();

    for (int i=21;i>10;i--)
        b.insert(i--);
    cout<<"[ b.insert(i) 실행 후 ] => [ 대입 : 11 13 15 17 19 21 ]\n"<<endl;
    cout<<"변수 b : ";
    b.show_contents();

    cout<<"\n==================== [ case 2 ] ====================\n"<<endl;
    cout<<"=====\tnonmember function = 실행 \t=====\n"<<endl;

    cout<<"[ c = a + b 실행 전 ]\n"<<endl;
    cout<<"변수 a : ";
    a.show_contents();
    cout<<"변수 b : ";
    b.show_contents();
    cout<<"변수 c : ";
    c.show_contents();

    c = a + b;
    cout<<"[ c = a + b 실행 후 ]\n"<<endl;
    cout<<"변수 a : ";
    a.show_contents();
    cout<<"변수 b : ";
    b.show_contents();
    cout<<"변수 c : ";
    c.show_contents();

    cout<<"\n==================== [ case 3 ] ====================\n"<<endl;
    cout<<"=====\tmember function += 실행 \t=====\n"<<endl;

    for (int i=0;i<5;i++)
        d.insert(7);
    cout<<"[ a += d 실행 전 ]\n"<<endl;
    cout<<"변수 a : ";
    a.show_contents();
    cout<<"변수 d : ";
    d.show_contents();

    a += d;
    cout<<"[ a += d 실행 후 ]\n"<<endl;
    cout<<"변수 a : ";
    a.show_contents();
    cout<<"변수 d : ";
    d.show_contents();

    cout<<"\n==================== [ case 4 ] ====================\n"<<endl;
    cout<<"=====\tnonmember function == and != 실행 \t=====\n"<<endl;

    cout<<"변수 e : ";
    for (int i=0;i<12;i++)
        e.insert(i);
    e.show_contents();
    cout<<"변수 f : ";
    for (int i=10;i>=0;i--)
        f.insert(i);
    f.show_contents();

    cout<<"[ e == f 실행 ]\n"<<endl;
    cout<<(e == f)<<endl<<endl;
    cout<<"[ f == e 실행 ]\n"<<endl;
    cout<<(f == e)<<endl<<endl;
    cout<<"[ e != f 실행 ]\n"<<endl;
    cout<<(e != f)<<endl;

    cout<<"\n==================== [ case 5 ] ====================\n"<<endl;
    cout<<"===== member function erase_one() 실행 이후 비교 연산(== or !=) 실행 =====\n"<<endl;

    cout<<"[ e.erase_one(11) and e.erase_one(5) 실행 전 ]\n"<<endl;
    cout<<"변수 e : ";
    e.show_contents();
    e.erase_one(11);
    e.erase_one(5);
    cout<<"[ e.erase_one(11) and e.erase_one(5) 실행 후 ]\n"<<endl;
    cout<<"변수 e : ";
    e.show_contents();
    cout<<"[ f.erase_one(5) \"두 번\" 실행 전 ]\n"<<endl;
    cout<<"변수 f : ";
    f.show_contents();
    f.erase_one(5);
    f.erase_one(5);
    cout<<"[ f.erase_one(5) \"두 번\" 실행 후 ]\n"<<endl;
    cout<<"변수 f : ";
    f.show_contents();

    cout<<"[ 변수 e와 변수 f 비교 ]\n"<<endl;
    cout<<"변수 e : ";
    e.show_contents();
    cout<<"변수 f : ";
    f.show_contents();
    cout<<"[ e != f 실행 ]\n"<<endl;
    cout<<(e != f)<<endl<<endl;
    cout<<"[ f != e 실행 ]\n"<<endl;
    cout<<(f != e)<<endl<<endl;
    cout<<"[ e == f 실행 ]\n"<<endl;
    cout<<(e == f)<<endl;

    cout<<"\n==================== [ case 6 ] ====================\n"<<endl;
    cout<<"===== member function erase()와 erase_one() 실행 =====\n"<<endl;

    g.insert(1);
    for (int i=0;i<5;i++)
        g.insert(7);
    for (int i=0;i<2;i++)
        g.insert(1);
    for (int i=0;i<3;i++)
        g.insert(5);
    for (int i=0;i<2;i++)
        g.insert(1);

    cout<<"[ g.erase(1) 실행 전 ]\n"<<endl;
    cout<<"변수 g : ";
    g.show_contents();
    g.erase(1);
    cout<<"[ g.erase(1) 실행 후 ]\n"<<endl;
    cout<<"변수 g : ";
    g.show_contents();

    g.erase_one(5);
    cout<<"[ 이어서 g.erase_one(5) 실행 후 ]\n"<<endl;
    cout<<"변수 g : ";
    g.show_contents();

    g.erase(7);
    cout<<"[ 이어서 g.erase(7) 실행 후 ]\n"<<endl;
    cout<<"변수 g : ";
    g.show_contents();

    g.erase(5);
    cout<<"[ 이어서 g.erase(5) 실행 후 ]\n"<<endl;
    cout<<"변수 g : ";
    g.show_contents();

    cout<<"\n==================== [ case 7 ] ====================\n"<<endl;
    cout<<"=====\tconst member function grab() 실행 \t=====\n"<<endl;

    for (int i=30;i>0;i--)
        h.insert(i);
    cout<<"변수 h : "<<endl;
    h.show_contents();
    cout<<"[ h.grab() 함수 출력 ]\n"<<endl;
    for (int i=1;i<6;i++)
        cout<<"\t"<<i<<" 번째 : "<<h.grab()<<endl;

    cout<<"\n[ 변수 k에 함수 h.grab()가 실행해서 나온 값 저장 ]\n"<<endl;
    for (int i=0;i<5;i++)
        k.insert(h.grab());
    cout<<"변수 k : ";
    k.show_contents();

    cout<<"\n==================== [ case 8 ] ====================\n"<<endl;
    cout<<"===== member function = 실행 이후 비교 연산(== or !=) 실행 ======\n"<<endl;

    cout<<"[ l = a 실행 전 ]\n"<<endl;
    cout<<"변수 a : ";
    a.show_contents();
    cout<<"변수 l : ";
    l.show_contents();

    l = a;
    cout<<"[ l = a 실행 후 ]\n"<<endl;
    cout<<"변수 a : ";
    a.show_contents();
    cout<<"변수 l : ";
    l.show_contents();

    cout<<"[ l == a 실행 ]\n"<<endl;
    cout<<(l == a)<<endl;

    cout<<"\n[ l == l 실행 ]\n"<<endl;
    cout<<(l == l)<<endl;

    cout<<"\n[ l != l 실행 ]\n"<<endl;
    cout<<(l != l)<<endl;


    cout<<"\n==================== [ Finish! ] ====================\n"<<endl;

    return 0;
}
