//
//  StudentMultiset.h
//  hw1
//
//  Created by desiree on 1/16/15.
//  Copyright (c) 2015 desiree. All rights reserved.
//

#ifndef __hw1__StudentMultiset__
#define __hw1__StudentMultiset__

#include "Multiset.h"



class StudentMultiset
{
public:
    StudentMultiset();       // Create an empty student multiset.
    
    bool add(ItemType id);
    // Add a student id to the StudentMultiset.  Return true if and only
    // if the id was actually added.
    
    int size() const;
    // Return the number of items in the StudentMultiset.  If an id was
    // added n times, it contributes n to the size.
    
    void print() const;
    // Print to cout every student id in the StudentMultiset one per line;
    // print as many lines for each id as it occurs in the StudentMultiset.
    
private:
    Multiset m_multiset;
    int m_size;
    
    
};

#endif /* defined(__hw1__StudentMultiset__) */
