#include "Label.h"

Label::Label(const string& content, const CPoint& position = CPoint(0,0))
{
	m_position = position;
	m_szContent = content;
}

Label::Label()
{
	m_position = CPoint(0, 0);
	m_szContent = "\0";
}

GeometeryType Label::getType() const
{
	return label_type;
}

void Label::print() const
{
	std::cout << m_szContent << std::endl;
	std::cout << "labelµÄÎ»ÖÃÊÇ";
	m_position.print();
	std::cout << std::endl;
}

string Label::getContent() const
{
	return m_szContent;
}

CPoint Label::getPosition() const
{
	return m_position;
}

void Label::setContent(const string& content)
{
	m_szContent = content;
}

void Label::setPosition(CPoint& point_obj)
{
	m_position = point_obj;
}
