#pragma once
#include <algorithm>
#include <math.h>
#include <iostream>

 
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
private:

	int m_id;
	int m_value;
	mutable int m_parent_id;
	mutable double m_debug_rang;
};


std::ostream& operator<<(std::ostream& o, bbs& _bss);