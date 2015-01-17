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


Multiset::Multiset():m_size(0)
{
}



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

int Multiset::uniqueSize() const
{
    
    //want to check whatever is at item type and see if it matches previous array.
    if(empty()==true)
    {
        return 0;
    }
    
    int numUnique=0;

    for (int i=0; i<m_size; i++)
    {
        if (m_arr[i].m_count!=0)
        {
            numUnique++;
        }
    }
    
    return numUnique;
}

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
    m_arr[uniqueSize()-1].m_count++;
    m_arr[uniqueSize()-1].m_item=value;
    
    m_size++;
    }
    else
    {
        m_arr[uniqueSize()].m_item=value;
        m_arr[uniqueSize()].m_count++;
        m_size++;
    }
    
    return true;
}


int Multiset::erase(const ItemType& value)
{
    int remove=0;
    for(int i=0; i<m_size; i++)
    {
        if(m_arr[i].m_item == value)
        {
            remove=1;
            m_arr[i].m_count--;
            m_size--;
            for (int j=0; j<m_size; j++)
            m_arr[j]=m_arr[j+1];
            return remove;
            
        }
    }
    return remove;
}


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

int Multiset::get(int i, ItemType& value)const
{
    
    if(i>=0 && i< uniqueSize())
    {
    value=m_arr[i].m_item;
        return count(value);
    }
    else
        return 0;

}


void Multiset::swap(Multiset& other)
{
    Multiset temp = *this;
    
    *this = other;
    other = temp;
}











