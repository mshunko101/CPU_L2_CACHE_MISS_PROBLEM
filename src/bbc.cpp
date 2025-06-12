#include "bbc.h"
#include "car.h"

static int g_Indexer = 0;
vector<bbc> bbc::m_tree;

bbc::bbc()
: m_vtable_offset(0), m_vtable_size(0)
{
	m_vtable_offset = m_tree.size();
	m_vtable_size = m_vtable_offset;
	m_prev_bbc = this;
	m_tree.push_back(*m_prev_bbc);
}

bbc::~bbc()
{

}

bbc bbc::operator+(const bbc& r)
{ 
	return *this;
}

void bbc::print()
{
	auto v = m_vtable_size - m_vtable_offset;
	switch (v)
	{
	case 0:
		cout << "ITS AWFUL YOU CALLED METHOD WHICH PURE VIRTUAL";
		break;
	case 1:
		reinterpret_cast<vechline&>(m_tree[m_vtable_offset]).print();
		break;
	case 2:
		reinterpret_cast<car&>(m_tree[m_vtable_offset + 1]).print();
		break;
	case 3:
		m_tree[m_vtable_offset + 4].print();
		break;
	}
}

void bbc::go()
{
	m_tree[m_vtable_offset + m_vtable_size].go();
}

void bbc::init_class(bbc* parent)
{
	(*m_prev_bbc) = (*m_prev_bbc) + (*parent);
	m_vtable_size++;
	m_tree.push_back(*parent);
}