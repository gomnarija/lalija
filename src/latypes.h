#ifndef LATYPES_H
#define LATYPES_H

#include	<string>
#include	<vector>
#include	<memory>
#include	<map>

enum laType
{
	Nil,
	Number,
	String,
	Symbol,
	List,
	Function
};



struct laVal
{
	laVal(){}
	
	virtual std::string print();
	
	const virtual laType get_type(){return laType::Nil;}

	const virtual bool is_true()
		{return false;}

	const virtual bool equals(std::shared_ptr<laVal> other)
		{return false;}
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

	const laType get_type() override {return laType::Number;}
	const  bool is_true() override 
			{return this->m_value==0?false:true;}

	const bool equals (std::shared_ptr<laVal> other)override;

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

	const laType get_type() override {return laType::String;}
	const  bool is_true() override 
			{return this->m_value=="\"\""?false:true;}

	const bool equals (std::shared_ptr<laVal> other)override;


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


	const laType get_type() override {return laType::List;}
	const  bool is_true() override 
			{return this->size()==0?false:true;}

	const bool equals(std::shared_ptr<laVal> other) override;


private:
	std::vector<laValPtr>	m_items;
};

struct laSymbol : laVal
{
	laSymbol(){}
	laSymbol(std::string value) : m_value{value}{}

	std::string print()
		override;

	const laType get_type() override {return laType::Symbol;}

private:
	std::string 	m_value;
};


typedef	std::shared_ptr<laNumber>
		laNumberPtr;
typedef	std::shared_ptr<laString>
		laStringPtr;
typedef	std::shared_ptr<laSymbol>
		laSymbolPtr;
typedef	std::shared_ptr<laList>
		laListPtr;



struct laFunction : laVal
{
	laFunction(){};
	laFunction(std::string name, laListPtr args, laListPtr body)
		: m_name{name}, m_args{args}, m_body{body} {};

	std::string print() override {return this->m_name;}


	const laType get_type() override {return laType::Function;}


	laListPtr	args(){return m_args;}
	laListPtr	body(){return m_body;}

private:
	std::string	m_name;
	laListPtr	m_args;
	laListPtr	m_body;
};

typedef	std::shared_ptr<laFunction>
		laFunctionPtr;


struct laNil : laVal
{

	laNil(){};	
	
	std::string print() 
		override;


	static laValPtr Nil();
	
	
private:
	const laType get_type() override {return laType::Nil;}

	const bool equals (std::shared_ptr<laVal> other) override
		{return true;} 


};



laValPtr laNilVal();



struct laEnv
{

	laEnv() :m_upper_env{nullptr} {}
	laEnv(laEnv* env_ptr) 
		:m_upper_env{env_ptr}{}
	laEnv(laEnv* env_ptr, 
		std::map<std::string,laValPtr> m) 
			: m_map{m},m_upper_env{env_ptr}{};
	

	laValPtr	get_val(std::string key);
	void		set_val(std::string key,
				laValPtr val);
	void		insert_val(std::string key,
				laValPtr val);
	void		fset_val(std::string key,
				 laValPtr val);
		
	laEnv*	get_upper_env()
				{return this->m_upper_env;}
private:
	std::map<std::string,laValPtr>	m_map;
	laEnv*				m_upper_env;
};



#endif
