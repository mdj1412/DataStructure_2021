//  Created by 민동준 on 2021/11/03.
//
//  FILE: stack.hpp (part of the namespace main_mindongjun_2018603039)
//  TEMPLATE CLASS PROVIDED:
//      stack<Item> (a stack of items)
//      The template parameter, Item, is the data type of the items in the stack,
//      also defined as stack<Item>::value_type.
//      It may be any of the C++ built-in types (int, char, etc.), or a class
//      with a default constructor, a copy constructor, and an assignment
//      operator.
//
//  TYPEDEF for the template node class:
//      stack<Item>::size_type
//          size_type is the data type of any variable that keeps track of
//          how many items are in a stack.
//
//      stack<Item>::value_type
//          value_type is the data type of the items in the stack.
//
//  CONSTRUCTOR for the stack<Item> template class:
//      stack()
//          Postcondition: The stack has been initialized as an empty stack.
//
//      stack(const stack& source)
//          Postcondition: source is the stack which is the const stack reference
//          since the original stack is unaltered.
//          Postcondition: the data in the source by deep copy.
//
//  DESTRUCTOR for the stack<Item> template class:
//      ~stack()
//          Postcondtion: All nodes of the doubly list have been returned to the heap,
//          and the top_ptr is now NULL.
//
//  MODIFICATION MEMBER FUNCTIONS for the stack<Item> class:
//      void push(const Item& entry)
//          Precondition: size() < CAPACITY.
//          Postcondition: A new copy of entry has been pushed onto the stack.
//
//      void pop()
//          Precondition: size() > 0.
//          Postcondition: The top item of the stack has been removed.
//
//      void operator =(const stack& source)
//          Precondition: source is the stack which is the const stack reference
//          since the original stack is unaltered.
//          Postcondition: the data in the source by deep copy.
//
//  CONSTANT MEMBER FUNCTIONS for the stack<Item> class:
//      bool empty() const
//          Postcondition: Return value is true if the stack is empty.
//
//      size_type size() const
//          Postcondition: Return value is the total number of items in the stack.
//
//      Item top() const
//          Precondition: size() > 0.
//          Postcondition: The return value is the top item of the stack (but the
//          stack is unchanged). This differs slightly from the STL stack (where
//          the top function returns a reference to the item on top of the stack).
//
//      VALUE SEMANTICS for the stack<Item> class:
//          Assignments and the copy constructor may be used with stack<Item> objects.
//
//  DYNAMIC MEMORY USAGE by the stack<Item> template class:
//      If there is insufficient dynamic memory, then the following functions throw bad_alloc:
//      the copy constructor, push, and the assignment operator.

#ifndef stack_hpp
#define stack_hpp
#include <cstdlib>      // Provides NULL and size_t
#include <cassert>      // Provides assert
#include "dnode.hpp"

namespace main_mindongjun_2018603039
{
    template <class Item>
    class stack
    {
    public:
        // TYPEDEFS
        typedef std::size_t size_type;
        typedef Item value_type;
        
        // CONSTRUCTORS and DESTRUCTOR
        stack() { top_ptr = NULL; }
        stack(const stack& source);
        ~stack() { list_clear(top_ptr); }
        
        // MODIFICATION MEMBER FUNCTIONS
        void push(const Item& entry);
        void pop();
        void operator =(const stack& source);
        
        // CONSTANT MEMBER FUNCTIONS
        size_type size() const { return list_length(top_ptr); }
        bool empty() const { return (top_ptr == NULL); }
        Item top() const;
        
    private:
        node<Item> *top_ptr;  // Points to top of stack
    };
}


#include "stack.template"

#endif /* stack_hpp */
