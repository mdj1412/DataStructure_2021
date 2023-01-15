//  Created by 민동준 on 2021/11/17.
//
//  FILE: set.h (part of the namespace main_mindongjun_2018603039)
//  TEMPLATE CLASS PROVIDED: set<Item>
//    (a container template class for a set of items)
//
//  TYPEDEFS for the set<Item> class:
//      set<Item>::value_type
//          set<Item>::value_type is the data type of the items in the set.
//
//  CONSTRUCTOR for the set<Item> class:
//      set()
//          Postcondition: The set is empty.
//
//  DESTRUCTOR for the stack<Item> template class:
//      ~set()
//          Postcondtion: All member variables in sets have been returned to the heap
//          by using clear function.
//
//  MODIFICATION PUBLIC MEMBER FUNCTIONS for the set<Item> class:
//      void clear()
//          Postcondition: The set is empty.
//
//      bool insert(const Item& entry)
//          Postcondition: If an equal entry was already in the set, the set is
//          unchanged and the return value is false. Otherwise, entry was added
//          to the set and the return value is true.
//
//      bool erase(const Item& target)
//          Postcondition: If target was in the set, then it has been removed from
//          the set and the return value is 1. Otherwise the set is unchanged and the
//          return value is zero.
//
//  CONSTANT PUBLIC MEMBER FUNCTIONS for the Set<Item> class:
//      size_t count(const Item& target) const
//          Postcondition: Returns the number of items equal to the target
//          (either 0 or 1 for a set).
//
//      bool empty() const
//          Postcondition: Returns true if the set is empty; otherwise returns false.
//
//      void show_contents(int indent = 6) const
//          Postcondition: Input the distance between printing the items and default
//          value(argument) is 6.
//          Note: This is a temporary public function for use by the programmer
//          who implements the set class. The function prints a representation of the set’s B-tree.
//          The entries of the root node are printed with an indentation given by the parameter,
//          and each subtree has an extra four spaces of indentation.
//
//  PRIVATE MEMBER CONSTANTS for the Set<Item> class:
//      static const std::size_t MINIMUM
//      static const std::size_t MAXIMUM
//          It is important to use b-tree which it have insert, erase, or count items.
//          The maximum number of entries in a node is twice the value of MININUM.
//
//  PRIVATE MEMBER VARIABLES for the Set<Item> class:
//      std::size_t data_count
//          It stores the number of data.
//
//      Item data[MAXIMUM+1]
//          The entries of each B-tree node are stored in a partially filled array,
//          sorted from the smallest entry (at index 0) to the largest entry
//          (at the final used index)
//
//      std::size_t child_count
//          It stores the number of child.
//
//      set *subset[MAXIMUM+2]
//          It is an array that stores sets of children. The number of subtrees
//          below a nonleaf node is always one more than the number of entries in the node.
//
//  PRIVATE HELPER MEMBER FUNCTIONS for the Set<Item> class:
//      bool is_leaf() const
//          Check if there is a child node(set).
//
//      bool loose_insert(const Item& entry)
//          It may not fit the rules, but it's a function to insert.
//
//      bool loose_erase(const Item& target)
//          It may not fit the rules, but it's a function to erase.
//
//      void remove_biggest(Item& removed_entry)
//          When a erase function is executed, it is executed when there is an item
//          to be deleted from the b-tree. The largest value among the items stored
//          in the left child node is stored in the removed_entry.
//
//      void fix_excess(std::size_t i)
//          If the number of items exceeds the MAXIMUM, change it to set the rule.
//
//      void fix_shortage(std::size_t i)
//          If the number of items less than the MINIMUM, change it to set the rule.
//
//      void print_help(int indent) const
//          It is a recursive function that helps when a show_contents(int indent = 6) const
//          function is executed.
//



#ifndef set_hpp
#define set_hpp

#include <stdio.h>
#include <cstdlib>   // Provides size_t

namespace main_mindongjun_2018603039
{
    template <class Item>
    class set
    {
    public:
        // TYPEDEFS
        typedef Item value_type;
        
        // CONSTRUCTORS and DESTRUCTOR
        set();
        ~set() { clear( ); }
        
        // MODIFICATION MEMBER FUNCTIONS
        void clear();
        bool insert(const Item& entry);
        bool erase(const Item& target);  // 원서에서
        
        // CONSTANT MEMBER FUNCTIONS
        std::size_t count(const Item& target) const;
        bool empty() const { return (data_count == 0); }
        
        // SUGGESTED FUNCTION FOR DEBUGGING
        void show_contents(int indent = 6) const;

    private:
        // MEMBER CONSTANTS
        static const std::size_t MINIMUM = 1; // 200
        static const std::size_t MAXIMUM = 2 * MINIMUM;
        
        // MEMBER VARIABLES
        std::size_t data_count;
        Item data[MAXIMUM+1];
        std::size_t child_count;
        set *subset[MAXIMUM+2];
        
        // HELPER MEMBER FUNCTIONS
        bool is_leaf() const { return (child_count == 0); }
        bool loose_insert(const Item& entry);
        bool loose_erase(const Item& target);
        void remove_biggest(Item& removed_entry);
        void fix_excess(std::size_t i);
        void fix_shortage(std::size_t i);
        void print_help(int indent) const;
        // NOTE: The implementor may want to have additional helper functions
    };
}

#include "set.template" // Include the implementation.


#endif /* set_hpp */
