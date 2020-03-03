#include "geometery.h"
#include<iostream>

GeometeryType Geometery::getType() const
{
	return geometery_type;
}

void Geometery::print() const
{
	std::cout << "这是基类" << std::endl;
}
