#include "Line.h"

void Line::print() const
{
	std::cout << "这是线基类" << std::endl;
}

GeometeryType Line::getType() const
{
	return line_base_type;
}

double Line::getLength() const
{
	return 0;
}


CPoint Line::getPosition()
{
	return CPoint(0,0);
}

void Line::setPosition(const CPoint& point_obj)
{
}

SeqmentLine::SeqmentLine(const CPoint& point_begin, const CPoint& point_end)
{
	m_point_begin = point_begin;
	m_point_end = point_end;
}

SeqmentLine::SeqmentLine(const SeqmentLine& seqment_line_obj)
{
	m_point_begin = seqment_line_obj.getPointBegin();
	m_point_end = seqment_line_obj.getPointEnd();
}

void SeqmentLine::print()const
{
	m_point_begin.print();
	m_point_end.print();
}

void SeqmentLine::setPosition(const CPoint& point_obj)
{
	m_point_end = (m_point_end + (point_obj - m_point_begin));
	m_point_begin = point_obj;
}

double SeqmentLine::getLength() const
{
	double x = m_point_begin.getX();
	double y = m_point_begin.getY();
	double x1 = m_point_end.getX();
	double y1 = m_point_end.getY();
	return sqrt((x - x1)*(x - x1) + ((y - y1)*(y - y1)));
}

CPoint SeqmentLine::getPosition()
{
	return m_point_begin;
}

CPoint SeqmentLine::getPointBegin() const
{
	return m_point_begin;
}

CPoint SeqmentLine::getPointEnd() const
{
	return m_point_end;
}

GeometeryType SeqmentLine::getType() const
{
	return seqment_line_type;
}

PolyLine::PolyLine(const CPoint& point_obj, ...)
{

}

PolyLine::PolyLine(const PolyLine& polyline_obj)
{
	int point_count = polyline_obj.getPointCount();
	for (int i = 0; i < point_count; ++i) {
		this->m_points.push_back(polyline_obj.getPoint(i));
	}
}

PolyLine PolyLine::operator=(const PolyLine& polyline_obj)
{
	int point_count = polyline_obj.getPointCount();
	for (int i = 0; i < point_count; ++i) {
		this->m_points.push_back(polyline_obj.getPoint(i));
	}
	return *this;
}

void PolyLine::print()const
{
	for (auto iter = m_points.begin(); iter < m_points.end(); ++iter) {
		iter->print();
	}
}

void PolyLine::setPosition(const CPoint& point_obj)
{
	for (auto iter = m_points.begin() + 1; iter < m_points.end(); ++iter) {
		*iter =*iter - m_points[0] + point_obj;
	}
	m_points[0] = point_obj;
}

void PolyLine::addPoint(const CPoint& point_obj, int pos)
{
	auto iter = m_points.begin();
	while (pos--) {
		iter++;
	}
	m_points.insert(iter, point_obj);
}

double PolyLine::getLength() const
{
	double x, y, x1, y1;
	double sqrt_value_sum = 0.0;
	for (auto iter = m_points.begin(); iter < m_points.end(); ++iter) {
		auto pTemp = iter + 1;
		double x = iter->getX();
		double y = iter->getY();
		double x1 = pTemp->getX();
		double y1 = pTemp->getY();
		sqrt_value_sum += sqrt((x - x1) * (x - x1) + ((y - y1) * (y - y1)));
	}
	return sqrt_value_sum;
}

CPoint PolyLine::getPosition()
{
	return m_points[0];
}

CPoint PolyLine::getPoint(int pos) const
{
	return m_points[pos - 1];
}

int PolyLine::getPointCount() const
{
	return m_points.size();
}

GeometeryType PolyLine::getType() const
{
	return point_type;
}
