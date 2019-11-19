#include "BooleanOptionItem.h"
#include "MenuDefinitions.h"

/*
 *  Constructor
 */
BooleanOptionItem::BooleanOptionItem( const std::string &name )
: MenuItem( name )
{
	m_value = false;
	m_pLive_variable = 0;
}


/*
 *  Destructor
 */
BooleanOptionItem::~BooleanOptionItem(void)
{
}


/*
 *  process_input()
 */
void BooleanOptionItem::process_input( int key )
{
	if( key == ID_INCREASE || key == ID_DECREASE ) 
		set_value( !m_value );
}


/*
 *  process_input()
 */
void BooleanOptionItem::process_input( unsigned char key )
{
	if( key == ID_ACTION ) 
		set_value( !m_value );
}


/*
 *  get_value()
 */
bool BooleanOptionItem::get_value( void )
{
	return m_value;
}


/*
 *  set_value()
 */
void BooleanOptionItem::set_value( bool val )
{
	if( m_pLive_variable )
		*m_pLive_variable = val;
	m_value = val;
}


/*
 *  set_live_variable()
 */
void BooleanOptionItem::set_live_variable( bool *live_var )
{
	m_pLive_variable = live_var;
}


/*
 *  get_name()
 */
std::string BooleanOptionItem::get_name( void )
{
	if( m_value )
		return m_name + "On";
	else
		return m_name + "Off";
}


/*
 *  selectable()
 */
bool BooleanOptionItem::selectable( void )
{
	return true;
}
