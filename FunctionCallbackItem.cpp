#include "FunctionCallbackItem.h"
#include "MenuDefinitions.h"
#include <iostream>
using namespace std;


/*
 *  Constructor
 */
FunctionCallbackItem::FunctionCallbackItem( const std::string &name )
: MenuItem( name )
{
	m_cb_function = 0;
}


/*
 *  Destructor
 */
FunctionCallbackItem::~FunctionCallbackItem()
{
}


/*
 *  set_callback_function()
 */
void FunctionCallbackItem::set_callback_function( CBFunction fn )
{
	m_cb_function = fn;
}


/*
 *  process_input()
 */
void FunctionCallbackItem::process_input( unsigned char key )
{
	if( key == ID_ACTION )
		if( m_cb_function )
			m_cb_function();
		else
			cerr << "[FunctionCallbackItem]::process_input() cb_function == 0!" << endl;
}


/*
 *  selectable()
 */
bool FunctionCallbackItem::selectable( void )
{
	return true;
}

