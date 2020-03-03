#ifndef LINE_H_
#define LINE_H_

//[line基类]:		继承自Geometry类
//[SeqmentLine类]:	继承自line类
//[PolyLine类]:		继承自line类

#include"Point.h"
#include "geometery.h"
#include<vector> 
using std::vector;

//![line基类]:		继承自Geometry类
class Line : public Geometery{
public:
	Line() = default;
	virtual double getLength() const;
	virtual CPoint getPosition();
	virtual void setPosition(const CPoint& point_obj);

	virtual void print()const override;
	virtual GeometeryType getType() const override;
};

//![SeqmentLine类]:继承自line类
class SeqmentLine : public Line{
public:
	SeqmentLine(const CPoint& point_begin, const CPoint& point_end);
	SeqmentLine(const SeqmentLine& seqment_line_obj);
	~SeqmentLine(){}

	void print()const override;
	void setPosition(const CPoint& point_obj)override;
	double getLength()const override;
	CPoint getPosition()override;
	CPoint getPointBegin() const;
	CPoint getPointEnd() const;
	GeometeryType getType()const override;
private:
	CPoint m_point_begin;
	CPoint m_point_end;
};

//![PolyLine类]: 继承自line类
class PolyLine :public Line {
public:
	PolyLine(const CPoint& point_obj, ...);
	PolyLine(const PolyLine& polyline_obj);
	~PolyLine(){}
	PolyLine operator=(const PolyLine& polyline_obj);
	void print() const override;
	void setPosition(const CPoint& point_obj)override;
	void addPoint(const CPoint& point_obj, int pos);
	void delPoint(int pos);
	double getLength() const override;
	CPoint getPosition() override;
	CPoint getPoint(int pos)const;
	int getPointCount()const;
	GeometeryType getType()const override;
private:
	vector<CPoint> m_points;
};
#endif //LINE_H_
