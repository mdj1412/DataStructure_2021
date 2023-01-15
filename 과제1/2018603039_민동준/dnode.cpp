//  Created by 민동준 on 2021/09/28.
//
//  FILE: dnode.cpp
//  IMPLEMENTS: The functions of the node class and the doubly linked list toolkit.
//  INVARIANT for the node class:
//  The data of a node is stored in data_field, link_fore and link_back.

#include "dnode.hpp"

namespace main_mindongjun_2018603039
{
    // Library facilities used: cstdlib
    std::size_t list_length(const node* head_ptr){
        const node* cursor;
        size_t answer;
        
        answer = 0;
        for (cursor=head_ptr;cursor!=NULL;cursor=cursor->fore())
            answer++;
        return answer;
    }

    // Library facilities used: cstdlib
    node* list_search(node* head_ptr, const node::value_type& target){
        node* cursor;
        
        for (cursor=head_ptr;cursor!=NULL;cursor=cursor->fore())
            if (cursor->data() == target)
                break;
        return cursor;
    }

    // Library facilities used: cstdlib
    const node* list_search(const node* head_ptr, const node::value_type& target){
        const node* cursor;
        
        for (cursor=head_ptr;cursor!=NULL;cursor=cursor->fore())
            if (cursor->data() == target)
                break;
        return cursor;
    }

    // Library facilities used: cassert, cstdlib
    node* list_head_locate(node* head_ptr, std::size_t position){
        node* cursor;
        size_t i;
        
        assert(position > 0);
        cursor = head_ptr;
        for (i=1;(i<position)&&(cursor!=NULL);i++)
            cursor=cursor->fore();
        return cursor;
    }

    // Library facilities used: cassert, cstdlib
    const node* list_head_locate(const node* head_ptr, std::size_t position){
        const node* cursor;
        size_t i;
        
        assert(position > 0);
        cursor = head_ptr;
        for (i=1;(i<position)&&(cursor!=NULL);i++)
            cursor=cursor->fore();
        return cursor;
    }

    // Library facilities used: cassert, cstdlib
    node* list_tail_locate(node* tail_ptr, std::size_t position){
        node* cursor;
        size_t i;
        
        assert(position > 0);
        cursor = tail_ptr;
        for (i=1;(i<position)&&(cursor!=NULL);i++)
            cursor=cursor->back();
        return cursor;
    }

    // Library facilities used: cassert, cstdlib
    const node* list_tail_locate(const node* tail_ptr, std::size_t position){
        const node* cursor;
        size_t i;
        
        assert(position > 0);
        cursor = tail_ptr;
        for (i=1;(i<position)&&(cursor!=NULL);i++)
            cursor=cursor->back();
        return cursor;
    }

    void list_insert(node* previous_ptr, const node::value_type& entry){
        node* insert_ptr;
        
        insert_ptr = new node(entry, previous_ptr->fore(), previous_ptr);
        insert_ptr->fore()->set_back(insert_ptr);
        previous_ptr->set_fore(insert_ptr);
    }

    // Library facilities used: cstdlib
    void list_head_insert(node*& head_ptr, const node::value_type& entry){
        head_ptr = new node(entry, head_ptr);
        head_ptr->fore()->set_back(head_ptr);
    }

    // Library facilities used: cstdlib
    void list_tail_insert(node*& tail_ptr, const node::value_type& entry){
        tail_ptr = new node(entry, NULL, tail_ptr);
        tail_ptr->back()->set_fore(tail_ptr);
    }

    // Library facilities used: cstdlib
    void list_head_remove(node*& head_ptr){
        node* remove_ptr;
        
        remove_ptr = head_ptr;
        head_ptr = head_ptr->fore();
        head_ptr->set_back(NULL);
        delete remove_ptr;
    }
    
    // Library facilities used: cstdlib
    void list_tail_remove(node*& tail_ptr){
        node* remove_ptr;
        
        remove_ptr = tail_ptr;
        tail_ptr = tail_ptr->back();
        tail_ptr->set_fore(NULL);
        delete remove_ptr;
    }

    void list_remove(node* previous_ptr){
        node* remove_ptr;
        
        remove_ptr = previous_ptr->fore();
        remove_ptr->fore()->set_back(previous_ptr);
        previous_ptr->set_fore(remove_ptr->fore());
        delete remove_ptr;
    }

    // Library facilities used: cstdlib
    void list_clear(node*& head_ptr){
        while (head_ptr != NULL)
            list_head_remove(head_ptr);
    }

    // Library facilities used: cstdlib
    void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr){
        head_ptr = NULL;
        tail_ptr = NULL;
        
        if (source_ptr == NULL)
            return;
        list_head_insert(head_ptr, source_ptr->data());
        tail_ptr = head_ptr;
        
        source_ptr = source_ptr->fore();
        while (source_ptr != NULL){
            list_tail_insert(tail_ptr, source_ptr->data());
            source_ptr = source_ptr->fore();
        }
    }
}
