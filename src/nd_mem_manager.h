#ifndef ND_MEM_MANAGER_H
#define ND_MEM_MANAGER_H

#pragma once
#include <iostream>
using namespace std;

void* operator new(size_t size);
void operator delete(void* p);

void nd_mgr_exit();
size_t m_memory;
size_t m_memory_end(0);
const size_t m_memory_limit_bytes(200 * 1024 * 1024);
float mark_free = 16.126;
float mark_portion = 126.16;

#endif