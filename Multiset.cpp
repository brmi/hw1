//
//  Multiset.cpp
//  hw1
//
//  Created by desiree on 1/14/15.
//  Copyright (c) 2015 desiree. All rights reserved.
//

#include "Multiset.h"
#include <iostream>
#include <string>
using namespace std;


//Your implementation of the Multiset class must be such that the compiler-generated destructor, copy constructor, and assignment operator do the right things.

Multiset::Multiset():m_size(0)    // Create an empty multiset.
{
    //do i put anything in here?? since i already constructed that struct and stuff??
}


// Return true if the multiset is empty, otherwise false.
//what defines an empty multiset?
//well if there are no items in the mutiset, then size should be 0
bool Multiset::empty() const
{
        if(m_size==0)
            return true;
    
    return false;
}

int Multiset::size() const
{
    return m_size;
    
}

// Return the number of distinct items in the multiset.  For example,
// the uniqueSize of a multiset containing "cumin", "cumin", "cumin",
// "turmeric" is 2.


int Multiset::uniqueSize() const
{
    
    //want to check whatever is at item type and see if it matches previous array.
    if(empty()==true)
    {
        return 0;
    }

    int notUnique=0;
    int numUnique=1;
    int j=0;
    for (int i=1; i<m_size; i++)
    {
        while(j<m_size)
        {
            if(m_arr[i].m_item==m_arr[j].m_item && &m_arr[i].m_item!=&m_arr[j].m_item)
            {
                
                j=0;
                notUnique=1;
                
            }
            j++;
            if(notUnique==1)
            {
                notUnique=0;
                break;
            }
            if(j==m_size) //something wrong with this line
            {
                numUnique++;
                j=0;
                break;
                
            }
        }
        
    }
    return numUnique;
}

// Insert value into the multiset.  Return true if the value was
// actually inserted.  Return false if the value was not inserted
// (perhaps because the multiset has a fixed capacity and is full).
//THIS IS WRONG
bool Multiset::insert(const ItemType& value)
{
    if(m_size==DEFAULT_MAX_ITEMS)
        return false;
    
    for(int i=0; i<uniqueSize(); i++)
    {
        if(m_arr[i].m_item == value)
        {
            m_arr[i].m_count++;
            m_size++;
            return true;
            
        }else if (m_arr[i].m_item!=value && i==uniqueSize()-1)
        {
            m_arr[uniqueSize()].m_item=value;
            m_arr[uniqueSize()].m_count++;
            m_size++;
            return true;
        }
    }
    
    if(uniqueSize()!=0)
    {
    m_arr[uniqueSize()-1].m_count++; //por que
    m_arr[uniqueSize()-1].m_item=value;
    
    m_size++;
    }
    else
    {
        m_arr[uniqueSize()].m_count++;
        m_arr[uniqueSize()].m_item=value;
        m_size++;
    }
    
//    if(m_size>1)
//    {
//    m_arr[uniqueSize()-1].m_item=value;
//    m_arr[uniqueSize()-1].m_count=1;
//    m_size++;
//        }else
//        {
//            m_arr[uniqueSize()].m_item=value;
//            m_arr[uniqueSize()].m_count=1;
//        m_size++;
//    }
    return true;
}

// Remove one instance of value from the multiset if present.
// Return the number of instances removed, which will be 1 or 0.
int Multiset::erase(const ItemType& value)
{
    int remove=0;
    for(int i=0; i<m_size; i++)
    {
        if(m_arr[i].m_item == value)
        {
            remove=1;
            m_arr[i].m_count--;
            for (int j=0; j<m_size; j++)
            m_arr[j]=m_arr[j+1];
            return remove;
            
        }
    }
    return remove;
}

// Remove all instances of value from the multiset if present.
// Return the number of instances removed.
int Multiset::eraseAll(const ItemType& value)
{
    int remove=0;
    for(int i=0; i<m_size; i++)
    {
        if(m_arr[i].m_item == value)
        {
            remove++;
            for (int j=0; j<m_size; j++)
                m_arr[i]=m_arr[i+1];
        }
    }
    return remove;
}

// Return true if the value is in the multiset, otherwise false.
bool Multiset::contains(const ItemType& value) const
{
    for(int i=0; i<m_size; i++)
    {
        if(m_arr[i].m_item == value)
        {
            return true;
        }
    }
    return false;
}


// Return the number of instances of value in the multiset.
int Multiset::count(const ItemType& value) const
{
    
    for(int i=0; i<uniqueSize(); i++)
    {
        if(m_arr[i].m_item == value)
        {
            return m_arr[i].m_count;
        }
    }
    return 0;
}


// If 0 <= i < uniqueSize(),
// copy into value an item in the
// multiset and return the number of instances of that item in
// the multiset.  Otherwise, leave value unchanged and return 0.
// (See below for details about this function.)

int Multiset::get(int i, ItemType& value)const
{
    
    if(i>=0 && i< uniqueSize())
    {
    value=m_arr[i].m_item;
        return count(value);
    }
    else
        return 0;
    
    
    //If nothing is inserted into or erased from the multiset in the interim, then calling get repeatedly with the same value for the first parameter each time must copy the same value into the second parameter each time and return the same value each time, so that this code is fine: maybe will have to implement this somehow lol
}

// Exchange the contents of this multiset with the other one.
void Multiset::swap(Multiset& other)
{
    //wanna create a temp to hold the stuff in ms1 ((or first multiset))
   //need size of larger of the two so we can loop that many times or someshit like that, wait maybe not
    
    
    
    
    Multiset temp = *this;
    
    *this = other;
    other = temp;
    
    //now wanna empty this
    
//    for (int i=0; i<this->uniqueSize(); i++)
//    {
//        this->m_arr[i].m_item= other.m_arr[i].m_item;
//        this->m_arr[i].m_count= other.m_arr[i].m_count;
//        
//    }
//    
//    for(int j=0; j<temp.uniqueSize(); j++)
//    {
//        other.m_arr[j].m_item= temp.m_arr[j].m_item;
//        other.m_arr[j].m_count= temp.m_arr[j].m_count;
//
//    }
    
}











