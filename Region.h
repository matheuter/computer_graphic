#ifndef REGION_H_
#define REGION_H_


#include "geometery.h"
#include"Point.h"
#define PI 3.1415926

class Region :public Geometery{
public:
	Region() = default;
	GeometeryType getType() const override;
	void print()const override;
	virtual double getAria() const = 0;
	virtual double getCircle() const = 0;
	virtual CPoint getPosition() const = 0;
	virtual void setPosition(const CPoint& point_obj) = 0;
};


class CSG :public Region {
public: 
	virtual double getAria() const override;
	virtual double getCircle() const override;
	virtual CPoint getPosition() const override;
	virtual void setPosition(const CPoint& point_obj)override;
	virtual void print() const override;
	virtual GeometeryType getType()const override;
};


class Retangle :public CSG {
public:
	Retangle(double x = 0, double y = 0, double x1 = 0, double y1 = 0);
	Retangle(const CPoint& point_lh, const CPoint& point_rh);
	~Retangle(){}
	double getAria() const override;
	double getCircle() const override;
	CPoint getPosition() const override;
	void setPosition(const CPoint& point_obj)override;
	void setFrom(double wight, double height);
private:
	CPoint m_point_begin;
	CPoint m_point_end;
};

class Ellipse :public CSG {
public:
	Ellipse(const CPoint& point_obj, double major_axis, double minor_axis);
	Ellipse(double pos_x, double pos_y, double major_axis, double minor_axis);
	Ellipse(const Ellipse& ellipse_obj);
	~Ellipse(){}
	double getAria() const override;
	double getCircle() const override;
	CPoint getPosition() const override;
	void setPosition(const CPoint& point_obj)override;
	void setFrom(double major_axis, double minor_axis);
	double getMajorAxis()const;
	double getMinorAxis()const;
private:
	double m_magor_axis;
	double m_minor_axis;
	CPoint m_position;
};


#endif // !REGION_H_
