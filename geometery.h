#ifndef GEOMETERY_H_
#define GEOMETERY_H_

enum GeometeryType {
	geometery_type = 0,
	point_type,
	line_base_type,
	label_type,
	seqment_line_type,
	region_type,
	csg_type,
	trangle_type,
	retrangle_type,
	ellipse_type
};

class Geometery {
public:
	virtual GeometeryType getType()const;
	//virtual void ShowObject()const;
	virtual void print() const;
};

#endif //GEOMETERY_H_