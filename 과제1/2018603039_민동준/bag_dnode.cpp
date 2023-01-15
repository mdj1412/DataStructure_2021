//  Created by 민동준 on 2021/09/28.
//
//  FILE: bag_dnode.cpp
//  CLASS implemented: bag
//  INVARIANT for the bag ADT:
//      1. The items in the bag are stored on a doubly linked list;
//      2. The head pointer of the list is stored in the member variable head_ptr;
//      3. The total number of items in the list is stored in the member variable
//         many_nodes.


#include "bag_dnode.hpp"        // Provides bag's member functions and nonmember functions

namespace main_mindongjun_2018603039
{
    // Library facilities used: cstdlib
    bag::bag(){
        head_ptr = NULL;
        tail_ptr = NULL;
        many_nodes = 0;
    }

    // Library facilities used: cstdlib, bag_dnode.hpp
    bag::bag(const bag& source){
        list_copy(source.head_ptr, head_ptr, tail_ptr);
        many_nodes = source.many_nodes;
    }

    // Library facilities used: bag_dnode.hpp
    bag::~bag(){
        list_clear(head_ptr);
        tail_ptr = NULL;
        many_nodes = 0;
    }

    // Library facilities used: cstdlib, bag_dnode.hpp
    bag::size_type bag::erase(const value_type& target){
        size_type answer = 0;
        node* target_ptr;
        
        target_ptr = list_search(head_ptr, target);
        while (target_ptr != NULL){
            erase_one(target);
            target_ptr = list_search(head_ptr, target);
            answer++;
        }
        return answer;
    }

    // Library facilities used: cstdlib, bag_dnode.hpp
    bool bag::erase_one(const value_type& target){
        node* target_ptr;
        
        target_ptr = list_search(head_ptr, target);
        
        // 다음과 같이 분류
        // 1. 원하는 target이 없는 경우 -> return false
        // 2. many_nodes == 1 일 때
        // 3. target_ptr == head_ptr
        // 4. target_ptr == tail_ptr
        // 5. 그 외
        
        if (target_ptr == NULL)
            return false;
        
        if (many_nodes == 1){
            list_head_remove(head_ptr);
            tail_ptr = NULL;
        }
        else if (target_ptr == head_ptr){
            list_head_remove(head_ptr);
        }
        else if (target_ptr == tail_ptr){
            list_tail_remove(tail_ptr);
        }
        else {
            list_remove(target_ptr->back());
        }
        
        many_nodes--;
        return true;
    }

    // Library facilities used: bag_dnode.hpp
    void bag::insert(const value_type& entry){
        list_head_insert(head_ptr, entry);
        if (tail_ptr == NULL)
            tail_ptr = head_ptr;
        many_nodes++;
    }

    // Library facilities used: bag_dnode.hpp
    void bag::operator +=(const bag& addend){
        node* copy_head_ptr;
        node* copy_tail_ptr;
        
        if (addend.many_nodes > 0){
            list_copy(addend.head_ptr, copy_head_ptr, copy_tail_ptr);
            head_ptr->set_back(copy_tail_ptr);
            copy_tail_ptr->set_fore(head_ptr);
            head_ptr = copy_head_ptr;
            many_nodes += addend.many_nodes;
        }
    }

    // Library facilities used: bag_dnode.hpp
    void bag::operator =(const bag& source){
        if (this == &source)
            return;
        list_clear(head_ptr);
        tail_ptr = NULL;
        list_copy(source.head_ptr, head_ptr, tail_ptr);
        many_nodes = source.many_nodes;
    }

    // Library facilities used: cstdlib, bag_dnode.hpp
    bag::size_type bag::count(const value_type& target) const{
        size_type answer;
        const node* cursor;
        
        answer = 0;
        cursor = list_search(head_ptr, target);
        while (cursor != NULL){
            answer++;
            cursor = cursor->fore();
            cursor = list_search(cursor, target);
        }
        return answer;
    }

    // Library facilities used: cassert, cstdlib, bag_dnode.hpp
    bag::value_type bag::grab() const{
        size_type i;
        const node* cursor;
        
        assert(size() > 0);
        i = (rand() % size()) + 1;
        
        // 분류 기준
        // 1. rand() 값이 앞 쪽에 위치할 때
        // 2. rand() 값이 뒤 쪽에 위치할 때
        
        if (i < many_nodes/2){
//            cout<<"list_head_locate"<<endl;
            cursor = list_head_locate(head_ptr, i);
        }
        else{
//            cout<<"list_tail_locate"<<endl;
            cursor = list_tail_locate(tail_ptr, many_nodes - i + 1);
        }
        
        return cursor->data();
    }

    bag operator +(const bag& b1, const bag& b2){
        bag answer;
        
        answer += b1;
        answer += b2;
        return answer;
    }

    bool operator ==(const bag& b1, const bag& b2){
        bag::value_type target;
        bag compare_bag;
        
        // 다음과 같이 분류
        // 1. 같은 객체를 비교할 때 -> return true
        // 2. 두 객체의 size가 다를 때 -> return false
        // 3. 그 외에 나머지
        //      a) target의 갯수를 비교해서 같은지 확인
        //      b) 같을 경우 전부 다 erase
        //      c) 다음 target 비교 ... 반복
        
        if (&b1 == &b2)
            return true;
        if (b1.size() != b2.size())
            return false;
        
        compare_bag = b1;
        while (compare_bag.size() != 0){
            target = compare_bag.first_data();
            if (compare_bag.count(target) != b2.count(target))
                return false;
            compare_bag.erase(target);
        }
        return true;
    }

    bool operator !=(const bag& b1, const bag& b2){
        return !(b1 == b2);
    }

    void bag::sort(){
        node* new_head_ptr;
        node* cursor;
        value_type max;
        size_type count;
        
        // 다음과 같이 분류
        // 1. 가장 큰 값 찾기
        // 2. 가장 큰 값의 보유 수를 찾아 새로운 node에 삽입
        // 3. 반복 ...
        
        new_head_ptr = NULL;
        while (many_nodes != 0){
            max = head_ptr->data();
            for (cursor=head_ptr->fore();cursor!=NULL;cursor=cursor->fore())
                if (max < cursor->data())
                    max = cursor->data();
            count = erase(max);
            while (count--)
                list_head_insert(new_head_ptr, max);
        }
        many_nodes = list_length(new_head_ptr);
        head_ptr = new_head_ptr;
    }


    // Library facilities used: iostream, cstdlib, bag_dnode.hpp
    void bag::show_contents() const{
        const node* cursor;
        
        for (cursor=head_ptr;cursor!=NULL;cursor=cursor->fore())
            cout<<cursor->data()<<'\t';
        cout<<endl<<endl;
    }
}


