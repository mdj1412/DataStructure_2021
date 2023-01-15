//  Created by 민동준 on 2021/09/28.
//
//  FILE: dnode.hpp
//  TEMPLATE CLASS PROVIDES:
//      A template class for a node in a doubly linked list, and list manipulation
//      template functions, all within the namespace main_mindongjun_2018603039
//
//  TYPEDEF for the template node class:
//      stack<Item>::value_type
//          value_type is the data type of the items in the node.
//
//  PRIVATE MEMBER VARIABLE for the template node class:
//      Note: Each node of the list contains a piece of data and two pointers that
//          one pointing to the next node and one pointing to the previous node.
//
//      Item data_field
//          The item is saved in data_field.
//
//      node<Item>* link_fore
//          link_fore points next node.
//
//      node<Item>* link_back
//          link_back points back node.
//
//  CONSTRUCTOR for the template node class:
//      node(const Item& init_data = Item(), node<Item>* init_fore = NULL, node<Item>* init_back = NULL)
//          Postcondition: The node contains the specified data, link_fore and link_back.
//          NOTE: The default value for the init_data is obtained from the default
//          constructor of the value_type, providing a default value of
//          zero. The init_fore and init_back have a default value of NULL.
//
//  NOTE:
//      Some of the functions have a return value which is a pointer to a node.
//      Each of these  functions comes in two versions: a non-const version (where
//      the return value is node<Item>*) and a const version (where the return value
//      is const node<Item>*).
//
//  MEMBER FUNCTIONS for the template node class:
//      void set_data(const Item& new_data)
//          Postcondition: The node now contains the specified new_data.
//
//      void set_fore(node<Item>* new_fore)
//          Postcondition: The node now contains the specified new_fore.
//
//      void set_back(node<Item>* new_back)
//          Postcondition: The node now contains the specified new_back.
//          NOTE: If this keyword is null pointer, then it have to return
//          because of the error-> Thread 1: EXC_BAD_ACCESS (code=1, address=0x10)
//
//      value_type data() const
//          Postcondition: The return value is the data from this node.
//
//      const node<Item>* fore() const <----- const version
//      node<Item>* fore() <----------------- non-const version
//          Postcondition: The return value is the link_fore from this node.
//
//      const node<Item>* back() const <----- const version
//      node<Item>* back() <----------------- non-const version
//          Postcondition: The return value is the link_back from this node.
//
//  FUNCTIONS in the doubly linked list toolkit:
//      std::size_t list_length(const node<Item>* head_ptr)
//          Precondition: head_ptr is the head pointer of a doubly linked list.
//          Postcondition: The value is returned the number of nodes in the doubly
//          linked list.
//
//      node<Item>* list_search(node<Item>* head_ptr, const Item& target)
//      const node<Item>* list_search(const node<Item>* head_ptr, const Item& target)
//          Precondition: head_ptr is the head pointer of a doubly linked list.
//          Postcondition: The pointer returned points to the first node containing
//          the specified target in its data member. If there is no such node, the
//          null pointer is returned.
//
//      node<Item>* list_head_locate(node<Item>* head_ptr, std::size_t position)
//      const node<Item>* list_head_locate(const node<Item>* head_ptr, std::size_t position)
//          Precondition: head_ptr is the head pointer of a doubly linked list, and position > 0.
//          Postcondition: The pointer returned points to the node at the specified
//          position in the list. (The head node is position 1, the next node is
//          position 2, and so on). If there is no such position, then the null
//          pointer is returned.
//
//      node<Item>* list_tail_locate(node<Item>* tail_ptr, std::size_t position)
//      const node<Item>* list_tail_locate(const node<Item>* tail_ptr, std::size_t position)
//          Precondition: tail_ptr is the tail pointer of a doubly linked list, and position > 0.
//          Postcondition: The pointer returned points to the node at the specified
//          position in the list. (The tail node is position 1, the next node is
//          position 2, and so on). If there is no such position, then the null
//          pointer is returned.
//
//      void list_insert(node<Item>* previous_ptr, const Item& entry)
//          Precondition: previous_ptr points to a node in a doubly linked list.
//          Postcondition: A new node containing the given entry has been added
//          after the node that previous_ptr points to. We must set(or change) link_fore
//          and link_back.
//
//      void list_head_insert(node<Item>*& head_ptr, const node<Item>::value_type& entry)
//          Precondition: head_ptr is the head pointer of a doubly linked list.
//          Postcondition: A new node containing the given entry has been added at
//          the head of the doubly linked list; head_ptr now points to the head of the new,
//          longer doubly linked list. The link_back of past head_ptr is changed to
//          new head_ptr.
//
//      void list_tail_insert(node<Item>*& tail_ptr, const Item& entry)
//          Precondition: tail_ptr is the tail pointer of a doubly linked list.
//          Postcondition: A new node containing the given entry has been added at
//          the tail of the doubly linked list; tail_ptr now points to the tail of the new,
//          longer doubly linked list. The link_fore of past tail_ptr is changed to
//          new tail_ptr.
//
//      void list_head_remove(node<Item>*& head_ptr)
//          Precondition: head_ptr is the head pointer of a doubly linked list, with at
//          least one node.
//          Postcondition: The head node has been removed and returned to the heap;
//          head_ptr is changed link_fore and link_back of new head_ptr sets null pointer.
//
//      void list_tail_remove(node<Item>*& tail_ptr)
//          Precondition: tail_ptr is the tail pointer of a doubly linked list, with at
//          least one node.
//          Postcondition: The tail node has been removed and returned to the heap;
//          tail_ptr is changed link_back and link_fore of new tail_ptr sets null pointer.
//
//      void list_remove(node<Item>* previous_ptr)
//          Precondition: previous_ptr points to a node in a doubly linked list, and this
//          is not the tail node of the list.
//          Postcondition: The node after previous_ptr has been removed from the doubly
//          linked list. We have to set the link_back and link_fore of some node pointer
//
//      void list_clear(node<Item>*& head_ptr)
//          Precondition: head_ptr is the head pointer of a doubly linked list.
//          Postcondition: All nodes of the list have been returned to the heap,
//          and the head_ptr is now NULL.
//
//      void list_copy(const node<Item>* source_ptr, node<Item>*& head_ptr, node<Item>*& tail_ptr)
//          Precondition: source_ptr is the head pointer of a doubly linked list.
//          Postcondition: head_ptr and tail_ptr are the head and tail pointers for
//          a new doubly linked list that contains the same items as the list pointed
//          to by source_ptr.
//

#ifndef dnode_hpp
#define dnode_hpp
#include <cstdlib>              // Provides NULL and size_t
#include <cassert>              // Provides assert
#include <iostream>
using namespace std;

namespace main_mindongjun_2018603039
{
    template <class Item>
    class node
    {
    public:
        // TYPEDEF
        typedef Item value_type;
        
        // CONSTRUCTOR
        node(const Item& init_data = Item(), node<Item>* init_fore = NULL, node<Item>* init_back = NULL) {
            data_field = init_data;
            link_fore = init_fore;
            link_back = init_back;
        }
        
        // Member functions to set the data, link_fore and link_back fields:
        void set_data(const Item& new_data) { data_field = new_data; }
        void set_fore(node<Item>* new_fore) {
            if (this == NULL)
                return;
            link_fore = new_fore;
        }
        void set_back(node<Item>* new_back) {
            if (this == NULL)           // 처음 시작할 때 (node에 한 개 있을 때) 문제되어서 첨가
                return;
            link_back = new_back;
        }
        
        // Const member function to retrieve the current data:
        Item data() const { return data_field; }
        
        // Two slightly different member functions to retrieve each current link_fore and link_back:
        const node<Item>* fore() const { return link_fore; }
        node<Item>* fore() { return link_fore; }
        const node<Item>* back() const { return link_back; }
        node<Item>* back() { return link_back; }
        
    private:
        Item data_field;
        node<Item>* link_fore;
        node<Item>* link_back;
    };


    // FUNCTIONS for the doubly linked list toolkit
    template <class Item>
    std::size_t list_length(const node<Item>* head_ptr);

    template <class Item>
    node<Item>* list_search(node<Item>* head_ptr, const Item& target);
    template <class Item>
    const node<Item>* list_search(const node<Item>* head_ptr, const Item& target);
    
    template <class Item>
    node<Item>* list_head_locate(node<Item>* head_ptr, std::size_t position);
    template <class Item>
    const node<Item>* list_head_locate(const node<Item>* head_ptr, std::size_t position);

    template <class Item>
    node<Item>* list_tail_locate(node<Item>* tail_ptr, std::size_t position);
    template <class Item>
    const node<Item>* list_tail_locate(const node<Item>* tail_ptr, std::size_t position);

    template <class Item>
    void list_insert(node<Item>* previous_ptr, const Item& entry);
    template <class Item>
    void list_head_insert(node<Item>*& head_ptr, const Item& entry);
    template <class Item>
    void list_tail_insert(node<Item>*& tail_ptr, const Item& entry);

    template <class Item>
    void list_head_remove(node<Item>*& head_ptr);
    template <class Item>
    void list_tail_remove(node<Item>*& tail_ptr);
    template <class Item>
    void list_remove(node<Item>* previous_ptr);
    template <class Item>
    void list_clear(node<Item>*& head_ptr);

    template <class Item>
    void list_copy(const node<Item>* source_ptr, node<Item>*& head_ptr, node<Item>*& tail_ptr);
}

#include "dnode.template"

#endif /* dnode_hpp */
