//
//  Multiset.h
//  hw1
//
//  Created by desiree on 1/14/15.
//  Copyright (c) 2015 desiree. All rights reserved.
//

#ifndef hw1_Multiset_h
#define hw1_Multiset_h

#include <iostream>
typedef unsigned long ItemType; //have unsigned long when you turn in the project

const int DEFAULT_MAX_ITEMS = 200;

class Multiset
{
public:

    Multiset();    // Create an empty multiset.
    
    bool empty() const;  // Return true if the multiset is empty, otherwise false.
    
    int size() const;
    // Return the number of items in the multiset.  For example, the size
    // of a multiset containing "cumin", "cumin", "cumin", "turmeric" is 4.
    
    int uniqueSize() const;
    // Return the number of distinct items in the multiset.  For example,
    // the uniqueSize of a multiset containing "cumin", "cumin", "cumin",
    // "turmeric" is 2.
    
    bool insert(const ItemType& value);
    // Insert value into the multiset.  Return true if the value was
    // actually inserted.  Return false if the value was not inserted
    // (perhaps because the multiset has a fixed capacity and is full).
    
    int erase(const ItemType& value);
    // Remove one instance of value from the multiset if present.
    // Return the number of instances removed, which will be 1 or 0.
    
    int eraseAll(const ItemType& value);
    // Remove all instances of value from the multiset if present.
    // Return the number of instances removed.
    
    bool contains(const ItemType& value) const;
    // Return true if the value is in the multiset, otherwise false.
    
    int count(const ItemType& value) const;
    // Return the number of instances of value in the multiset.
    
    int get(int i, ItemType& value)const; 
    // If 0 <= i < uniqueSize(), copy into value an item in the
    // multiset and return the number of instances of that item in
    // the multiset.  Otherwise, leave value unchanged and return 0.
    // (See below for details about this function.)
    
    void swap(Multiset& other);
    // Exchange the contents of this multiset with the other one.
    
   

    
private:


    struct multArray 
    {
        ItemType m_item; //just pretend this is the name of the dude visiting
        int m_count; //this is the number of times that person or item has visited the site
        multArray()
        {
            m_count=0;
           //m_item=""; // can u do this??, what should i initialize as, or is this even needed?
        }
    };
    
    
    int m_size; // the num of items
    
    multArray m_arr[DEFAULT_MAX_ITEMS];
    
};

#endif
