 #ifndef LABEL_H_
#define LABEL_H_

#include<string>
#include"geometery.h"
#include"Point.h"

using std::string;

class Label : public Geometery {
public:
	Label(const string& content, const CPoint& position);
	Label();
	~Label(){}

	void print()const override;
	GeometeryType getType() const override;
	
	string getContent() const;
	CPoint getPosition() const;
	void setContent(const string& content);
	void setPosition(CPoint& point_obj);
private:
	string m_szContent;
	CPoint m_position;
};

#endif // LABEL_H_