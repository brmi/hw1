//
//  StudentMultiset.cpp
//  hw1
//
//  Created by desiree on 1/16/15.
//  Copyright (c) 2015 desiree. All rights reserved.
//

#include "StudentMultiset.h"
using namespace std;

// Create an empty student multiset.
StudentMultiset::StudentMultiset()
{
    //default constructor of class type should construct itself by using default constructor of multiset
}


// Add a student id to the StudentMultiset.  Return true if and only
// if the id was actually added.
bool StudentMultiset::add(ItemType id)
{
    if(m_multiset.insert(id))
    {
        return true;
    }
    
    return false;
}


// Return the number of items in the StudentMultiset.  If an id was
// added n times, it contributes n to the size.
int StudentMultiset::size() const
{
    return m_multiset.size();
}


// Print to cout every student id in the StudentMultiset one per line;
// print as many lines for each id as it occurs in the StudentMultiset.
void StudentMultiset::print() const
{
    for (int i=0; i< m_multiset.uniqueSize(); i++)
    {
        unsigned long x;
        m_multiset.get(i, x);
        cout<<x<<endl;
        
    }
}
