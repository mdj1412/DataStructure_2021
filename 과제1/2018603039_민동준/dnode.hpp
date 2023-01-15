//  Created by 민동준 on 2021/09/28.
//
//  FILE: dnode.hpp
//  PROVIDES:
//      A class for a node in a doubly linked list, and list manipulation
//      functions, all within the namespace main_mindongjun_2018603039
//
//  TYPEDEF for the node class:
//      Each node of the list contains a piece of data and two pointers that
//      one pointing to the next node and one pointing to the previous node.
//      The type of the data is defined as node::value_type in a
//      typedef statement.
//
//  PRIVATE MEMBER VARIABLE for the node class:
//      value_type data_field
//          The item is saved in data_field.
//
//      node* link_fore
//          link_fore points next node.
//
//      node* link_back
//          link_back points back node.
//
//  CONSTRUCTOR for the node class:
//      node(const value_type& init_data = value_type(), node* init_fore = NULL, node* init_back = NULL)
//          Postcondition: The node contains the specified data, link_fore and link_back.
//          NOTE: The default value for the init_data is obtained from the default
//          constructor of the value_type, providing a default value of
//          zero. The init_fore and init_back have a default value of NULL.
//
//  NOTE:
//      Some of the functions have a return value which is a pointer to a node.
//      Each of these  functions comes in two versions: a non-const version (where
//      the return value is node*) and a const version (where the return value
//      is const node*).
//
//  MEMBER FUNCTIONS for the node class:
//      void set_data(const value_type& new_data)
//          Postcondition: The node now contains the specified new_data.
//
//      void set_fore(node* new_fore)
//          Postcondition: The node now contains the specified new_fore.
//
//      void set_back(node* new_back)
//          Postcondition: The node now contains the specified new_back.
//          NOTE: If this keyword is null pointer, then it have to return
//          because of the error-> Thread 1: EXC_BAD_ACCESS (code=1, address=0x10)
//
//      value_type data() const
//          Postcondition: The return value is the data from this node.
//
//      const node* fore() const <----- const version
//      node* fore() <----------------- non-const version
//          Postcondition: The return value is the link_fore from this node.
//
//      const node* back() const <----- const version
//      node* back() <----------------- non-const version
//          Postcondition: The return value is the link_back from this node.
//
//  FUNCTIONS in the doubly linked list toolkit:
//      std::size_t list_length(const node* head_ptr)
//          Precondition: head_ptr is the head pointer of a doubly linked list.
//          Postcondition: The value is returned the number of nodes in the doubly
//          linked list.
//
//      node* list_search(node* head_ptr, const node::value_type& target)
//      const node* list_search(const node* head_ptr, const node::value_type& target)
//          Precondition: head_ptr is the head pointer of a doubly linked list.
//          Postcondition: The pointer returned points to the first node containing
//          the specified target in its data member. If there is no such node, the
//          null pointer is returned.
//
//  NOTE:
//      Separating to list_head_locate and list_tail_locate because bag class have
//      head pointer and tail pointer. If position closed to tail pointer, then
//      it is easy to access the node pointer when we use list_tail_locate better
//      than list_head_locate.
//
//      node* list_head_locate(node* head_ptr, std::size_t position)
//      const node* list_head_locate(const node* head_ptr, std::size_t position)
//          Precondition: head_ptr is the head pointer of a doubly linked list, and position > 0.
//          Postcondition: The pointer returned points to the node at the specified
//          position in the list. (The head node is position 1, the next node is
//          position 2, and so on). If there is no such position, then the null
//          pointer is returned.
//
//      node* list_tail_locate(node* tail_ptr, std::size_t position)
//      const node* list_tail_locate(const node* tail_ptr, std::size_t position)
//          Precondition: tail_ptr is the tail pointer of a doubly linked list, and position > 0.
//          Postcondition: The pointer returned points to the node at the specified
//          position in the list. (The tail node is position 1, the next node is
//          position 2, and so on). If there is no such position, then the null
//          pointer is returned.
//
//      void list_insert(node* previous_ptr, const node::value_type& entry)
//          Precondition: previous_ptr points to a node in a doubly linked list.
//          Postcondition: A new node containing the given entry has been added
//          after the node that previous_ptr points to. We must set(or change) link_fore
//          and link_back.
//
//      void list_head_insert(node*& head_ptr, const node::value_type& entry)
//          Precondition: head_ptr is the head pointer of a doubly linked list.
//          Postcondition: A new node containing the given entry has been added at
//          the head of the doubly linked list; head_ptr now points to the head of the new,
//          longer doubly linked list. The link_back of past head_ptr is changed to
//          new head_ptr.
//
//      void list_tail_insert(node*& tail_ptr, const node::value_type& entry)
//          Precondition: tail_ptr is the tail pointer of a doubly linked list.
//          Postcondition: A new node containing the given entry has been added at
//          the tail of the doubly linked list; tail_ptr now points to the tail of the new,
//          longer doubly linked list. The link_fore of past tail_ptr is changed to
//          new tail_ptr.
//
//      void list_head_remove(node*& head_ptr)
//          Precondition: head_ptr is the head pointer of a doubly linked list, with at
//          least one node.
//          Postcondition: The head node has been removed and returned to the heap;
//          head_ptr is changed link_fore and link_back of new head_ptr sets null pointer.
//
//      void list_tail_remove(node*& tail_ptr)
//          Precondition: tail_ptr is the tail pointer of a doubly linked list, with at
//          least one node.
//          Postcondition: The tail node has been removed and returned to the heap;
//          tail_ptr is changed link_back and link_fore of new tail_ptr sets null pointer.
//
//      void list_remove(node* previous_ptr)
//          Precondition: previous_ptr points to a node in a doubly linked list, and this
//          is not the tail node of the list.
//          Postcondition: The node after previous_ptr has been removed from the doubly
//          linked list. We have to set the link_back and link_fore of some node pointer
//
//      void list_clear(node*& head_ptr)
//          Precondition: head_ptr is the head pointer of a doubly linked list.
//          Postcondition: All nodes of the list have been returned to the heap,
//          and the head_ptr is now NULL.
//
//      void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr)
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
    class node
    {
    public:
        // TYPEDEF
        typedef double value_type;
        
        // CONSTRUCTOR
        node(const value_type& init_data = value_type(), node* init_fore = NULL, node* init_back = NULL){
            data_field = init_data;
            link_fore = init_fore;
            link_back = init_back;
        }
        
        // Member functions to set the data, link_fore and link_back fields:
        void set_data(const value_type& new_data){ data_field = new_data; }
        void set_fore(node* new_fore){
            if (this == NULL)
                return;
            link_fore = new_fore;
        }
        void set_back(node* new_back){
            if (this == NULL)           // 처음 시작할 때 (node에 한 개 있을 때) 문제되어서 첨가
                return;
            link_back = new_back;
        }
        
        // Const member function to retrieve the current data:
        value_type data() const{ return data_field; }
        
        // Two slightly different member functions to retrieve each current link_fore and link_back:
        const node* fore() const{ return link_fore; }
        node* fore(){ return link_fore; }
        const node* back() const{ return link_back; }
        node* back(){ return link_back; }
        
    private:
        value_type data_field;
        node* link_fore;
        node* link_back;
    };


    // FUNCTIONS for the doubly linked list toolkit
    std::size_t list_length(const node* head_ptr);

    node* list_search(node* head_ptr, const node::value_type& target);
    const node* list_search(const node* head_ptr, const node::value_type& target);
    
    node* list_head_locate(node* head_ptr, std::size_t position);
    const node* list_head_locate(const node* head_ptr, std::size_t position);

    node* list_tail_locate(node* tail_ptr, std::size_t position);
    const node* list_tail_locate(const node* tail_ptr, std::size_t position);

    void list_insert(node* previous_ptr, const node::value_type& entry);
    void list_head_insert(node*& head_ptr, const node::value_type& entry);
    void list_tail_insert(node*& tail_ptr, const node::value_type& entry);

    void list_head_remove(node*& head_ptr);
    void list_tail_remove(node*& tail_ptr);
    void list_remove(node* previous_ptr);
    void list_clear(node*& head_ptr);

    void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr);
}



#endif /* dnode_hpp */
