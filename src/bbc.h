#pragma once

#include "tree.h"
#include <vector>

using namespace std;

 
#define VIRTUAL 
#define OVERRIDE 
#define THIS this


class bbc 
{
public:
	bbc();
	~bbc();
	bbc operator+(const bbc& r);

	void print();
	void go();
protected:
	void init_class(bbc* parent);
	size_t m_vtable_offset;
	int m_vtable_size;
	bbc* m_prev_bbc;
private:
	static vector<bbc> m_tree;
};

