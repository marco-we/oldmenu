#include "IntegerFieldItem.h"
#include "MenuDefinitions.h"
#include <string>
#include <sstream>
#include <limits>
#include <iostream>
using namespace std;

/*
 *  Constructor
 */
IntegerFieldItem::IntegerFieldItem( const std::string &name )
: MenuItem( name )
{
	m_value = 0;
	m_live_variable = 0;
	m_min = numeric_limits<int>::min();
	m_max = numeric_limits<int>::max();
}


/*
 *  Destructor
 */
IntegerFieldItem::~IntegerFieldItem()
{
}


/*
 *  process_input()
 */
void IntegerFieldItem::process_input( int key )
{
	int new_val;
	
	// we have to shift to get the actual number
	if( key >= 48 && key  <= 57 ) {
		new_val = m_value * 10 + (key - 48);
	}
	else if( key == ID_DECREASE ) 
		new_val = m_value - 1;
	else if( key == ID_INCREASE ) 
		new_val = m_value + 1;
	else if( key == ID_BACKSPACE ) 
		new_val = m_value / 10;
	else return;
	
	set_value( new_val );
}


/*
 *  process_input()
 */
void IntegerFieldItem::process_input( unsigned char key )
{
	if( (key >= '0' && key <= '9') || key == ID_BACKSPACE )
		process_input( (int)key );
}


/*
 *  get_value()
 */
int IntegerFieldItem::get_value( void )
{
	return m_value;
}


/*
 *  set_value()
 */
void IntegerFieldItem::set_value( int value )
{
	if( value < m_min || value > m_max )
		return;
	if( m_live_variable )
		*m_live_variable = value;
	m_value = value;
}

/*
 *  get_name()
 */
std::string IntegerFieldItem::get_name( void )
{
	stringstream num;
	num << m_value;
	return m_name + num.str();
}


/*
 *  set_min_value()
 */
void IntegerFieldItem::set_min_value( int min )
{
	if( m_value < min )
		m_value = min;
	m_min = min;
}


/*
 *  set_max_value()
 */
void IntegerFieldItem::set_max_value( int max )
{
	if( m_value > max )
		m_value = max;
	m_max = max;
}


/*
 *  set_live_variable()
 */
void IntegerFieldItem::set_live_variable( int *live_var )
{
	m_live_variable = live_var;
	*live_var = m_value;
}


/*
 *  selectable()
 */
bool IntegerFieldItem::selectable( void )
{
	return true;
}

