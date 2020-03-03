#include "Region.h"

GeometeryType Region::getType() const
{
	return region_type;
}

void Region::print()const
{
	std::cout << "ÕâÊÇregionÀà" << std::endl;
}

double CSG::getAria() const
{
	return 0.0;
}

double CSG::getCircle() const
{
	return 0.0;
}

CPoint CSG::getPosition() const
{
	return CPoint(0, 0);
}

void CSG::setPosition(const CPoint& point_obj)
{
	point_obj.print();
}

void CSG::print() const
{
	std::cout << "this is CSG" << std::endl;
}

GeometeryType CSG::getType() const
{
	return csg_type;
}

Retangle::Retangle(double x, double y, double x1, double y1)
{
	m_point_begin = CPoint(x, y);
	m_point_end = CPoint(x1, y1);
}

Retangle::Retangle(const CPoint& point_lh, const CPoint& point_rh)
{
	m_point_begin = point_lh;
	m_point_end = point_rh;
}

double Retangle::getAria() const
{
	double height,wight;
	height = m_point_begin.getX() - m_point_end.getX();
	wight = m_point_begin.getY() - m_point_end.getY();
	return height * wight;
}

double Retangle::getCircle() const
{
	double height, wight;
	height = m_point_begin.getX() - m_point_end.getX();
	wight = m_point_begin.getY() - m_point_end.getY();
	return 2 *(height + wight);
}

CPoint Retangle::getPosition() const
{
	return m_point_begin;
}

void Retangle::setPosition(const CPoint& point_obj)
{
	m_point_end = m_point_end - m_point_begin + point_obj;
	m_point_begin = point_obj;
}

void Retangle::setFrom(double wight, double height)
{
	m_point_end = CPoint(m_point_begin.getX() + wight, m_point_begin.getY() + height);
}

Ellipse::Ellipse(const CPoint& point_obj, double major_axis, double minor_axis)
{
	m_magor_axis = major_axis;
	m_minor_axis = minor_axis;
	m_position = point_obj;
}

Ellipse::Ellipse(double pos_x, double pos_y, double major_axis, double minor_axis)
{
	m_magor_axis = major_axis;
	m_minor_axis = minor_axis;
	m_position = CPoint(pos_x, pos_y);
}

Ellipse::Ellipse(const Ellipse& ellipse_obj)
{
	m_magor_axis = ellipse_obj.getMajorAxis();
	m_minor_axis = ellipse_obj.getMinorAxis();
	m_position = ellipse_obj.getPosition();
}

double Ellipse::getAria() const
{
	return m_magor_axis * m_minor_axis*PI;
}

double Ellipse::getCircle() const
{
	return PI*2*m_minor_axis +4*(m_magor_axis - m_minor_axis);
}

CPoint Ellipse::getPosition() const
{
	return m_position;
}

void Ellipse::setPosition(const CPoint& point_obj)
{
	m_position = point_obj;
}

void Ellipse::setFrom(double major_axis, double minor_axis)
{
	m_magor_axis = major_axis;
	m_minor_axis = minor_axis;
}

double Ellipse::getMajorAxis() const
{
	return m_magor_axis;
}

double Ellipse::getMinorAxis() const
{
	return m_minor_axis;
}
