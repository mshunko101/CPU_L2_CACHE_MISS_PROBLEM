#include "car.h"

car::car()
{
	init_class(this);
}

car::~car()
{

}

void car::print()
{
	cout << "car::print" << endl;
}

void car::go()
{
	cout << "car::go" << endl;
}