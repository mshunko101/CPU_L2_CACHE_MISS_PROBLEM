#include "bbs.h"

static int g_Indexer = 0;

bbs::bbs(double value_parent_id_aka_l, double value_id_aka_r)
:m_debug_rang(0), m_child_id_value_aka_r(value_id_aka_r), m_value_parents_id_aka_l(value_parent_id_aka_l)
{

}

bbs::bbs(double value_id_aka_r)
	:m_debug_rang(0), m_child_id_value_aka_r(value_id_aka_r), m_value_parents_id_aka_l(value_id_aka_r - 1)
{

}


bbs::~bbs()
{

}

bbs bbs::operator+(const bbs& r)
{
	r.m_value_parents_id_aka_l = this->m_child_id_value_aka_r;
	this->m_operation = bbs_operation_add;
	r.m_operation = bbs_operation_add;
	return *this;
}

bbs bbs::operator-(const bbs& r)
{
	r.m_value_parents_id_aka_l = this->m_child_id_value_aka_r;
	this->m_operation = bbs_operation_sub;
	r.m_operation = bbs_operation_sub;
	return *this;
}

bbs bbs::operator*(const bbs& r)
{
	r.m_value_parents_id_aka_l = this->m_child_id_value_aka_r;
	this->m_operation = bbs_operation_mul;
	r.m_operation = bbs_operation_mul;
	return *this;
}

bbs bbs::operator/(const bbs& r)
{
	r.m_value_parents_id_aka_l = this->m_child_id_value_aka_r;
	this->m_operation = bbs_operation_div;
	r.m_operation = bbs_operation_div;
	return *this;
}



double bbs::rang()
{
	return m_debug_rang;
}

double bbs::calc(double l, double r, bbs_operation op)
{
	switch (op)
	{
		case bbs_operation_add:
			return l + r;
		case bbs_operation_sub:
			return l - r;
		case bbs_operation_mul:
			return l * r;
		case bbs_operation_div:
			return l / r;
		default:
			return 0.0f;
	}
}


double bbs::value()
{
	return calc(m_value_parents_id_aka_l, m_child_id_value_aka_r, m_operation);
}
 
bool bbs::operator<(const bbs& r)const
{
	if (this->m_value_parents_id_aka_l < r.m_value_parents_id_aka_l)
	{
		r.m_debug_rang += 1;
		return true;
	}
	else if (this->m_value_parents_id_aka_l > r.m_value_parents_id_aka_l)
	{
		this->m_debug_rang = r.m_debug_rang + 1;
		return false;
	}
	else
	{
		int maxs = std::max(this->m_debug_rang, r.m_debug_rang);
		this->m_debug_rang = maxs;
		r.m_debug_rang = maxs;
		if (this->m_operation < r.m_operation)
		{
			return true;
		}
		else if (this->m_operation > r.m_operation)
		{
			return false;
		}
		else
		{
			return this->m_child_id_value_aka_r < r.m_child_id_value_aka_r;
		}
	}
}