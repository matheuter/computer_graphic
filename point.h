#ifndef POINT_H_
#define POINT_H_

#include<iostream>
#include<iomanip>

#include"GraphicAlgorithm.h"
#include"geometery.h"

class CPoint{
private:
	double m_x;
	double m_y;
public:
	CPoint(const CPoint& point_obj);
	CPoint(double x, double y);
	CPoint() = default;
	~CPoint(){}

	double getX()const;
	double getY()const;
	void setX(double x);
	void setY(double y);
	void print() const;

	CPoint& operator=(const CPoint& point_obj);
	CPoint operator+(const CPoint& point_obj);
	CPoint operator-(const CPoint& point_obj);
	bool operator==(const CPoint& point_obj);
	friend CPoint operator-(const CPoint& point_lh, const CPoint& point_rh);
	friend bool operator==(const CPoint& point_lh, const CPoint& point_rh);

	GeometeryType getType() const;
	//void ShowObject()const;
};
#endif