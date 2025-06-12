#pragma once
#include <algorithm>
#include <math.h>
#include <iostream>


 enum bbs_operation { bbs_operation_undefined, bbs_operation_div, bbs_operation_sub, bbs_operation_add, bbs_operation_mul};

class bbs
{
public: 
	bbs(double value_id_aka_r);
	bbs(double value_parent_id_aka_l, double value_id_aka_r);
	~bbs();

	bbs operator+(const bbs& r);
	bbs operator-(const bbs& r);
	bbs operator*(const bbs& r);
	bbs operator/(const bbs& r);
	bool operator<(const bbs& r) const;
	double rang();
	double value();
	friend std::ostream& operator<<(std::ostream& o, bbs& bss);
	friend bbs& operator>>(bbs& bssl, bbs& bssr);
private:
	double calc(double l, double r, bbs_operation op);
	mutable bbs_operation m_operation;
	double m_child_id_value_aka_r;
	mutable double m_value_parents_id_aka_l;
	mutable double m_debug_rang;
};

static  std::ostream& operator<<(std::ostream& o, bbs& _bss)
{
	for (int j = 0; j < _bss.m_debug_rang; j++)
	{
		o << " ";
	}
	//o << _bss.m_debug_rang;
	return o;
}

