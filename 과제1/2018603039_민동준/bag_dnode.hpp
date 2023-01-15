//  Created by 민동준 on 2021/09/28.
//
//  FILE: bag_dnode.hpp
//  TYPEDEFS for the bag class:
//      bag::size_type
//          size_type is the data type of any variable that keeps track of
//          how many items are in a bag.
//
//      bag::value_type
//          value_type is the data type of the items in the bag. 
//
//  PRIVATE MEMBER VARIABLE for the node class:
//      node* head_ptr
//          It points a first node in the bag.
//
//      node* tail_ptr
//          It points a last node in the bag.
//
//      size_type many_nodes
//          Number of nodes on the doubly linked lists
//
//  CONSTRUCTOR for the bag class:
//      bag()
//          Postcondition: The bag is empty. We set that the head_ptr is
//          null pointer and many_nodes is 0.
//
//      bag(const bag& source)
//          Precondition: source is the bag which is the const bag reference
//          since the original bag is unaltered.
//          Postcondition: Copy the many_nodes and the data in the source
//          by deep copy.
//
//  DESTRUCTOR for the bag class:
//      ~bag()
//          Postcondition: All nodes of the list(head_ptr) have been returned to the heap,
//          and the head_ptr is now NULL. Also, many_nodes is changed 0.
//
//  MEMBER FUNCTIONS for the bag class:
//      size_type erase(const value_type& target)
//          Postcondition: All copies of target have been removed from the bag.
//          The return value is the number of copies removed (which could be zero).
//
//      bool erase_one(const value_type& target)
//          Postcondition: If target was in the bag, then one copy of target has
//          been removed from the bag and then return true. Otherwise the bag is
//          unchanged and return false.
//
//      void insert(const value_type& entry)
//          Postcondition: A new copy of entry has been inserted into the bag.
//
//      void operator +=(const bag& addend)
//          Postcondition: Each item in addend has been added to this bag.
//          Addition we also change the many_nodes.
//
//      void operator =(const bag& source)
//          Precondition: source is the bag which is the const bag reference
//          since the original bag is unaltered.
//          Postcondition: Copy the many_nodes and the data in the source
//          by deep copy.
//
//      void sort()
//          Postcondition: The function actually changes the order of data
//          items stored in the bag to ascending order.
//
//  CONSTANT MEMBER FUNCTIONS for the bag class:
//      size_type size() const
//          Postcondition: Return value is the total number of items in the bag.
//
//      size_type count(const value_type& target) const
//          Postcondition: Return value is number of times target is in the bag.
//
//      value_type grab() const
//          Precondition: size() > 0.
//          Postcondition: The return value is a randomly selected item from the bag.
//
//      void show_contents() const
//          Postcondition: Printing all items in the bag.
//
//      value_type first_data() const
//          Postcondition: The return value is a item which is pointed the head_ptr.
//
//      value_type last_data() const
//          Postcondition: The return value is a item which is pointed the tail_ptr.
//
//  NONMEMBER FUNCTIONS for the bag class:
//      bag operator +(const bag& b1, const bag& b2)
//          Postcondition: The bag returned is the union of b1 and b2 which are
//          unaltered.
//
//      bool operator ==(const bag& b1, const bag& b2)
//          Postcondition: If they have some items and number of items, then the
//          return value is true or not false.
//
//      bool operator !=(const bag& b1, const bag& b2)
//          Postcondition: If they have some items and number of items, then the
//          return value is false or not true.


#ifndef bag_dnode_hpp
#define bag_dnode_hpp
#include "dnode.hpp"        // Provides node class


namespace main_mindongjun_2018603039
{
    class bag
    {
    public:
        // TYPEDEFS
        typedef std::size_t size_type;
        typedef node::value_type value_type;
        
        // CONSTRUCTOR and DESTRUCTOR
        bag();
        bag(const bag& source);     // copy constructor(deep copy)
        ~bag();
        
        // MEMBER FUNCTIONS
        size_type erase(const value_type& target);
        bool erase_one(const value_type& target);
        void insert(const value_type& entry);
        void operator +=(const bag& addend);
        void operator =(const bag& source);
        void sort();
        
        // CONSTANT MEMBER FUNCTIONS
        size_type size() const{ return many_nodes; }
        size_type count(const value_type& target) const;
        value_type grab() const;
        void show_contents() const;
        value_type first_data() const{ return head_ptr->data(); }
        value_type last_data() const{ return tail_ptr->data(); }
        
    private:
        node* head_ptr;             // List head pointer
        node* tail_ptr;             // List tail pointer
        size_type many_nodes;       // Number of nodes on the doubly linked lists
    };


    // NONMEMBER FUNCTIONS for the bag class
    bag operator +(const bag& b1, const bag& b2);
    bool operator ==(const bag& b1, const bag& b2);
    bool operator !=(const bag& b1, const bag& b2);
}


#endif /* bag_dnode_hpp */
