#include "Point.h"


CPoint::CPoint(const CPoint& point_obj)
{
	m_x = point_obj.getX();
	m_y = point_obj.getY();
}

CPoint::CPoint(double x, double y)
{
	m_x = x;
	m_y = y;
}

double CPoint::getX() const
{
	return m_x;
}

double CPoint::getY() const
{
	return m_y;
}

void CPoint::setX(double x)
{
	this->m_x = x;
}

void CPoint::setY(double y)
{
	this->m_y = y;
}

void CPoint::print() const
{
	std::cout<< "(" << m_x << " , " << m_y << ")";
}

CPoint& CPoint::operator=(const CPoint& point_obj)
{
	this->m_x = point_obj.getX();
	this->m_y = point_obj.getY();
	return *this;
}

CPoint CPoint::operator+(const CPoint& point_obj)
{
	double x = this->m_x + point_obj.getX();
	double y = this->m_y + point_obj.getY();
	return CPoint(x, y);
}

CPoint CPoint::operator-(const CPoint& point_obj)
{
	double x = this->m_x - point_obj.getX();
	double y = this->m_y - point_obj.getY();
	return CPoint(x ,y);
}

bool CPoint::operator==(const CPoint& point_obj)
{
	return ((this->getX() == point_obj.getX())
		&& (this->getY() == point_obj.getY()))
		? true : false;
}

GeometeryType CPoint::getType() const
{
	return point_type;
}


CPoint operator-(const CPoint& point_lh, const CPoint& point_rh)
{
	double x = point_lh.getX() - point_rh.getX();
	double y = point_lh.getY() - point_rh.getY();
	return CPoint(x, y);
}

bool operator==(const CPoint& point_lh, const CPoint& point_rh)
{
	return ((point_lh.getX() == point_rh.getX()) 
		&&(point_lh.getY() == point_rh.getY()))
		? true : false;
}
