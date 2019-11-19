#include "TextFieldItem.h"
#include "MenuDefinitions.h"

#include <string>
using namespace std;

/*
 *  Constructor
 */
TextFieldItem::TextFieldItem( const std::string &name )
:MenuItem( name )
{
	m_text = "";
	m_max_length = 20;
	m_pLive_variable = 0;
}


/*
 *  Destructor
 */
TextFieldItem::~TextFieldItem()
{
}

/*
 *  get_text()
 */
std::string TextFieldItem::get_text( void )
{
	return m_text;
}


/*
 *  set_text()
 */
void TextFieldItem::set_text( const std::string &text )
{
	m_text = text;
	if( m_pLive_variable )
		*m_pLive_variable = text;
}


/*
 *  get_name()
 */
std::string TextFieldItem::get_name( void )
{
	return m_name + m_text;
}


/*
 *  process_input()
 */
void TextFieldItem::process_input( int key )
{
	if( key == ID_DECREASE || key == ID_INCREASE )
		return;
	if( m_text.length() < m_max_length )
		m_text += (char)key;
	set_text( m_text );
}


/*
 *  process_input()
 */
void TextFieldItem::process_input( unsigned char key )
{
	if( key == ID_ACTION )
		return;
	else if( key == ID_BACKSPACE ) {
		if( m_text.length() > 0 ) 
			set_text( m_text.substr( 0, m_text.length()-1 ) );
		return;
	}
	else if( m_text.length() < m_max_length )
		m_text += key;
	set_text( m_text );
}


/*
 *  selectable()
 */
bool TextFieldItem::selectable( void )
{
	return true;
}


/*
 *  set_live_variable()
 */
void TextFieldItem::set_live_variable( std::string *live_var )
{
	m_pLive_variable = live_var;
	*m_pLive_variable = get_text();
}
