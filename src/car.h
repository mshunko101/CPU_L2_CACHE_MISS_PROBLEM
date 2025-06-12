#pragma once
#include "vechline.h"


class car : public vechline
{
public:
	car();
	~car();
	void print() OVERRIDE;
	void go() OVERRIDE;
private:

};

