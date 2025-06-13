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
		m_order = 0;
	}
	bool operator () (const bbs& l, const  bbs& r)
	{
		bool result = false;
		
		if(l.m_id < r.m_parent_id)
		{//true I
			result = true;
		}
		else if (l.m_id > r.m_parent_id)
		{//false I
			l.m_debug_rang = r.m_debug_rang + 1;
			result = false;
		}
		else  
		{
			if (l.m_parent_id < r.m_parent_id)
			{
				result = true;
			}
			else if (l.m_parent_id > r.m_parent_id)
			{ 
				result = false;
			}
			else
			{
				result = l.m_id < r.m_id;
			}

		}
		return result;
	 
	}
private:
	int m_max;
	int m_order;
};

std::ostream& operator<<(std::ostream& o, bbs& _bss);