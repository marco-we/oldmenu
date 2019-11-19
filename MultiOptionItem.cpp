#include "MultiOptionItem.h"
#include "MenuDefinitions.h"

/*
 *  Constructor
 */
MultiOptionItem::MultiOptionItem( const std::string &name )
: MenuItem( name )
{
	m_pLive_variable = 0;
	m_active_item = 0;
}


/*
 *  Destructor
 */
MultiOptionItem::~MultiOptionItem(void)
{
}


/*
 *  process_input()
 */
void MultiOptionItem::process_input( int key )
{
	if( m_options.size() == 0 )
		return;
	if( key == ID_INCREASE )
		m_active_item = ((m_active_item + 1) % m_options.size());
	else if( key == ID_DECREASE )
		m_active_item = ((m_active_item - 1) % m_options.size());
	if( m_pLive_variable )
		*m_pLive_variable = m_options[ m_active_item ];
}


/*
 *  process_input()
 */
void MultiOptionItem::process_input( unsigned char key )
{
	if( m_options.size() == 0 )
		return;
	if( key == ID_ACTION )
		m_active_item = ((m_active_item + 1) % m_options.size());
	if( m_pLive_variable )
		*m_pLive_variable = m_options[ m_active_item ];
}


/*
 *  add_option()  
 */
void MultiOptionItem::add_option( const std::string &opt )
{
	m_options.push_back( opt );
	if( m_pLive_variable )
		*m_pLive_variable = m_options[ m_active_item ];
}


/*
 *  get_value()
 */
std::string MultiOptionItem::get_value( void )
{
	if( m_options.size() > 0 )
		return m_options[ m_active_item ];
	else
		return "";
}


/*
 *  set_live_variable()
 */
void MultiOptionItem::set_live_variable( std::string *live_var )
{
	m_pLive_variable = live_var;
	*m_pLive_variable = get_value();
}


/*
 *  get_name()
 */  
std::string MultiOptionItem::get_name( void )
{
	return m_name + get_value();
}


/*
 *  selectable()
 */
bool MultiOptionItem::selectable( void )
{
	if( m_options.size() > 0 )
		return true;
	else
		return false;
}
