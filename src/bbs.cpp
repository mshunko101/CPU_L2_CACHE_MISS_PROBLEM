#include "bbs.h"


std::ostream& operator<<(std::ostream& o, bbs& _bss)
{
	for (int j = 0; j < _bss.m_debug_rang; j++)
	{
		o << " ";
	}
	o << _bss.m_debug_rang;
	return o;
}

static int g_Indexer;

bbs::bbs()
:m_debug_rang(0), m_id(++g_Indexer), m_parent_id(0)
{
	m_value = m_id;
}

bbs::~bbs()
{

}

bbs bbs::operator+(const bbs& r)
{
	r.m_parent_id = this->m_id;
	return *this;
}

double bbs::rang()
{
	return m_debug_rang;
}
 
bool bbs::operator<(const bbs& r)const
{
	if (this->m_parent_id < r.m_parent_id)
	{
		r.m_debug_rang += 1;
		return true;
	}
	else if (this->m_parent_id > r.m_parent_id)
	{
		this->m_debug_rang = r.m_debug_rang + 1;
		return false;
	}
	else
	{
		int maxs = std::max(this->m_debug_rang, r.m_debug_rang);
		this->m_debug_rang = maxs;
		r.m_debug_rang = maxs;
		return this->m_id < r.m_id;
	}
}