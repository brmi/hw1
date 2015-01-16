//
//  main.cpp
//  hw1
//
//  Created by desiree on 1/14/15.
//  Copyright (c) 2015 desiree. All rights reserved.
//

#include "Multiset.h"
#include <iostream>
#include <cassert>
using namespace std;

int main()
{
    Multiset ms;
    ms.insert("fennel");
    ms.insert("fennel");
    ms.insert("fenugreek"); //wrong
    ms.insert("fennel");
    for (int k = 0; k < ms.uniqueSize(); k++)
    {
        string x;
        int n = ms.get(k, x);
        cout << x << " occurs " << n << " times." << endl;
    }

    Multiset mr;
    mr.insert("cinnamon");
    mr.insert("galangal");
    mr.insert("cinnamon");
    string s1;
    int n1 = mr.get(1, s1);
    assert((s1 == "cinnamon"  &&  n1 == 2)  ||  (s1 == "galangal"  &&  n1 == 1));
    string s2;
    int n2 = mr.get(1, s2);
    assert(s2 == s1  &&  n2 == n1);
    
    cout<<"pass";
}

