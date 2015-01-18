//
//  newMultiset.h
//  hw1
//
//  Created by desiree on 1/17/15.
//  Copyright (c) 2015 desiree. All rights reserved.
//

#ifndef __hw1__newMultiset__
#define __hw1__newMultiset__

#include <iostream>

typedef unsigned long ItemType;

const int DEFAULT_MAX_ITEMS = 200;

class Multiset
{
public:
    
    Multiset(int m_max);
    
    ~Multiset();
    
    Multiset(const Multiset& copycon);
    
    bool empty() const;
    
    int size() const;
   
    
    int uniqueSize() const;
    
    bool insert(const ItemType& value);
  
    
    int erase(const ItemType& value);

    
    int eraseAll(const ItemType& value);
  
    
    bool contains(const ItemType& value) const;

    
    int count(const ItemType& value) const;
    
    
    int get(int i, ItemType& value)const;

    
    void swap(Multiset& other);
  
    
    
    
    
private:
    
    
    struct multArray
    {
        ItemType m_item;    //just pretend this is the name of the dude visiting
        int m_count;    //this is the number of times that person or item has visited the site
        multArray()
        {
            m_count=0;
            //m_item=""; // can u do this??, what should i initialize as, or is this even needed?
        }
    };
    
    
    int m_size; // the num of items
    
    int m_max; //the dyamic size of the array
    ItemType* m_arr;
};


#endif /* defined(__hw1__newMultiset__) */
