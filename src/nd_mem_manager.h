#ifndef ND_MEM_MANAGER_H
#define ND_MEM_MANAGER_H

#pragma once
#include <iostream>
#include <vector>
using namespace std;

void* operator new(size_t size);
void operator delete(void* p);

struct mem_block
{
    mem_block()
    {
        m_position = 0;
        m_size = 0;
        m_free = true;
    }
    mem_block(size_t start, size_t size)
    {
        m_position = start;
        m_size = size;
        m_free = false;
    }

    mem_block devide(size_t need_size)
    {
        if (need_size > m_size)
        {
            throw 1;
        }
        else
        {
            size_t divdv_pos = m_position + need_size;
            mem_block mod_block(divdv_pos, m_size - need_size);
            m_size = need_size;
            return mod_block;
        }
    }
    void* position()
    {
        return (void*)(m_position);
    }
    size_t m_size;
    bool m_free;
private:
    size_t m_position;
};

void nd_mgr_exit();
size_t m_mem_limit(200*1024*1024);
size_t m_free_pos_start(0);
size_t m_memory(0);
mem_block* m_mem_state(0);
size_t m_mem_state_end(0);
size_t m_mem_state_length(0);
unsigned long long m_merge_counter(0);


#endif