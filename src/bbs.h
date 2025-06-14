#pragma once
#include <algorithm>
#include <math.h>
#include <iostream>
 
class bss_classic;
class bbs
{
public: 
	bbs();
	~bbs();

	bbs operator+(const bbs& r);
	bool operator<(const bbs& r) const;
	double rang();
	double value();
	friend std::ostream& operator<<(std::ostream& o, bbs& bss);
	friend bbs& operator>>(bbs& bssl, bbs& bssr);
	friend class bss_classic;
private:
	int m_id;
	int m_value;
	mutable int m_parent_id;
	mutable double m_debug_rang;
};


class bss_classic
{
public:
	bss_classic()
	{
		m_current_root_id = 0;
	}
	bool operator () (const bbs& l, const  bbs& r)
	{// LINK - TRUE
		if(l.m_parent_id == 0)
		{
			l.m_debug_rang = 0;
			r.m_debug_rang = r.m_parent_id;
			return true;
		}

		if(r.m_parent_id == 0)
		{
			r.m_debug_rang = 0;
			l.m_debug_rang = l.m_parent_id;
			return true;
		}


		if (l.m_parent_id == r.m_id)
		{
			r.m_debug_rang = r.m_parent_id;
			l.m_debug_rang = l.m_parent_id;
			return true;
		}
		else
		{
			if (l.m_parent_id <= r.m_id)
			{ 
				r.m_debug_rang = r.m_parent_id;
				l.m_debug_rang = l.m_parent_id;
				return true;
			}
			else if (l.m_parent_id > r.m_id)
			{
				r.m_debug_rang = r.m_parent_id;
				l.m_debug_rang = l.m_parent_id;
				return false;
			}
		}
	}
private:
	int m_max;
	int m_current_root_id;
};

std::ostream& operator<<(std::ostream& o, bbs& _bss);