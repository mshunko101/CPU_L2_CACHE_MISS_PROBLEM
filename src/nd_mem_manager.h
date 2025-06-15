#ifndef ND_MEM_MANAGER_H
#define ND_MEM_MANAGER_H

#pragma once
#include <iostream>
using namespace std;


void * operator new(size_t size)
{
    cout << "New operator overloading " << endl;
    void * p = malloc(size);
    return p;
}

void operator delete(void * p)
{
    cout << "Delete operator overloading " << endl;
    free(p);
}

class nd_mem_manager
{
public:
    nd_mem_manager();
    ~nd_mem_manager();

private:

};

#endif