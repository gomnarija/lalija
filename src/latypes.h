#ifndef LATYPES_H
#define LATYPES_H

#include	<string>
#include	<vector>
#include	<memory>

struct laVal
{
	laVal(){}
	
	virtual std::string print();

};
typedef	std::shared_ptr<laVal>
		laValPtr;


struct laNumber : laVal
{
	laNumber();
	laNumber(double value) 
		:m_value{value}{}

	laNumber(std::string value);

	double	value() const 
			{return m_value;}
	
	std::string print() 
		override;

private:
	double		m_value;
};

struct laString : laVal
{
	laString(){}
	laString(std::string value) :m_value{value} {}

	std::string	value() const 
				{return m_value;}


	std::string print() 
		override;


private:
	std::string	m_value;
};

struct laList : laVal
{
	
	laList(){}

	laList(std::vector<laValPtr> list);


	void 	insert(laValPtr val);
	size_t 	size()
		{return m_items.size();}
	
	laValPtr at(const int);


	std::string print()
		override;	


private:
	std::vector<laValPtr>	m_items;
};


struct laNil : laVal
{
	laNil(){}

	
	std::string print() 
		override;



};

#endif
