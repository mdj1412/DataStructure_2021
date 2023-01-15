//  Created by 민동준 on 2021/11/03.
//
//  FILE: stack.template
//  INVARIANT for the template stack class:
//      1. The items in the stack are stored in a doubly linked list, with the top of the
//         stack stored at the head node, down to the bottom of the stack at the final node.
//      2. The member variable top_ptr is the head pointer of the doubly linked list.

#include <cassert>          // Provides assert
#include "dnode.hpp"        // Node template class
#include "stack.hpp"

namespace main_mindongjun_2018603039
{
    template <class Item>
    stack<Item>::stack(const stack<Item>& source)
    // Library facilities used: node2.h
    {
        node<Item> *tail_ptr; // Needed for argument of list_copy

        list_copy(source.top_ptr, top_ptr, tail_ptr);
    }

    template <class Item>
    void stack<Item>::push(const Item& entry)
    // Library facilities used: node2.h
    {
        list_head_insert(top_ptr, entry);
    }

    template <class Item>
    void stack<Item>::pop()
    // Library facilities used: cassert, node2.h
    {
        assert(!empty());
        list_head_remove(top_ptr);
    }

    template <class Item>
    void stack<Item>::operator =(const stack<Item>& source)
    // Library facilities used: node2.h
    {
        node<Item> *tail_ptr; // Needed for argument of list_copy

        if (this == &source) // Handle self-assignment
            return;

        list_clear(top_ptr);
        list_copy(source.top_ptr, top_ptr, tail_ptr);
    }

    template <class Item>
    Item stack<Item>::top() const
    // Library facilities used: cassert
    {
        assert(!empty());
        return top_ptr->data();
    }

//    template class stack<char>;
//    template class stack<double>;
}
